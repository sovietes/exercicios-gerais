#include "utils.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int *CriaVetor(int tamanho) {
  int *vetor;
  vetor = malloc(tamanho*sizeof(int));
  assert(vetor);
  return vetor;
}

void LeVetor(int *vetor, int tamanho) {
  int i;
  for(i = 0; i < tamanho; i++) {
    scanf("%d", &vetor[i]);
  }
}

float CalculaMedia(int *vetor, int tamanho) {
  int i;
  float media = 0;
  for(i = 0; i < tamanho; i++) {
    media += (float)vetor[i];
  }
  media /= (float)tamanho;
  return media;
}

void LiberaVetor(int *vetor) {
  free(vetor);
}
