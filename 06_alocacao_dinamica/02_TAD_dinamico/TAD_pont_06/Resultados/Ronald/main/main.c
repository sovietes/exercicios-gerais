#include <stdio.h>
#include "./matrix_utils.h"

void ImprimeMenu();

int main() {

    tMatrix *matriz1, *matriz2;
    
    // Lendo matriz1
    int rows1, cols1;
    scanf("%d %d\n", &rows1, &cols1);
    matriz1 = MatrixCreate(rows1, cols1);
    MatrixRead(matriz1);

    // Lendo matriz2
    int rows2, cols2;
    scanf("%d %d\n", &rows2, &cols2);
    matriz2 = MatrixCreate(rows2, cols2);
    MatrixRead(matriz2);

    // Lendo opcoes
    int flagStop = 0, opcao = 0;
    tMatrix *matrizResultado = NULL;

    while(!flagStop) {
        ImprimeMenu();
        scanf("%d\n", &opcao);
        switch (opcao)
        {
        case 1:
            if(PossibleMatrixSum(matriz1, matriz2)) {
                matrizResultado = MatrixAdd(matriz1, matriz2);
                MatrixPrint(matrizResultado);
                MatrixFree(matrizResultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
            break;
        case 2:
            if(PossibleMatrixSub(matriz1, matriz2)) {
                matrizResultado = MatrixSub(matriz1, matriz2);
                MatrixPrint(matrizResultado);
                MatrixFree(matrizResultado);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
            break;
        case 3:
            if(PossibleMatrixMultiply(matriz1, matriz2)) {
                matrizResultado = MatrixMultiply(matriz1, matriz2);
                MatrixPrint(matrizResultado);
                MatrixFree(matrizResultado);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
            break;
        case 4:
            int matrizEscolhida, escalar;
            scanf("%d %d\n", &escalar, &matrizEscolhida);
            if(matrizEscolhida == 1) {
                matrizResultado = MatrixMultiplyByScalar(matriz1, escalar);
                MatrixFree(matriz1);
                matriz1 = matrizResultado;
            } else {
                matrizResultado = MatrixMultiplyByScalar(matriz2, escalar);
                MatrixFree(matriz2);
                matriz2 = matrizResultado;
            }
            MatrixPrint(matrizResultado);
            break;
        case 5:
            matrizResultado = TransposeMatrix(matriz1);
            MatrixPrint(matrizResultado);
            MatrixFree(matrizResultado);
            matrizResultado = TransposeMatrix(matriz2);
            MatrixPrint(matrizResultado);
            MatrixFree(matrizResultado);
            break;
        case 6:
            flagStop = 1;
            break;
        }
    }

    MatrixFree(matriz1);
    MatrixFree(matriz2);

    return 0;
}

void ImprimeMenu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}