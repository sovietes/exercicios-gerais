#include <stdio.h>
#include "utils_char.h"

int main() {
    int tamanho;
    char *vet;
    scanf("%d", &tamanho);
    scanf("%*[^a-zA-Z0-9]");
    vet = CriaVetor(tamanho);
    ImprimeString(vet, tamanho);
    LeVetor(vet, tamanho);
    ImprimeString(vet, tamanho);

    free(vet);
    return 0;
}