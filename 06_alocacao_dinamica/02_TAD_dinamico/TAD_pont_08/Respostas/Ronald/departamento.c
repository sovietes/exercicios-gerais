#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./departamento.h"

/**
 * @brief Cria uma estrutura, alocada dinamicamente, que possui os campos de um departamento. 
 * Lembre-se de inicializar os ponteiros com NULL e as variáveis númericas com -1.
 * 
 * @return Um ponteiro para uma estrutura de um Departamento.
 */
tDepartamento* CriaDepartamento() {
    tDepartamento *departamento = NULL;
    departamento = (tDepartamento *) malloc(sizeof(tDepartamento));
    if(!departamento) {
        printf("erro ao alocar departamento!!\n");
        exit(0);
    }
    departamento->nome = NULL;
    departamento->c1 = departamento->c2 = departamento->c3 = NULL;
    departamento->m1 = departamento->m2 = departamento->m3 = -1;
    departamento->diretor = NULL;
    departamento->media_geral = -1;
    
    return departamento;
}

/**
 * @brief Preenche os dados de uma estrutura departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 */
void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor) {
    // Preenchendo nome dos cursos
    depto->c1 = (char *) malloc((strlen(c1) + 1)*sizeof(char));
    depto->c2 = (char *) malloc((strlen(c2) + 1)*sizeof(char));
    depto->c3 = (char *) malloc((strlen(c3) + 1)*sizeof(char));
    strcpy(depto->c1, c1);
    strcpy(depto->c2, c2);
    strcpy(depto->c3, c3);
    // Preenchendo nome dpt
    depto->nome = (char *) malloc((strlen(nome) + 1)*sizeof(char));
    strcpy(depto->nome, nome);
    // Preenchendo medias cursos
    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;
    // Preenchendo nome do diretor
    depto->diretor = (char *) malloc((strlen(diretor) + 1)*sizeof(char));
    strcpy(depto->diretor, diretor);
}

void LiberaMemoriaDepartamento(tDepartamento* depto) {
    if(depto) {
        // Liberando nome dos cursos
        if(depto->c1) free(depto->c1);
        if(depto->c2) free(depto->c2);
        if(depto->c3) free(depto->c3);
        // Liberando nome do dpt
        if(depto->nome) free(depto->nome);
        // Liberando nome diretor
        if(depto->diretor) free(depto->diretor);

        free(depto);
    }
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void ImprimeAtributosDepartamento (tDepartamento* depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto->nome);
    printf("diretor => %s\n", depto->diretor);
    printf("curso1 => %s, media1 => %d\n", depto->c1, depto->m1);
    printf("curso2 => %s, media2 => %d\n", depto->c2, depto->m2);
    printf("curso3 => %s, media3 => %d\n", depto->c3, depto->m3);
    printf("media geral => %.2f\n", CalculaMediaGeralDepartamento(depto));
    printf("desvio padrao => %.2f\n\n", CalculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int ValidaMediaDepartamento (int media) {
    if(media >= 0 && media <= 10) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double CalculaDesvioPadraoDepartamento(tDepartamento* depto) {
    double media = CalculaMediaGeralDepartamento(depto);
    double variacoes = 0;

    variacoes += pow((depto->m1 - media), 2);
    variacoes += pow((depto->m2 - media), 2);
    variacoes += pow((depto->m3 - media), 2);

    return sqrt(variacoes/3);

}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double CalculaMediaGeralDepartamento(tDepartamento* depto) {
    double media;
    media = ((double)depto->m1 + (double)depto->m2 + (double)depto->m3)/3;
    return media;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho) {
    int i, j;
    tDepartamento *aux;
    for(i = 0; i < tamanho; i++) {
        for(j = i+1; j < tamanho; j++) {
            if(CalculaMediaGeralDepartamento(d[i]) < CalculaMediaGeralDepartamento(d[j])) {
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }
}