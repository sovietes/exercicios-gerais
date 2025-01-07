#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "utils_char.h"

char *CriaVetor(int tamanho) {
    int i;
    char *vetor;
    vetor = malloc(tamanho*sizeof(char) +1);
    
    if(vetor == NULL) {
        printf("Erro ao criar o vetor.\n");
        exit(0);
    }

    for(i = 0; i < tamanho; i++) {
        *(vetor+i) = '_';
    }
    *(vetor+i) = '\0';

    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    int i;
    char c;

    for(i = 0; i < tamanho; i++) {
        scanf("%c", &c);
        if(c == '\n') break;
        *(vetor+i) = c;
    }
}

void ImprimeString(char *vetor, int tamanho) {
    int i;
    printf("%s", vetor);
    printf("\n");
}

void LiberaVetor(char *vetor) {
    free(vetor);
}