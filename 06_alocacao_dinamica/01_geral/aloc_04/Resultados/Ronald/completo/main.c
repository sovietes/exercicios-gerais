#include <stdio.h>
#include "./utils_char2.h"

int main() {
    char *vetor;
    int tamanho = TAM_PADRAO;
    vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
}