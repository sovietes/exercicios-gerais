#include <stdio.h>
#include "./base_alunos.h"

int main() {
    tBaseAlunos *base = CriarBaseAlunos();

    char enderecoArquivo[100];
    scanf("%[^\n]", enderecoArquivo);

    LerBaseAlunos(base, enderecoArquivo);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;
}