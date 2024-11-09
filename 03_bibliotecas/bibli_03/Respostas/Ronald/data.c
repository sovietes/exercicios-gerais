#include "./data.h"

int verificaDataValida(int dia, int mes, int ano) {
    // Verifica se o ano é valido (Será positivo independente de ser AC ou DC)
    if(ano >= 0) {
        // Verifica se o mês é valido
        if(mes >= 1 && mes <= 12) {
            // Verificar numero de dias
            if(dia >= 0 && dia <= numeroDiasMes(mes, ano)) {
                return 1;
            }
        }
    }

    return 0;
}

void imprimeMesExtenso(int mes) {
    switch(mes) {
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

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

/*
1- Se o ano for uniformemente divisível por 4, vá para a etapa 2. Caso contrário, vá para a etapa 5.
2- Se o ano for uniformemente divisível por 100, vá para a etapa 3. Caso contrário, vá para a etapa 4.
3- Se o ano for uniformemente divisível por 400, vá para a etapa 4. Caso contrário, vá para a etapa 5.
4- O ano é bissexto (tem 366 dias).
5- O ano não é um ano bissexto (tem 365 dias).
*/

int verificaBissexto(int ano) {
    if(ano%4 == 0) { // 1
        if(ano%100 == 0) { // 2
            if(ano%400 == 0) { // 3
                return 1; // 4
            } else { // 5
                return 0;
            }
        } else { // 4
            return 1;
        }
    } else {
        return 0;
    }
}

int numeroDiasMes(int mes, int ano) {
    if(mes == 2) {
        if(verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    }

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else {
        return 30;
    }
}


int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(ano1 > ano2) {
        return 1;
    } else if (ano1 < ano2) {
        return -1;
    }

    if(ano1 == ano2) {
        if(mes1 > mes2) {
            return 1;
        } else if (mes1 < mes2) {
            return -1;
        }
    }

    if(ano1 == ano2 && mes1 == mes2) {
        if(dia1 > dia2) {
            return 1;
        } else if(dia1 < dia2) {
            return -1;
        } else {
            // No caso das datas serem iguais
            return 0;
        }
    }
}

int calculaDiasAteMes(int mes, int ano) {
    int i, qtdDias = 0;
    
    for(i = 1; i < mes; i++) {
        qtdDias += numeroDiasMes(i, ano);
    }

    return qtdDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diferenca, qtdDiasPrimeiraData, qtdDiasSegundaData, maiorData;

    maiorData = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    qtdDiasPrimeiraData = calculaDiasAteMes(mes1, ano1) + dia1;
    qtdDiasSegundaData = calculaDiasAteMes(mes2, ano2) + dia2;

    if(maiorData == 1) {
        diferenca = qtdDiasPrimeiraData - qtdDiasSegundaData;

        // Para somar a diferenca de dias ocasionado pela diferenca de anos
        while(ano2 < ano1) {
            if(verificaBissexto(ano2)) {
                diferenca += 366;
            } else {
                diferenca += 365;
            }
            ano2++;
        }

    } else if(maiorData == -1) {
        diferenca = qtdDiasSegundaData - qtdDiasPrimeiraData;

        // Para somar a diferenca de dias ocasionado pela diferenca de anos
        while(ano1 < ano2) {
            if(verificaBissexto(ano1)) {
                diferenca += 366;
            } else {
                diferenca += 365;
            }
            ano1++;
        }

    } else {
        diferenca = 0;
    }
    
    return diferenca;
}
