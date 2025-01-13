#include <stdio.h>
#include "./vetor.h"

int add(int, int);
int mult(int, int);

int main() {

    Vetor vetor;
    Vetor *ptrVetor = &vetor;
    LeVetor(ptrVetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(ptrVetor, add));
    printf("Produto: %d\n", AplicarOperacaoVetor(ptrVetor, mult));
    

    return 0;
}

int add(int n1, int n2) {
    return n1+n2;
}

int mult(int n1, int n2) {
    return n1*n2;
}