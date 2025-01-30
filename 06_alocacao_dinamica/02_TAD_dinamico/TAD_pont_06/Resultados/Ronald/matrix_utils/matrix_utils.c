#include <stdio.h>
#include <stdlib.h>
#include "./matrix_utils.h"

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix* MatrixCreate(int rows, int cols) {
    int i;
    tMatrix *matriz = NULL;
    // Alocando espaco para o tipo matrix e os atributos dela
    matriz = (tMatrix *) malloc(sizeof(tMatrix));
    if(!matriz) {
        printf("erro ao alocar matri!");
        exit(0);
    }
    matriz->rows = rows;
    matriz->cols = cols;

    // Alocando a matriz em si

    // Linhas primeiro
    matriz->data = (int **) malloc(rows*sizeof(int *));

    // Colunas
    for(i = 0; i < rows; i++) {
        matriz->data[i] = (int *) malloc(cols*sizeof(int));
    }


    return matriz;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix* matrix) {
    int i;
    if(matrix) {
        if(matrix->data) {
            for(i = 0; i < matrix->rows; i++) {
                if(matrix->data[i]) {
                    free(matrix->data[i]);
                }
            }
            free(matrix->data);
        }
        free(matrix);
    }
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix* matrix) {
    int i, j;
    for(i = 0; i < matrix->rows; i++) {
        for(j = 0; j < matrix->cols; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix* matrix) {
    int i, j;
    
    for(i = 0; i < matrix->rows; i++) {
        printf("|");
        for(j = 0; j < matrix->cols; j++) {
            printf("%d", matrix->data[i][j]);
            if(j < (matrix->cols - 1)) printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2) {
    if(matrix1->rows == matrix2->rows) {
        if(matrix1->cols == matrix2->cols) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2) {
    if(matrix1->rows == matrix2->rows) {
        if(matrix1->cols == matrix2->cols) {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2) {
    if(matrix1->cols == matrix2->rows) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2) {
    int i, j;
    tMatrix *matrizResultado;
    matrizResultado = MatrixCreate(matrix1->rows, matrix1->cols);

    for(i = 0; i < matrizResultado->rows; i++) {
        for(j = 0; j < matrizResultado->cols; j++) {
            matrizResultado->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return matrizResultado;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2) {
    int i, j;
    tMatrix *matrizResultado;
    matrizResultado = MatrixCreate(matrix1->rows, matrix1->cols);

    for(i = 0; i < matrizResultado->rows; i++) {
        for(j = 0; j < matrizResultado->cols; j++) {
            matrizResultado->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return matrizResultado;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2) {
    int i, j, k;
    tMatrix *matrizResultado;
    matrizResultado = MatrixCreate(matrix1->rows, matrix2->cols);

    for(i = 0; i < matrix1->rows; i++) {
        for(j = 0; j < matrix2->cols; j++) {
            matrizResultado->data[i][j] = 0;
            for(k = 0; k < matrix1->cols; k++) {
                matrizResultado->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }

    return matrizResultado;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix* TransposeMatrix(tMatrix* matrix) {
    int i, j;

    tMatrix *matrizResultado;
    matrizResultado = MatrixCreate(matrix->cols, matrix->rows);

    for(i = 0; i < matrizResultado->rows; i++) {
        for(j = 0; j < matrizResultado->cols; j++) {
            matrizResultado->data[i][j] = matrix->data[j][i];
        }
    }

    return matrizResultado;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar) {
    int i, j;
    tMatrix *matrizResultado = MatrixCreate(matrix->rows, matrix->cols);

    for(i = 0; i < matrix->rows; i++) {
        for(j = 0; j < matrix->cols; j++) {
            matrizResultado->data[i][j] = matrix->data[i][j] * scalar;
        }
    }

    return matrizResultado;
}