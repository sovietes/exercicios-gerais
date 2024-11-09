#include <stdio.h>
#include "./data.h"

int main() {
    int dia, mes, ano;


    // Lendo primeira data
    scanf("%d/%d/%d", &dia, &mes, &ano);


    if(verificaDataValida(dia, mes, ano)) {

        // Imprime a data por extenso
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);

        // Verifica se eh bissexo
        if(verificaBissexto(ano)) {
            printf("O ano informado eh bissexto\n");
        } else {
            printf("O ano informado nao eh bissexto\n");
        }

        // Numero de dias do mes
        printf("O mes informado possui %02d dias\n", numeroDiasMes(mes, ano));

        // Data seguinte
        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);


    } else {
        printf("A data informada eh invalida\n");
    }

    return 0;
}