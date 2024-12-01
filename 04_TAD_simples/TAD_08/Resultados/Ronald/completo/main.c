#include <stdio.h>
#include "departamento.h"

int main() {
    int qtdDptos, m1, m2, m3, i;
    float media_geral;
    char nome[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], diretor[STRING_MAX];
    scanf("%d", &qtdDptos);
    tDepartamento departamentos[qtdDptos];

    for(i = 0; i < qtdDptos; i++) {
        scanf("%*[^a-zA-Z]");
        scanf("%[^\n]", nome);
        scanf("%*c");
        scanf("%[^\n]", diretor);
        scanf("%*c");
        scanf("%[^\n]", c1);
        scanf("%*c");
        scanf("%[^\n]", c2);
        scanf("%*c");
        scanf("%[^\n]", c3);
        scanf("%*c");
        scanf("%d %d %d", &m1, &m2, &m3);
        departamentos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(departamentos, qtdDptos);

    for(i = 0; i < qtdDptos; i++) {
        imprimeAtributosDepartamento(departamentos[i]);
    }


    return 0;
}