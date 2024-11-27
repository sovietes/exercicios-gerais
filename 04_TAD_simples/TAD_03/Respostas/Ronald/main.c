#include <stdio.h>
#include "locadora.h"

void LimpaBufferAntes();
void LimpaBufferAposEquebraLinha();

int main() {

    tLocadora locadora;
    char op;

    locadora = criarLocadora();

    while(scanf("%c", &op) == 1) {
        if(op == 'C') {
            scanf("%*[^0-9]");
            locadora = lerCadastroLocadora(locadora);
            LimpaBufferAposEquebraLinha();
        } else if(op == 'E') {
            LimpaBufferAntes();
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora(locadora);
            LimpaBufferAposEquebraLinha();
        } else if(op == 'D') {
            LimpaBufferAntes();
            locadora = lerDevolucaoLocadora(locadora);
            LimpaBufferAposEquebraLinha();
        } else if(op == 'A') {
            LimpaBufferAntes();
            locadora = lerAluguelLocadora(locadora);
            LimpaBufferAposEquebraLinha();
        }
    }
    
    consultarLucroLocadora(locadora);
    return 0;
}

void LimpaBufferAntes() {
    scanf("%*[^\n]");
    scanf("%*c");
}

void LimpaBufferAposEquebraLinha() {
    scanf("%*[^A-Z]");
    printf("\n");
}