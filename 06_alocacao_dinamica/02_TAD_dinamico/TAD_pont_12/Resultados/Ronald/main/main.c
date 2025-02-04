#include <stdio.h>
#include "./array.h"

int main() {

    Array *array;
    int numeroProcurado, resultadoBusca;
    array = CriarArray();
    LerArray(array);
    scanf("%d", &numeroProcurado);
    OrdenarArray(array);
    resultadoBusca = BuscaBinariaArray(array, numeroProcurado);
    if(resultadoBusca == -1) {
        printf("Elemento %d não encontrado no array (%d).\n", numeroProcurado, resultadoBusca);
    } else {
        printf("Elemento %d encontrado no índice %d.\n", numeroProcurado, resultadoBusca);
    }

    DestruirArray(array);

    return 0;
}