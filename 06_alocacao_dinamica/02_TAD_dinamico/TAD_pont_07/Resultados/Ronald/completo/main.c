#include <stdio.h>
#include "./data.h"

int main() {
    // Criando e inicializando vetor datas
    tData *data1 = CriaData(), *data2 = CriaData();
    // Lendo datas
    LeData(data1);
    LeData(data2);
    // Verificando se sao validas
    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    } else {
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        // Comparando datas
        if(ComparaData(data1, data2) == -1) {
            printf("A primeira data eh mais antiga\n");
        } else if(ComparaData(data1, data2) == 1) {
            printf("A segunda data eh mais antiga\n");
        } else {
            printf("As datas sao iguais\n");
        }
        // Diferenca
        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));
    }
    
    LiberaData(data1);
    LiberaData(data2);
    return 0;
}