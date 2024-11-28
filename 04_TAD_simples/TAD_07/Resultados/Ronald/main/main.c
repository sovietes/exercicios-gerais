#include <stdio.h>
#include "data.h"

int main() {
    tData data1, data2;
    int d1, m1, a1, d2, m2, a2;
    scanf("%d/%d/%d", &d1, &m1, &a1);
    scanf("%d/%d/%d", &d2, &m2, &a2);
    data1 = CriaData(d1, m1, a1);
    data2 = CriaData(d2, m2, a2);

    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);   

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    if(ComparaData(data1, data2) == -1) {
        printf("A primeira data eh mais antiga\n");
    } else if(ComparaData(data1, data2) == 1) {
        printf("A segunda data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));

    return 0;
}