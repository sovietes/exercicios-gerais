#include <stdio.h>
#include <stdlib.h>
#include "./locadora.h"
#define NUM_MAX_FILMES 100

struct Locadora {
    tFilme** filme; 
    int numFilmes; 
    int lucro; 
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora () {
    tLocadora *l;
    l = (tLocadora *) malloc(sizeof(tLocadora));
    l->filme = NULL;
    l->numFilmes = 0;
    l->lucro = 0;
    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora) {
    if(locadora) {
        if(locadora->filme) {
            int i;
            for(i = 0; i < locadora->numFilmes; i++) {
                free(locadora->filme[i]);
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
    int i;
    for(i = 0; i < locadora->numFilmes; i++) {
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme) {
    // Reservando espaco para os filmes caso ainda n tenha
    if(!locadora->filme) {
        locadora->filme = (tFilme **) malloc(NUM_MAX_FILMES*sizeof(tFilme *));
    }
    // Cadastrando
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
        locadora->filme[locadora->numFilmes] = filme;
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filme[locadora->numFilmes]));
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes]);
        printf("\n");

        locadora->numFilmes++;
    } else {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora) {
    int codigo;
    while(scanf("%d", &codigo) == 1) {
        tFilme *filme = CriarFilme();
        scanf("%*[^a-zA-Z]");
        LeFilme(filme, codigo);
        CadastrarFilmeLocadora(Locadora, filme);
    }

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
    for(i = 0; i < quantidadeCodigos; i++) {
        if(VerificarFilmeCadastrado(locadora, codigos[i])) {
            for(j = 0; j < locadora->numFilmes; j++) {
                if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    if(ObterQtdEstoqueFilme(locadora->filme[j]) > 0) {
                        AlugarFilme(locadora->filme[j]);
                        qtdAlugados++;
                        valorTotal += ObterValorFilme(locadora->filme[j]);
                        break;
                    } else {
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
            if(VerificarFilmeCadastrado(locadora, codigos[i])) {
                if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    if(ObterQtdAlugadaFilme(locadora->filme[j]) > 0) {
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
            } else {
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
        for(j = i+1; j < locadora->numFilmes; j++) {
            if(CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) > 0) {
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