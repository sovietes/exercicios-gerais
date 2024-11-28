#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols) {
    int i, j;
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    // Zerando a matrix
    for(i = 0; i < matrix.rows; i++) {
        for(j = 0; j < matrix.cols; j++) {
            matrix.data[i][j] = 0;
        }
    }
    return matrix;
}

tMatrix MatrixRead(tMatrix matrix) {
    int i, j;
    for(i = 0; i < matrix.rows; i++) {
        for(j = 0; j < matrix.cols; j++) {
            scanf("%d", &matrix.data[i][j]);
        }
    }

    return matrix;
}

void MatrixPrint(tMatrix matrix) {
    int i, j;
    for(i = 0; i < matrix.rows; i++) {
        printf("|");
        for(j = 0; j < matrix.cols; j++) {
            printf("%d", matrix.data[i][j]);
            if(j < matrix.cols-1) printf(" ");
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
    if((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols)) {
        return 1;
    } else {
        return 0;
    }
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
    if((matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols)) {
        return 1;
    } else {
        return 0;
    }
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    if(matrix1.cols == matrix2.rows) {
        return 1;
    } else {
        return 0;
    }
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
    int i, j;
    tMatrix matrixResult;
    matrixResult = MatrixCreate(matrix1.rows, matrix1.cols);

    for(i = 0; i < matrixResult.rows; i++) {
        for(j = 0; j < matrixResult.cols; j++) {
            matrixResult.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return matrixResult;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    int i, j;
    tMatrix matrixResult;
    matrixResult = MatrixCreate(matrix1.rows, matrix1.cols);

    for(i = 0; i < matrixResult.rows; i++) {
        for(j = 0; j < matrixResult.cols; j++) {
            matrixResult.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return matrixResult;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    int i, j, k;
    tMatrix matrixResult;
    matrixResult = MatrixCreate(matrix1.rows, matrix2.cols);

    for(i = 0; i < matrixResult.rows; i++) {
        for(j = 0; j < matrixResult.cols; j++) {
            for(k = 0; k < matrix1.cols; k++) {
                matrixResult.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }

    return matrixResult;
}

tMatrix TransposeMatrix(tMatrix matrix) {
    int i, j;
    tMatrix matrixResult;
    matrixResult = MatrixCreate(matrix.cols, matrix.rows);

    for(i = 0; i < matrixResult.rows; i++) {
        for(j = 0; j < matrixResult.cols; j++) {
            matrixResult.data[i][j] = matrix.data[j][i];
        }
    }

    return matrixResult;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    int i, j;
    tMatrix matrixResult;
    matrixResult = MatrixCreate(matrix.rows, matrix.cols);

    for(i = 0; i < matrixResult.rows; i++) {
        for(j = 0; j < matrixResult.cols; j++) {
            matrixResult.data[i][j] = matrix.data[i][j] * scalar;
        }
    }

    return matrixResult;
}