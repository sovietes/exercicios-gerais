#include "departamento.h"
#include <string.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor) {
    tDepartamento departamento;
    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    strcpy(departamento.diretor, diretor);
    departamento.media_geral = calculaMediaGeralDepartamento(departamento);
    return departamento;
}

void imprimeAtributosDepartamento (tDepartamento depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", calculaMediaGeralDepartamento(depto));
    printf("desvio padrao => %.2f\n", calculaDesvioPadraoDepartamento(depto));
    printf("\n");
}

int validaMediaDepartamento (int media) {
    if(media >= 0 && media <= 10) {
        return 1;
    } else {
        return 0;
    }
}

double calculaDesvioPadraoDepartamento(tDepartamento depto) {
    double desvPad = 0;
    double media = calculaMediaGeralDepartamento(depto);
    desvPad += pow((media - depto.m1), 2);
    desvPad += pow((media - depto.m2), 2);
    desvPad += pow((media - depto.m3), 2);

    desvPad /= 3;

    desvPad = sqrt(desvPad);
    return desvPad;
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
    double media;
    media = ((float)depto.m1 + (float)depto.m2 + (float)depto.m3)/3;
    return media;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
    int i, j;
    tDepartamento aux;
    for(i = 0; i < tamanho; i++) {
        for(j = i+1; j < tamanho; j++) {
            if(d[i].media_geral < d[j].media_geral) {
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }
}