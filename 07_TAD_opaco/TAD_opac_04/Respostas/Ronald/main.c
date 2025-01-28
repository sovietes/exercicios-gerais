#include <stdio.h>
#include <stdlib.h>
#include "./aluno.h"

void OrganizaAlunos(tAluno **alunos, int qtdAlunos);

int main() {

    tAluno **alunos;
    int qtdAlunos, i;

    scanf("%d\n", &qtdAlunos);

    alunos = (tAluno **) malloc(qtdAlunos*sizeof(tAluno *));

    for(i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    OrganizaAlunos(alunos, qtdAlunos);

    for(i = 0; i < qtdAlunos; i++) {
        if(VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }

    free(alunos);

    return 0;
}

void OrganizaAlunos(tAluno **alunos, int qtdAlunos) {
    int i, j;
    tAluno *ptrAux;
    for(i = 0; i < qtdAlunos; i++) {
        for(j = i+1; j < qtdAlunos; j++) {
            if(ComparaMatricula(alunos[i], alunos[j]) > 0) {
                ptrAux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = ptrAux;
            }
        }
    }
}