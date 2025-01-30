#include <stdio.h>
#include <stdlib.h>
#include "./data.h"

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData() {
    tData *data = NULL;
    data = (tData *) malloc(sizeof(tData));
    if(!data) {
        printf("erro ao alocar data!!");
        exit(0);
    }
    data->dia = -1;
    data->mes = -1;
    data->ano = -1;
    return data;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data) {
    scanf("%d/%d/%d\n", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data) {
    if(data) {
        free(data);
    }
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data) {
    if((data->dia >= 1) && (data->dia <= NumeroDiasMes(data))) {
        if((data->mes >= 1) && (data->mes <= 12)) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data) {
    switch (data->mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Marco");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data) {
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data) {
    int ano = data->ano;

    return (ano%4 == 0 && (ano%100 != 0 || ano%400 == 0));
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data) {
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(VerificaBissexto(data)) {
        diasMes[1] = 29;
    }

    return diasMes[data->mes-1];  
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2) {
    // Anos
    if(data1->ano != data2->ano) {
        return data1->ano > data2->ano ? 1 : -1;
    }

    // Meses
    if(data1->mes != data2->mes) {
        return data1->mes > data2->mes ? 1 : -1;
    }

    if(data1->dia != data2->dia) {
        return data1->dia > data2->dia ? 1 : -1;
    }

    // Retornara zero se for igual
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data) {
    tData *dataAux = CriaData();
    *dataAux = *data;
    int qtdDias = 0;

    while(dataAux->mes > 0) {
        dataAux->mes--;
        qtdDias += NumeroDiasMes(dataAux);
    }
    
    LiberaData(dataAux);

    return qtdDias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2) {
    int anoBase;
    int numDiasData1 = CalculaDiasAteMes(data1) + (data1->dia), numDiasData2 = CalculaDiasAteMes(data2) + (data2->dia);
    // Criando datas reservas para nao alterar as originais e atribuindo valores
    tData *dataAux1 = CriaData(), *dataAux2 = CriaData();
    *dataAux1 = *data1, *dataAux2 = *data2;
    // O melhor algoritmo para isso eh converter em um numero de dias a partir de um ano base.
    // Nesse caso, irei escolher o menor ano como ano base. Ex. Entre 25/02/2022 e 23/05/2019, meu ano base
    // sera 2019.

    // Definindo ano base como o menor ano. Se os anos forem iguais, tanto faz
    anoBase = ComparaData(data1, data2) == 1 ? data2->ano : data1->ano;

    // Calculando a quantidade de dias do ano base ate o ano "atual"
    while(dataAux1->ano > anoBase) {
        dataAux1->ano--;
        numDiasData1 += VerificaBissexto(dataAux1) ? 366 : 365;
    }
    // Calculando a quantidade de dias do ano base ate o ano "atual"
    while(dataAux2->ano > anoBase) {
        dataAux2->ano--;
        numDiasData2 += VerificaBissexto(dataAux2) ? 366 : 365;
    }
    // Liberando datas
    LiberaData(dataAux1); LiberaData(dataAux2);
    // Retornando a diferenca de dias
    return ComparaData(data1, data2) == 1 ? numDiasData1 - numDiasData2 : numDiasData2 - numDiasData1;
}
