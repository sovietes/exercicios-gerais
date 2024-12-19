#include <stdio.h>
#include "utils.h"

int main() {
  int *vetor, qtdElementos;
  scanf("%d", &qtdElementos);
  vetor = CriaVetor(qtdElementos);
  LeVetor(vetor, qtdElementos);

  printf("%.2f\n", CalculaMedia(vetor, qtdElementos));

  LiberaVetor(vetor);
  
}