#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

// Funcao auxiliar para deixar uma posicao de livro vazia
tLivros BIBLIOTECA_auxAnularLivro() {
    tLivros livro;
    livro.anoPublicacao = -1;
    livro.autor[0] = '\0';
    livro.titulo[0] = '\0';
    return livro;
}

tBiblioteca inicializarBiblioteca() {
    int i;
    tBiblioteca biblioteca;

    for(i = 0; i < MAX_LIVROS; i++) {
        biblioteca.livros[i] = BIBLIOTECA_auxAnularLivro(); 
    }

    biblioteca.tamanho = 0;
    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    int i;
    if(biblioteca.tamanho < MAX_LIVROS) {
        for(i = 0; i < MAX_LIVROS; i++) {
            // Se a posicao estiver vazia, salve o livro
            if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], "\0")) {
                // Adiciona o livro a biblioteca
                biblioteca.livros[i] = livro;
                // Atualiza o numero de livros da biblioteca
                biblioteca.tamanho++;
                // Mensagem de sucesso
                printf("Livro adicionado com sucesso!\n");
                break;
            }
        }

    } else {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.");
    }

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo) {
    int i, flagLivroEncontrado = 0;
    for(i = 0; i < MAX_LIVROS; i++) {
        if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)) {
            flagLivroEncontrado = 1;
            // Deixa a posição "vazia"
            biblioteca.livros[i] = BIBLIOTECA_auxAnularLivro();
            // Atualiza o numero de livros da biblioteca
            biblioteca.tamanho--;
            // Mensagem de sucesso
            printf("Livro removido com sucesso!\n");
            break;
        }
    }
    if(!flagLivroEncontrado) printf("Livro nao encontrado na biblioteca.\n");

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
    if(strcmp(livro.titulo, titulo) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    int i;
    if(biblioteca.tamanho == 0) {
        printf("A biblioteca esta vazia!");
    } else {
        printf("\nLista de Livros na Biblioteca:\n");
        for(i = 0; i < MAX_LIVROS; i++) {
            // Imprimir somente os espaços ocupados
            if(!verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], "\0")) {
                imprimeLivro(biblioteca.livros[i]);
            }
        }
    }
}



