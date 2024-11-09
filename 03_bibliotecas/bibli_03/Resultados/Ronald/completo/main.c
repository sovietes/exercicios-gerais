#include <stdio.h>
#include "./data.h"

int main() {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    int maiorData;

    // Lendo primeira data
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    // Lendo segunda data
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if(verificaDataValida(dia1, mes1, ano1) && verificaDataValida(dia2, mes2, ano2)) {

        // Imprime primeira data
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);

        // Imprime segunda data
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);

        // Imprime data mais antiga
        maiorData = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
        if(maiorData == 1) {
            printf("A segunda data eh mais antiga\n");
        } else if(maiorData == -1) {
            printf("A primeira data eh mais antiga\n");
        } else {
            printf("As datas sao iguais\n");
        }

        //Imprime a diferenca de dias
        printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));

    } else {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}