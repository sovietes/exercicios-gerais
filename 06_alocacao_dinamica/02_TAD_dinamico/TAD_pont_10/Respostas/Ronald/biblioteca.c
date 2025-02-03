#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./biblioteca.h"

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca() {
    tBiblioteca *biblioteca = NULL;
    biblioteca = (tBiblioteca *) malloc(sizeof(tBiblioteca));
    if(!biblioteca) {
        printf("erro ao alocar biblioteca!!!\n");
        exit(0);
    }

    int i;
    for(i = 0; i < MAX_LIVROS; i++) {
        biblioteca->livros[i] = NULL;
    }
    
    biblioteca->tamanho = 0;

    return biblioteca;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca) {
    if(biblioteca) {
        int i;
        for(i = 0; i < MAX_LIVROS; i++) {
            if(biblioteca->livros[i]) {
                ApagaLivro(biblioteca->livros[i]);
            }
        }
        free(biblioteca);
    }
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro) {
    int i;
    if((biblioteca->tamanho) < (MAX_LIVROS)) {
        for(i = 0; i < MAX_LIVROS; i++) {
            // Salva no espaco vazio
            if(!biblioteca->livros[i]) {
                biblioteca->livros[i] = livro;
                biblioteca->tamanho++;
                printf("Livro adicionado com sucesso!\n");
                return;
            }
        }
    } else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        ApagaLivro(livro);
    }
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo) {
    int i;
    for(i = 0; i < MAX_LIVROS; i++) {
        // Se for null, analisa o proximo livro
        if(!biblioteca->livros[i]) continue;

        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)) {
            ApagaLivro(biblioteca->livros[i]);
            biblioteca->livros[i] = NULL;
            biblioteca->tamanho--;
            printf("Livro removido com sucesso!\n");
            return;
        }
    }
    printf("Livro nao encontrado na biblioteca.\n");
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo) {
    return strcmp(livro->titulo, titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca) {
    int i;
    if(biblioteca->tamanho > 0) {
        printf("\nLista de Livros na Biblioteca:\n");
        for(i = 0; i < MAX_LIVROS; i++) {
            if(biblioteca->livros[i]) {
                ImprimeLivro(biblioteca->livros[i]);
            }
        }
    } else {
        printf("A biblioteca esta vazia!\n");
    }
}