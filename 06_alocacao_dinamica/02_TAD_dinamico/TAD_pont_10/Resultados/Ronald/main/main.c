#include <stdio.h>
#include <string.h>
#include "./biblioteca.h"

void ImprimeMenu();

int main() {
    tBiblioteca *biblioteca;
    biblioteca = InicializarBiblioteca();
    int qtdOperacoes, operacao, i;
    scanf("%d\n", &qtdOperacoes);

    ImprimeMenu();

    for(i = 0; i < qtdOperacoes; i++) {
        scanf("%d", &operacao);

        // Para a execucao
        if(operacao == 5) {
            printf("Operacao invalida!\n");
            break;
        }

        switch (operacao)
        {
        case 1:
            tLivros *livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);
            break;
        case 2:
            // Limpando buffer
            scanf("%*[^a-zA-Z]");
            // Lendo titulo
            char titulo[40];
            fgets(titulo, 40, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            RemoverLivroDaBiblioteca(biblioteca, titulo);
            break;
        case 3:
            ListarLivrosDaBiblioteca(biblioteca);
            break;
        }
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}

void ImprimeMenu() {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");
}