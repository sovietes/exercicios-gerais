#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./biblioteca.h"

tBiblioteca* AumentaCapacidadeBiblioteca(tBiblioteca *biblioteca);

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
    biblioteca->livros = NULL;
    biblioteca->tam_max_atual = 0;
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
        if(biblioteca->livros) {
            int i;
            for(i = 0; i < biblioteca->tam_max_atual; i++) {
                if(biblioteca->livros[i]) {
                    ApagaLivro(biblioteca->livros[i]);
                }
            }
            free(biblioteca->livros);
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
    if(biblioteca->tamanho == biblioteca->tam_max_atual) {
        biblioteca = AumentaCapacidadeBiblioteca(biblioteca);
    }

    for(i = 0; i < biblioteca->tam_max_atual; i++) {
        // Salva se estiver vazio
        if(!biblioteca->livros[i]) {
            biblioteca->livros[i] = livro;
            biblioteca->tamanho++;
            printf("Livro adicionado com sucesso!\n");
            return;
        }
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
    for(i = 0; i < biblioteca->tam_max_atual; i++) {
        // Se for null, passa pro proximo
        if(!biblioteca->livros[i]) continue;

        // Procura o livro, se achar
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
        for(i = 0; i < biblioteca->tam_max_atual; i++) {
            if(biblioteca->livros[i]) {
                ImprimeLivro(biblioteca->livros[i]);
            }
        }
    } else {
        printf("A biblioteca esta vazia!\n");
    }
}

tBiblioteca* AumentaCapacidadeBiblioteca(tBiblioteca *biblioteca) {
    int i;
    biblioteca->tam_max_atual += NUM_INICIAL_LIVROS;
    biblioteca->livros = (tLivros **) realloc(biblioteca->livros, (biblioteca->tam_max_atual)*sizeof(tLivros *));
    // Inicializando os espacos
    for(i = biblioteca->tamanho; i < biblioteca->tam_max_atual; i++) {
        biblioteca->livros[i] = NULL;
    }
    return biblioteca;
}