#include <stdio.h>
#include <stdlib.h>
#include "./estabelecimento.h"
#include "./vector.h"

struct Estabelecimento {
    Vector *produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento() {
    tEstabelecimento *est = (tEstabelecimento *) malloc(sizeof(tEstabelecimento));
    est->produtos = VectorConstruct();
    return est;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento) {
    if(estabelecimento) {
        if(estabelecimento->produtos) {
            VectorDestroy(estabelecimento->produtos, DestroiProduto);
        }
        free(estabelecimento);
    }
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto) {
    VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento) {
    int qtdProdutos, i; char enderecoArquivo[100];
    scanf("%[^\n]\n", enderecoArquivo);
    FILE *fp = fopen(enderecoArquivo, "rb");
    tProduto *p;
    fread(&qtdProdutos, sizeof(int), 1, fp);

    for(i = 0; i < qtdProdutos; i++) {
        p = LeProduto(fp);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(fp);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento) {
    int i, flagTemProduto = 0; 
    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");
    for(i = 0; i < VectorSize(estabelecimento->produtos); i++) {
        if(!TemEstoqueProduto(VectorGet(estabelecimento->produtos, i))) {
            ImprimeProduto(VectorGet(estabelecimento->produtos, i));
            flagTemProduto = 1;
        }
    }
    if(!flagTemProduto) {
        printf("Nao ha produtos em falta!\n");
    }
}