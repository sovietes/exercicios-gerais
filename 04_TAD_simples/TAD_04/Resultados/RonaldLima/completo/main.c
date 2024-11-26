#include <stdio.h>
#include "aluno.h"

void LerEntradaAlunos(tAluno *alunos, int qtdAlunos);
void OrganizaVetorAlunos(tAluno *alunos, int qtdAlunos);
void ImprimeAlunosAprovados(tAluno *alunos, int qtdAlunos);

int main() {

    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    tAluno alunos[qtdAlunos];

    LerEntradaAlunos(alunos, qtdAlunos);
    OrganizaVetorAlunos(alunos, qtdAlunos);
    ImprimeAlunosAprovados(alunos, qtdAlunos);




    return 0;
}

void LerEntradaAlunos(tAluno *alunos, int qtdAlunos) {
    int i;
    for(i = 0; i < qtdAlunos; i++) {
        alunos[i] = LeAluno();
    }
}

void OrganizaVetorAlunos(tAluno *alunos, int qtdAlunos) {
    int i, j;
    tAluno aux;
    for(i = 0; i < qtdAlunos; i++) {
        for(j = i+1; j < qtdAlunos; j++) {
            if(ComparaMatricula(alunos[i], alunos[j]) == 1) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

void ImprimeAlunosAprovados(tAluno *alunos, int qtdAlunos) {
    int i;
    for(i = 0; i < qtdAlunos; i++) {
        if(VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
    }
}