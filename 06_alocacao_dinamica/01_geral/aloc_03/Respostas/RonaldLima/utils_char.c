#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "utils_char.h"

char *CriaVetor(int tamanho) {
    int i;
    char *vetor;
    vetor = malloc(tamanho*sizeof(char));
    assert(vetor);

    for(i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }
    
    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    int i;
    char c;

    for(i = 0; i < tamanho; i++) {
        scanf("%c", &c);
        if(c == '\n') break;
        vetor[i] = c;
    }
}

void ImprimeString(char *vetor, int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char *vetor) {
    free(vetor);
}