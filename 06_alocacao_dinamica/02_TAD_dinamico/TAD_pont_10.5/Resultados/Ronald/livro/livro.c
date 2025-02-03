#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./livro.h"
#define TAM_PADRAO_STR 5

char* LeString(char *string);
char *AumentaTamanhoVetor(char *vetor, int *tamanho);

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro() {
    tLivros *livro = NULL;
    livro = (tLivros *) malloc(sizeof(tLivros));
    if(!livro) {
        printf("erro ao alocar livro!!!\n");
        exit(0);
    }

    livro->titulo = NULL;
    livro->autor = NULL;
    livro->anoPublicacao = -1;

    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro) {
    // Limpando buffer
    scanf("%*[^a-zA-Z]");

    livro->titulo = LeString(livro->titulo);
    livro->autor = LeString(livro->autor);
    scanf("%d\n", &livro->anoPublicacao);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n\n", livro->anoPublicacao);
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro) {
    if(livro) {
        if(livro->titulo) free(livro->titulo);
        if(livro->autor) free(livro->autor);
        free(livro);
    }
}

char* LeString(char *string) {
    int tamanho = TAM_PADRAO_STR;
    string = (char *) malloc(TAM_PADRAO_STR*sizeof(char));

    int comprimentoStr = 0;

    // Preciso tirar o comprimento do tamanho para que nao substitua nada string atual
    while(fgets(string+comprimentoStr, tamanho - comprimentoStr, stdin)) {
        comprimentoStr = strlen(string);

        if(string[comprimentoStr-1] == '\n') {
            string[comprimentoStr-1] = '\0';
            break;
        }

        string = AumentaTamanhoVetor(string, &tamanho);

    }

    return string;
}

char *AumentaTamanhoVetor(char *vetor, int *tamanho) {
    (*tamanho) += TAM_PADRAO_STR;
    vetor = (char *) realloc(vetor, (*tamanho)*sizeof(char));
    return vetor;
}