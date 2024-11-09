#include <stdio.h>
#include "matrix_utils.h"

void menuInterativo();
void processaOperacao(int opcao, int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]);

int main() {
    int rows1, cols1;
    int rows2, cols2;
    int opcao;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);


    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);


    while(scanf("%d", &opcao) == 1) {
        menuInterativo();
        processaOperacao(opcao, rows1, cols1, matrix1, rows2, cols2, matrix2);
    }

    return 0;
}

void menuInterativo() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

void processaOperacao(int opcao, int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]) {
        int escalar, matrizEscolhida;
        if(opcao == 1) {
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                int resultado[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, resultado);
                matrix_print(rows1, cols1, resultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }

        } else if (opcao == 2) {
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                int resultado[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, resultado);
                matrix_print(rows1, cols1, resultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }

        } else if (opcao == 3) {
            if(possible_matrix_multiply(cols1, rows2)) {
                int resultado[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, resultado);
                matrix_print(rows1, cols2, resultado);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }

        } else if (opcao == 4) {
            scanf("%d %d", &escalar, &matrizEscolhida);
            if(matrizEscolhida == 1) {
                scalar_multiply(rows1, cols1, matrix1, escalar);
                matrix_print(rows1, cols1, matrix1);
            } else {
                scalar_multiply(rows2, cols2, matrix2, escalar);
                matrix_print(rows2, cols2, matrix2);
            }

        } else if (opcao == 5) {
            int result1[cols1][rows1];
            int result2[cols2][rows2];

            transpose_matrix(rows1, cols1, matrix1, result1);
            transpose_matrix(rows2, cols2, matrix2, result2);

            matrix_print(cols1, rows1, result1);
            matrix_print(cols2, rows2, result2);

        } else if (opcao == 6) {
            return 0;
        }
}