#include "livro.h"

tLivros lerLivro() {
    tLivros livro;
    scanf("%*[^a-zA-Z0-9]");
    scanf("%[^\n]", livro.titulo);
    scanf("%*c");
    scanf("%[^\n]", livro.autor);
    scanf("%*c");
    scanf("%d", &livro.anoPublicacao);
    return livro;
}

void imprimeLivro(tLivros livro) {
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}