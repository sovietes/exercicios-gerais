#include <stdio.h>
#include "./vetor.h"

void LeVetor(Vetor *vetor) {
    int i;
    scanf("%d", &vetor->tamanhoUtilizado);
    scanf("%*[^0-9]");
    for(i = 0; i < vetor->tamanhoUtilizado; i++) {
        scanf("%d", vetor->elementos+i);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    int i, acumulador = *vetor->elementos;
    // Comeca no segundo elemento, pois o acumulador ja armazena o primeiro
    for(i = 1; i < vetor->tamanhoUtilizado; i++) {
        acumulador = op(acumulador, *(vetor->elementos+i));
    }
    return acumulador;
}

