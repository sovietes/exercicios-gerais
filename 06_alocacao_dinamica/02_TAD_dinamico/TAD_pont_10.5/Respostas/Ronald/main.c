#include <stdio.h>
#include "./biblioteca.h"

void ImprimeMenu();

int main() {
    int i, qtdOperacoes, op;
    tBiblioteca *biblioteca;
    biblioteca = InicializarBiblioteca();

    scanf("%d\n", &qtdOperacoes);
    
    ImprimeMenu();
    
    for(i = 0; i < qtdOperacoes; i++) {
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            tLivros *livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);
            break;
        case 2:
            char titulo[100];
            scanf("%s", titulo);
            RemoverLivroDaBiblioteca(biblioteca, titulo);
            break;
        case 3:
            ListarLivrosDaBiblioteca(biblioteca);
            break;
        default:
            printf("Operacao invalida!\n");
            ApagaBiblioteca(biblioteca);
            exit(0);
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
