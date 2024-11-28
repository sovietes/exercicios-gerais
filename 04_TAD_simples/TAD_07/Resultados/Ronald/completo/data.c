#include "data.h"

tData CriaData(int dia, int mes, int ano) {
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data) {
    // Verifica dia
    if(data.dia >= 1 && data.dia <= NumeroDiasMes(data)) {
        // Verifica mes
        if(data.mes >= 1 && data.mes <= 12) {
            return 1;
        }
    }

    return 0;
}

int NumeroDiasMes(tData data) {
    int mes;
    mes = data.mes;

    if(mes == 2) {
        if(VerificaBissexto(data)) {
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

int VerificaBissexto(tData data) {
    int ano;
    ano = data.ano;
    
    if(ano%4 == 0) { // Etapa 1
        if(ano%100 == 0) { // Etapa 2
            if(ano%400 == 0) { // Etapa 3
                return 1;
            } else { // Etapa 5
                return 0;
            }
        } else { // Etapa 4
            return 1;
        }
    } else { // Etapa 5
        return 0;
    }
}

int ComparaData(tData data1, tData data2) {
    int d1, m1, a1, d2, m2, a2;
    d1 = data1.dia;
    m1 = data1.mes;
    a1 = data1.ano;
    d2 = data2.dia;
    m2 = data2.mes;
    a2 = data2.ano;
    
    if(a1 > a2) {
        return 1;
    } else if(a1 == a2) {
        // Verificando o mes, caso o ano seja igual
        if(m1 > m2) {
            return 1;
        } else if(m1 == m2) {
            // Verificando o dia, caso o mes seja igual
            if(d1 > d2) {
                return 1;
            } else if(d1 == d2) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

int CalculaDiasAteMes(tData data) {
    int i, qtdDiasMes = 0;
    tData auxData = CriaData(1, 1, 0000);
    for(i = 1; i < data.mes; i++) {
        qtdDiasMes += NumeroDiasMes(auxData);
        auxData.mes++;
    }
    return qtdDiasMes;
}

void ImprimeMesExtenso(tData data) {
    int mes;
    mes = data.mes;

    switch (mes)
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

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

int CalculaDiferencaDias(tData data1, tData data2) {
    int qtdDiasData1 = 0, qtdDiasData2 = 0, diferencaDias = 0, diferencaAnos = 0;
    qtdDiasData1 = CalculaDiasAteMes(data1) + data1.dia;
    qtdDiasData2 = CalculaDiasAteMes(data2) + data2.dia;

    if(ComparaData(data1, data2) == 1) {
        // Definindo a diferenca de dias
        diferencaDias = qtdDiasData1 - qtdDiasData2;

        // Resolvendo a diferenca de anos
        while(data1.ano > data2.ano) {
            data2.ano++;
            if(VerificaBissexto(data2)) {
                diferencaDias += 366;
            } else {
                diferencaDias += 365;
            }
        }

    } else if(ComparaData(data1, data2) == -1) {
        // Definindo a diferenca de dias
        diferencaDias = qtdDiasData2 - qtdDiasData1;

        // Resolvendo a diferenca de anos
        while(data1.ano < data2.ano) {
            data1.ano++;
            if(VerificaBissexto(data1)) {
                diferencaDias += 366;
            } else {
                diferencaDias += 365;
            }            
        }

    } else {
        diferencaDias = 0;
    }

    return diferencaDias;
}
