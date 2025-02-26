#include <stdio.h>
#include <stdlib.h>
#include "./numcomplexo.h"

struct complexo {
    float real;
    float imaginario;
};

/**
 * @brief Função que cria uma estrutura que armazena um número complexo
 *
 * @param real - Parte real do número complexo
 * @param imag - Parte Imaginária do número complexo
 *
 * @return Um ponteiro para um novo número complexo, cuja parte real e imaginária são iguais 
 * aos valores passados para a função
 */
tNumComplexo* CriaNumComplexo(float real, float imag) {
    tNumComplexo *n = (tNumComplexo *) malloc(sizeof(tNumComplexo));
    n->real = real;
    n->imaginario = imag;
    return n;
}

/**
 * @brief Obtém a parte imaginária do número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos obter a parte imaginária
 *
 * @return A parte imaginária, do tipo float, do número complexo
 */
float PegaParteImagComplexo(tNumComplexo *cplx) {
    return cplx->imaginario;
}

/**
 * @brief Obtém a parte real do número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos obter a parte real
 *
 * @return A parte real, do tipo float, do número complexo
 */
float PegaParteRealComplexo(tNumComplexo *cplx) {
    return cplx->real;
}

/**
 * @brief Imprime um número complexo
 *
 * @param cplx - Ponteiro para o número complexo que queremos imprimir
 *
 */
void ImprimeNumeroComplexo(tNumComplexo *cplx) {
    printf("%.2f + i%.2f", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
}

/**
 * @brief Libera a memória alocada para um número complexo.
 *
 * @param cplx - Ponteiro para o número complexo que queremos imprimir
 *
 */
void DestroiNumeroComplexo(tNumComplexo *cplx) {
    if(cplx) {
        free(cplx);
    }
}

/**
 * @brief retorna o número de bytes ocupado pela estrutura definida pelo usuário
 *
 * @return int - Número de bytes ocupado pela "struct complexo"
 *
 */
int RetornaNumBytesComplexo() {
    return sizeof(tNumComplexo);
}

/**
 * @brief Função que soma dois números complexos
 *
 * @param n1 - Ponteiro para o primeiro número complexo a ser somado
 * @param n2 - Ponteiro para o segundo número complexo a ser somado
 *
 * @return Um ponteiro para um novo número complexo, cujos valores são iguais a soma entre n1 e n2
 */
tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo *n2) {
    float real, imaginario;
    real = PegaParteRealComplexo(n1) + PegaParteRealComplexo(n2);
    imaginario = PegaParteImagComplexo(n1) + PegaParteImagComplexo(n2);

    tNumComplexo *novoNum = CriaNumComplexo(real, imaginario);
    return novoNum;
}

/**
 * @brief Função que multiplica dois números complexos
 *
 * @param n1 - Ponteiro para o primeiro número complexo a ser multiplicado
 * @param n2 - Ponteiro para o segundo número complexo a ser multiplicado
 *
 * @return Um ponteiro para um novo número complexo, cujos valores são iguais a multiplicação entre n1 e n2
 */
tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2) {
    float real, imaginario;
    real = (PegaParteRealComplexo(n1) * PegaParteRealComplexo(n2)) - (PegaParteImagComplexo(n1) * PegaParteImagComplexo(n2));
    imaginario = (PegaParteRealComplexo(n1) * PegaParteImagComplexo(n2)) + (PegaParteRealComplexo(n2) * PegaParteImagComplexo(n1));

    tNumComplexo *novoNum = CriaNumComplexo(real, imaginario);
    return novoNum;
}