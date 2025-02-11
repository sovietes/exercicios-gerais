#include <stdio.h>
#include "./locadora.h"

void LimpaBuffer();

int main() {
    tLocadora *locadora;
    locadora = CriarLocadora();
    char opcao;

    scanf("%*[^A-Z]");

    while(scanf("%c", &opcao) != EOF) {
        switch (opcao)
        {
        case 'C':
            LimpaBuffer();
            LerCadastroLocadora(locadora);
            printf("\n");
            break;
        case 'A':
            LimpaBuffer();
            LerAluguelLocadora(locadora);
            printf("\n");
            break;
        case 'D':
            LimpaBuffer();
            LerDevolucaoLocadora(locadora);
            printf("\n");
            break;
        case 'E':   
            LimpaBuffer();
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            printf("\n");
            break;
        }
    }
    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);


    return 0;
}

void LimpaBuffer() {
    scanf("%*[^\n]");
    scanf("%*c");
}