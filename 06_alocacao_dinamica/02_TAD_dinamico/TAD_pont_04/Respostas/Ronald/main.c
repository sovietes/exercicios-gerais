#include <stdio.h>
#include <stdlib.h>
#include "./aluno.h"

int main() {
    tAluno **alunos = NULL;
    int qtdAlunos = 0, i;

    scanf("%d", &qtdAlunos);
    alunos = (tAluno **) malloc(qtdAlunos*sizeof(tAluno*));

    for(i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    OrdenaAlunos(alunos, qtdAlunos);

    for(i = 0; i < qtdAlunos; i++) {
        if(VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }

    free(alunos);

    return 0;
}

void OrdenaAlunos(tAluno **alunos, int qtdAlunos) {
    tAluno *ptrAux;
    int i, j;
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
