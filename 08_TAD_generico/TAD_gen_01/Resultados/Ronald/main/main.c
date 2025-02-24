#include <stdio.h>
#include "./tadgen.h"

int main() {
    int type, qtdElementos;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d\n", &type, &qtdElementos);
    tGeneric *generico = CriaGenerico(type, qtdElementos);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);

    return 0;
}