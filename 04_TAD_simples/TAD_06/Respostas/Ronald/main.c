#include <stdio.h>
#include "matrix_utils.h"

void ImprimeMenu();

int main() {
    tMatrix matrix1, matrix2;
    int l1, c1, l2, c2, op = -1;
    // Lendo primeira matriz
    scanf("%d %d", &l1, &c1);
    matrix1 = MatrixCreate(l1, c1);
    matrix1 = MatrixRead(matrix1);
    // Lendo segunda matriz
    scanf("%d %d", &l2, &c2);
    matrix2 = MatrixCreate(l2, c2);
    matrix2 = MatrixRead(matrix2);

    while(1) {
        ImprimeMenu();
        scanf("%d", &op);
        // Parar se a opcao for 6
        if(op == 6) break;

        switch (op) {
            case 1:
                if(PossibleMatrixSum(matrix1, matrix2)) {
                    MatrixPrint(MatrixAdd(matrix1, matrix2));
                }  else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;

            case 2:
                if(PossibleMatrixSub(matrix1, matrix2)) {
                    MatrixPrint(MatrixSub(matrix1, matrix2));
                }  else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;

            case 3:
                if(PossibleMatrixMultiply(matrix1, matrix2)) {
                    MatrixPrint(MatrixMultiply(matrix1, matrix2));
                }  else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                }
                break;

            case 4:
                int scalar, matrixEscolhida;
                scanf("%d %d", &scalar, &matrixEscolhida);
                if(matrixEscolhida == 1) {
                    matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                    MatrixPrint(matrix1);
                } else if(matrixEscolhida == 2) {
                    matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                    MatrixPrint(matrix2);
                }
                break;
            
            case 5:
                MatrixPrint(TransposeMatrix(matrix1));
                MatrixPrint(TransposeMatrix(matrix2));
                break;
            }
    }

    return 0;
}

void ImprimeMenu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}