#include "filme.h"
#include <string.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

tFilme leFilme(int codigo) {
    tFilme filme;
    char nome[20];
    int valor, quantidade;

    scanf("%*[^a-zA-Z]");
    scanf("%[^,],%d,%d", nome, &valor, &quantidade);
    scanf("%*[^\n]");
    scanf("%*c");

    filme = criarFilme(nome, codigo, valor, quantidade);
    return filme;
}

int obterCodigoFilme (tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo) {
    if(obterCodigoFilme(filme) == codigo) {
        return 1;
    } else {
        return 0;
    }
}

tFilme alugarFilme (tFilme filme) {
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme) {
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2) {
    return strcmp(filme1.nome, filme2.nome);
}
