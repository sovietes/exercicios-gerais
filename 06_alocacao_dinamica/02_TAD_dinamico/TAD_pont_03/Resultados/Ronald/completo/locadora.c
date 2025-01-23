#include <stdio.h>
#include <stdlib.h>
#include "./locadora.h"
#define QTD_MAX_FILMES 100

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora () {
    tLocadora *locadora;
    locadora = (tLocadora *) malloc(sizeof(tLocadora));
    locadora->filme = NULL;
    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora) {
    int i;
    if(locadora) {
        if(locadora->filme) {
            for(i = 0; i < locadora->numFilmes; i++) {
                if(locadora->filme[i]) {
                    DestruirFilme(locadora->filme[i]);
                }
            }
            free(locadora->filme);
        }
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo) {
    int i, qtdFilmesLidos;
    for(i = 0, qtdFilmesLidos = 0; qtdFilmesLidos < locadora->numFilmes; i++) {
        if(locadora->filme[i]) {
            qtdFilmesLidos++;

            if(EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
                return 1;
            }

        }
    }
    // So chegara aqui se n encontrar o filme
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme) {

    // Criando espaço para os filmes, caso necessario
    if(!locadora->filme) {
        int i;
        locadora->filme = (tFilme **) malloc(QTD_MAX_FILMES*sizeof(tFilme *));
        // Inicializando as posicoes
        for(i = 0; i < QTD_MAX_FILMES; i++) {
            locadora->filme[i] = NULL;
        }
    }

    // Verifica se o filme nao esta cadastrado
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
        // Procura espaco vazio e aloca espaco para o filme
        int i;
        for(i = 0; i < QTD_MAX_FILMES; i++) {
            if(!locadora->filme[i]) {
                locadora->filme[i] = CriarFilme();
                // Armazena o filme, como nao ha ponteiro dentro, o valor é copiado interiamente (a struct como um bloco)
                *locadora->filme[i] = *filme;
                // Contabiliza mais um filme cadastrado
                locadora->numFilmes++;

                printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filme[i]));
                ImprimirNomeFilme(locadora->filme[i]);
                printf("\n");
                return;
            }
        }
    } else {
        printf("Filme ja cadastrado no estoque\n");
        return;
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora) {
    tFilme *ptrFilme = CriarFilme();
    int codigo;

    while(scanf("%d", &codigo) == 1) {
        if(Locadora->numFilmes < QTD_MAX_FILMES) {
            scanf("%d", &codigo);
            // Limpando buffer e lendo filme
            scanf("%*[^A-Za-z]");
            LeFilme(ptrFilme, codigo);
            // Como nao ha ponteiros dentro, caso haja cadastro, o valor será copiado inteiramente
            CadastrarFilmeLocadora(Locadora, ptrFilme);
        }

    }

    DestruirFilme(ptrFilme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    int i, j;
    int qtdAlugados = 0, valorTotal = 0; 
    // Varre a lista de codigos
    for(i = 0; i < quantidadeCodigos; i++) {

        // Verifica se o filme com o codigo existe
        if(VerificarFilmeCadastrado(locadora, codigos[i])) {
            // Varre os filmes cadastrados
            for(j = 0; j < locadora->numFilmes; j++) {
                // Encontra o filme com o mesmo codigo
                if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    // Se tiver estoque, aluga
                    if(ObterQtdEstoqueFilme(locadora->filme[j])) {
                        AlugarFilme(locadora->filme[j]);
                        // Dados para saída final
                        qtdAlugados++;
                        valorTotal += ObterValorFilme(locadora->filme[j]);
                        break;
                    } else { // Caso nao tenha no estoque
                        printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                        ImprimirNomeFilme(locadora->filme[j]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                        break;
                    }
                }
            }
        } else { // Caso nao exista o codigo do filme
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }

    }
    if(qtdAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, valorTotal);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora) {
    int *codigos = NULL, qtdCodigos = 0, codigoUnico;

    // Lendo os codigos da entrada
    while(scanf("%d", &codigoUnico) == 1) {
        // Encontra espaco para alocar o novo codigo
        codigos = (int *) realloc(codigos, (qtdCodigos+1)*sizeof(int));

        // Aloca o codigo na nova posicao
        codigos[qtdCodigos] = codigoUnico;

        // Adiciona quantidade de codigos total
        qtdCodigos++;
    }

    AlugarFilmesLocadora(locadora, codigos, qtdCodigos);

    // Liberando espaco dinamico criado
    free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    int i, j;

    for(i = 0; i < quantidadeCodigos; i++) {
        for(j = 0; j < locadora->numFilmes; j++) {
            if(VerificarFilmeCadastrado(locadora, codigos[i])) {// Se o filme esta cadastrado
                if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    if(ObterQtdAlugadaFilme(locadora->filme[j])) { // Se tiver algum alugado, devolver
                        // Devolve o filme
                        DevolverFilme(locadora->filme[j]);
                        // Imprime nome do filme
                        printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                        ImprimirNomeFilme(locadora->filme[j]);
                        printf(" Devolvido!\n");
                        // Atualiza no lucro
                        locadora->lucro += ObterValorFilme(locadora->filme[j]);
                        break;
                    } else {
                        printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filme[j]);
                        printf(".\n");
                        break;
                    }
                }
            } else { // Se n estiver cadastrado
                printf("Filme %d nao cadastrado.\n", codigos[i]);
                break;
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora) {
    int *codigos = NULL, qtdCodigos = 0, codigoUnico;

    // Lendo os codigos da entrada
    while(scanf("%d", &codigoUnico) == 1) {
        // Encontra espaco para alocar o novo codigo
        codigos = (int *) realloc(codigos, (qtdCodigos+1)*sizeof(int));

        // Aloca o codigo na nova posicao
        codigos[qtdCodigos] = codigoUnico;

        // Adiciona quantidade de codigos total
        qtdCodigos++;
    }

    DevolverFilmesLocadora(locadora, codigos, qtdCodigos);

    // Liberando espaco dinamico criado
    free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora) {
    int i, j; tFilme *ptrFilme;
    for(i = 0; i < locadora->numFilmes; i++) {
        if(!locadora->filme[i]) continue;  // Verifica se o filme n eh null

            for(j = i+1; j < locadora->numFilmes; j++) {
                if(!locadora->filme[j]) continue; // Verifica se o filme n eh null

                    if(CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) == 1) {
                        ptrFilme = locadora->filme[i];
                        locadora->filme[i] = locadora->filme[j];
                        locadora->filme[j] = ptrFilme;
                    }
            }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora) {
    int i;
    printf("~ESTOQUE~\n");

    for(i = 0; i < locadora->numFilmes; i++) {
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }

}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora) {
    if(locadora->lucro > 0) {
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}