#include <stdio.h>
#include "utils.h"

int main() {
  int *vetor, qtdElementos;
  scanf("%d", &qtdElementos);
  vetor = CriaVetor(qtdElementos);
  LeVetor(vetor, qtdElementos);

  printf("%.2f", CalculaMedia(vetor, qtdElementos));

  LiberaVetor(vetor);
  
}