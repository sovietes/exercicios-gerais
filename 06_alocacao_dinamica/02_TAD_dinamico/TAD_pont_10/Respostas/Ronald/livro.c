#include <stdio.h>
#include <string.h>
#include "./livro.h"

#define TAM_MAX_STR 40

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro() {
    tLivros *livro;
    livro = (tLivros *) malloc(sizeof(tLivros));

    livro->autor = NULL;
    livro->titulo = NULL;
    livro->anoPublicacao = -1;

    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro) {
    livro->autor = (char *) malloc(TAM_MAX_STR*sizeof(char));
    livro->titulo = (char *) malloc(TAM_MAX_STR*sizeof(char));
    // Limpando buffer ate o autor
    scanf("%*[^a-zA-Z]");

    fgets(livro->titulo, TAM_MAX_STR, stdin);
    fgets(livro->autor, TAM_MAX_STR, stdin);

    // Substituindo o \n por \0 string
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';
    livro->autor[strcspn(livro->autor, "\n")] = '\0';

    // Lendo o ano
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
        if(livro->autor) free(livro->autor);
        if(livro->titulo) free(livro->titulo);
        free(livro);
    }
}