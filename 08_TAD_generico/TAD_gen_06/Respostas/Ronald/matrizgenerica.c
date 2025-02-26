#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./matrizgenerica.h"

struct matrizgenerica {
    void ***matriz;
    int linhas, colunas;
    int numBytesElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
    tMatrizGenerica *m = (tMatrizGenerica *) malloc(sizeof(tMatrizGenerica));
    m->linhas = linhas;
    m->colunas = colunas;
    m->numBytesElem = numByteElem;

    // Linhas
    m->matriz = (void ***) malloc((sizeof(void **))*linhas);
    
    // Para cada linha, numero x de colunas
    int i;
    for(i = 0; i < linhas; i++) {
        m->matriz[i] = (void **) malloc(sizeof(void *)*colunas);
    }

    // E para cada elemento, alocar o numero de bytes para ele
    int j;
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            m->matriz[i][j] = (void *) malloc(numByteElem);
        }
    }

    return m;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica * mat) {
    int i, j;
    if(mat) {
        if(mat->matriz) {
            // Liberando elementos
            for(i = 0; i < mat->linhas; i++) {
                for(j = 0; j < mat->colunas; j++) {
                    free(mat->matriz[i][j]);
                }
            }
            // Liberando colunas
            for(i = 0; i < mat->linhas; i++) {
                free(mat->matriz[i]);
            }

            // Liberando as linhas
            free(mat->matriz);
        }
        free(mat);
    }
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat) {
    return mat->linhas;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat) {
    return mat->colunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna) {
    return mat->matriz[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem) {
    memcpy(mat->matriz[linha][coluna], elem, mat->numBytesElem);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

 void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))) {
    int i, j;
    for(i = 0; i < mat->linhas; i++) {
        for(j = 0; j < mat->colunas; j++) {
            imprime_elemento(mat->matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }
 }

 /**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat) {
    tMatrizGenerica *matrizNova = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->numBytesElem);

    int i, j;
    for(i = 0; i < mat->linhas; i++) {
        for(j = 0; j < mat->colunas; j++) {
            AtribuiElementoMatrizGenerica(matrizNova, j, i, mat->matriz[i][j]);
        }
    }

    return matrizNova;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante 
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)) {
    tMatrizGenerica *novaMatriz = CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);
    int i, j, k;
    void *elementoNovoSoma;
    void *elementoNovoMult;
    for(i = 0; i < mat1->linhas; i++) {
        for(j = 0; j < mat2->colunas; j++) {
            for(k = 0; k < mat1->colunas; k++) {
                if(k == 0) {
                    elementoNovoMult = multi_elem(mat1->matriz[i][k], mat2->matriz[k][j]);
                    AtribuiElementoMatrizGenerica(novaMatriz, i, j, elementoNovoMult);
                    free(elementoNovoMult);
                    //novaMatriz->matriz[i][j] = multi_elem(mat1->matriz[i][k], mat2->matriz[k][j]);
                } else {
                    elementoNovoMult = multi_elem(mat1->matriz[i][k], mat2->matriz[k][j]);
                    elementoNovoSoma = soma_elem(novaMatriz->matriz[i][j], elementoNovoMult);
                    AtribuiElementoMatrizGenerica(novaMatriz, i, j, elementoNovoSoma);
                    free(elementoNovoMult);
                    free(elementoNovoSoma);
                    //novaMatriz->matriz[i][j] = soma_elem(novaMatriz->matriz[i][j], multi_elem(mat1->matriz[i][k], mat2->matriz[k][j]));
                }
            }
        }
    }

    return novaMatriz;
}

/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)) {
    tMatrizGenerica *matrizNova = CriaMatrizGenerica(mat2->linhas, mat2->colunas, novoNumByteElem);

    int i, j;
    void *elementoNovo;
    for(i = 0; i < mat2->linhas; i++) {
        for(j = 0; j < mat2->colunas; j++) {
            elementoNovo = converte_elem(mat2->matriz[i][j]);
            AtribuiElementoMatrizGenerica(matrizNova, i, j, elementoNovo);
            free(elementoNovo);
            //matrizNova->matriz[i][j] = converte_elem(mat2->matriz[i][j]);
        }
    }

    //DestroiMatrizGenerica(mat2);

    return matrizNova;
}