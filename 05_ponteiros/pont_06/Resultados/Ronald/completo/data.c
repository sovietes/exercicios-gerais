#include "./data.h"
#include <stdio.h>

/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 * 
 * Esta função recebe como parâmetro o dia, mês e ano de uma data e inicializa a estrutura tData correspondente com esses valores.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @param data Ponteiro para a estrutura tData que será inicializada.
 */
void InicializaDataParam( int dia, int mes, int ano, tData *data) {
    // Armazenando
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    // Corrigindo numero de dias e de meses caso invalido
    if(mes > 12) {
        data->mes = 12;
    } 
    if(dia > InformaQtdDiasNoMes(data)) {
        data->dia = InformaQtdDiasNoMes(data);
    }
}

/**
 * @brief Lê uma data do usuário.
 * 
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses valores na estrutura tData correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será preenchida com os valores lidos.
 */
void LeData(tData *data) {
    int dia, mes, ano;
    scanf("%d %d %d\n", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

/**
 * @brief Imprime uma data na tela.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o dia, mês e ano correspondentes.
 * 
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData( tData *data ) {
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano correspondente é bissexto.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto( tData *data ) {
    int ano;
    ano = data->ano;
    
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

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade de dias no mês correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes(tData *data) {
    int mes;
    mes = data->mes;

    if(mes == 2) {
        if(EhBissexto(data)) {
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

/**
 * @brief Avança uma data para o dia seguinte.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e avança a data correspondente para o dia seguinte.
 * 
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte( tData *data ) {
    data->dia += 1;

    if(data->dia > InformaQtdDiasNoMes(data)) {
        data->dia = 1;
        data->mes += 1;
    }

    if(data->mes > 12) {
        data->mes = 1;
        data->ano += 1;
    }
}

int EhIgual( tData *data1, tData *data2 ) {
    if(data1->dia == data2-> dia) {
        if(data1->mes == data2->mes) {
            if(data1->ano == data2->ano) {
                return 1;
            }
        }
    }
    return 0;
}