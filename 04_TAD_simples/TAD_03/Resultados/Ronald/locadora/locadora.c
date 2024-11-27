#include "locadora.h"
#include <stdio.h>

tLocadora criarLocadora () {
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    int i;
    for(i = 0; i < locadora.numFilmes; i++) {
        if(ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme) {
    if(!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))) {
        // Salvando o filme na ultima posicao
        locadora.filme[locadora.numFilmes] = filme;
        // Atualizando o numero de filmes da locadora
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
    } else {
        printf("Filme ja cadastrado no estoque");
    }
    printf("\n");
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    tFilme filme;
    int codigo;

    while(scanf("%d", &codigo) == 1) {
        scanf("%*[^a-zA-Z]");
        filme = leFilme(codigo);    
        locadora = cadastrarFilmeLocadora(locadora, filme);        
    }

    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    int qtdFilmesALugados = 0;
    int lucro = 0;
    int i, j, filmeEncontrado;
    // Varre o array de codigos
    for(i = 0; i < quantidadeCodigos; i++) {
        // Varre o array, procurando o codigo do filme que vai ser alugado
        for(j = 0, filmeEncontrado = 0; j < locadora.numFilmes; j++) {
            // Encontrou o codigo do filme
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                filmeEncontrado = 1;
                // Se tiver estoque, pode alugar
                if(obterQtdEstoqueFilme(locadora.filme[j]) > 0) {
                    // Aluga o filme e adiciona a qtd alugada e o lucro
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    qtdFilmesALugados++;
                    lucro += obterValorFilme(locadora.filme[j]);
                } else {
                    // Qnd nao tem no estoque
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }
        }
        // Se após varrer o array, nao encontrar, imprime:
        if(!filmeEncontrado) printf("Filme %d nao cadastrado.\n", codigos[i]);
    }

    if(qtdFilmesALugados) printf("Total de filmes alugados: %d com custo de R$%d\n", qtdFilmesALugados, lucro);

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora) {
    int qtdCodigos = 0;
    int codigos[100];

    scanf("%*[^0-9]");
    while(scanf("%d", &codigos[qtdCodigos]) == 1) {
        qtdCodigos++;
    }
    locadora = alugarFilmesLocadora(locadora, codigos, qtdCodigos);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    int i, j;
    int filmeEncontrado;
    // Varre o array de codigos
    for(i = 0; i < quantidadeCodigos; i++) {
        //Varre o array de filmes
        for(j = 0, filmeEncontrado = 0; j < locadora.numFilmes; j++) {
            // Encontrou o filme
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                filmeEncontrado = 1;
                // Se estiver algum alugado, pode devolver
                if(obterQtdAlugadaFilme(locadora.filme[j]) > 0) {
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!");
                    // Ja que o livro foi devolvido, somar ao lucro
                    locadora.lucro += obterValorFilme(locadora.filme[j]);
                } else {
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".");
                }

            }
        }

        // Se após varrer o array, nao encontrar, imprime:
        if(!filmeEncontrado) printf("Filme %d nao cadastrado.", codigos[i]);
        printf("\n");
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    int qtdCodigos = 0;
    int codigos[100];

    scanf("%*[^0-9]");
    while(scanf("%d", &codigos[qtdCodigos]) == 1) {
        qtdCodigos++;
    }
    locadora = devolverFilmesLocadora(locadora, codigos, qtdCodigos);
    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora) {
    tFilme aux;
    int i, j;
    for(i = 0; i < locadora.numFilmes; i++) {
        for(j = i+1; j < locadora.numFilmes; j++) {
            if(compararNomesFilmes(locadora.filme[i], locadora.filme[j]) > 0) {
                aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }
    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora) {
    int i;
    printf("~ESTOQUE~\n");
    locadora = ordenarFilmesLocadora(locadora);
    for(i = 0; i < locadora.numFilmes; i++) {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

void consultarLucroLocadora (tLocadora locadora) {
    if(locadora.lucro > 0) {
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}

