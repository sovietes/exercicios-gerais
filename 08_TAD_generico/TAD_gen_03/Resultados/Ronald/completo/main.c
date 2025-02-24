#include <stdio.h>
#include <stdlib.h>
#include "./relatorio.h"
#include "./aluno.h"

int main() {
    int qtdAlunos, i;
    Vector *alunos;

    tAluno *aluno;
    alunos = VectorConstruct();
    scanf("%d\n", &qtdAlunos);

    for(i = 0; i < qtdAlunos; i++) {
        aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos, aluno);
    }

    ImprimeRelatorio(alunos);
    VectorDestroy(alunos, DestroiAluno);

    return 0;
}