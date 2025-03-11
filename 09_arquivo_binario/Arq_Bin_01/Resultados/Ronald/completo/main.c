#include <stdio.h>
#include "./aluno.h"

int main() {

    Aluno **alunos;
    int qtdAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d", &qtdAlunos);
    alunos = CriaVetorAlunos(qtdAlunos);
    LeAlunos(alunos, qtdAlunos);
    SalvaAlunosBinario(alunos, "alunos.bin", qtdAlunos);
    LiberaAlunos(alunos, qtdAlunos);

    alunos = CriaVetorAlunos(qtdAlunos);
    CarregaAlunosBinario(alunos, "alunos.bin");
    ImprimeAlunos(alunos, qtdAlunos);
    LiberaAlunos(alunos, qtdAlunos);

    return 0;
}