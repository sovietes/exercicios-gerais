#include <stdio.h>
#include "biblioteca.h"

void ImprimirMenu();

int main() {
    tBiblioteca biblioteca; tLivros livro;
    int qtdOperacoes, operacao, i;
    char tituloRemovido[100];
    biblioteca = inicializarBiblioteca();
    scanf("%d", &qtdOperacoes);
    ImprimirMenu();

    for(i = 0; i < qtdOperacoes; i++) {
        scanf("%*[^0-9]");
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 1: // Cadastro de livro
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
            break;
        case 2: // Remover livro
            scanf("%*[^a-zA-Z0-9]");
            scanf("%s", tituloRemovido);
            biblioteca = removerLivroDaBiblioteca(biblioteca, tituloRemovido);
            break;
        case 3: // Listar livros
            listarLivrosDaBiblioteca(biblioteca);
            break;
        default:
            printf("Operacao invalida!\n");
            return 0;
        }

        
    }

    return 0;
}

void ImprimirMenu() {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");
}