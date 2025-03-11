#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./aluno.h"

struct aluno {
    char nome[100];
    char dataNasc[100];
    char cursoUfes[100];
    char periodo[100];
    int percentualConc;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos) {
    Aluno **alunos = (Aluno **) malloc(sizeof(Aluno *)*numeroAlunos);
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA) {
    Aluno *a = (Aluno *) malloc(sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->cursoUfes, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->percentualConc = percConclusao;
    a->CRA = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos) {
    int i;
    char nome[100], dataNasc[100], cursoUfes[100], periodo[100];
    int percentualConc;
    float CRA;
    for(i = 0; i < numeroAlunos; i++) {
        // Limpando buffer
        scanf("%*[^a-zA-Z]");
        // Lendo nome
        scanf("%[^\n]\n", nome);
        // Lendo data
        scanf("%[^\n]\n", dataNasc);
        // Lendo curso
        scanf("%[^\n]\n", cursoUfes);
        // Lendo periodo
        scanf("%[^\n]\n", periodo);
        // Lendo percent conclusao
        scanf("%d\n", &percentualConc);
        // Lendo CRA
        scanf("%f\n", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dataNasc, cursoUfes, periodo, percentualConc, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    int i;
    if(alunos) {
        for(i = 0; i < numeroAlunos; i++) {
            free(alunos[i]);
        }
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    int i; int tamanhoString;
    int qtdBytes = 0;
    FILE *fp;
    fp = fopen(fileName, "wb");

    // Salvando a quantidade de alunos
    qtdBytes += sizeof(int) * fwrite(&numeroAlunos, sizeof(int), 1, fp);

    // Escrevendo os alunos
    for(i = 0; i < numeroAlunos; i++) {
        // Salvando o nome
        tamanhoString = strlen(alunos[i]->nome);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->nome, sizeof(char), tamanhoString, fp);

        // Salvando a dataNascimento
        tamanhoString = strlen(alunos[i]->dataNasc);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->dataNasc, sizeof(char), tamanhoString, fp);

        // Salvando o curso
        tamanhoString = strlen(alunos[i]->cursoUfes);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->cursoUfes, sizeof(char), tamanhoString, fp);

        // Salvando o periodo
        tamanhoString = strlen(alunos[i]->periodo);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->periodo, sizeof(char), tamanhoString, fp);

        // Salvando o percentual de conclusao
        qtdBytes += (fwrite(&(alunos[i]->percentualConc), sizeof(int), 1, fp)) * sizeof(int);

        // Salvando o CRA
        qtdBytes += (fwrite(&(alunos[i]->CRA), sizeof(float), 1, fp)) * (sizeof(float));
    }
    printf("Numero de bytes salvos: %d\n", qtdBytes);
    fclose(fp);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {

    FILE *fp = fopen(fileName, "rb");
    int numAlunos, auxTamanho, i;
    char nome[100], dataNasc[100], curso[100], periodo[100];
    int prctConclusao; float CRA;

    // Preenchendo os 100 primeiros bytes com 0 que, em termos de char, equivale a \0.
    // Lembrando que se fosse int, seria diferente, pois o memset funciona apenas com bytes
    memset(nome, 0, 100);
    memset(dataNasc, 0, 100);
    memset(curso, 0, 100);
    memset(periodo, 0, 100);
    prctConclusao = 0;
    CRA = 0;

    // Lendo numero de alunos
    fread(&numAlunos, sizeof(int), 1, fp);

    for(i = 0; i < numAlunos; i++) {
        // Lendo o nome
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(nome, sizeof(char), auxTamanho, fp);

        // Lendo a data de nascimento
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(dataNasc, sizeof(char), auxTamanho, fp);

        // Lendo curso
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(curso, sizeof(char), auxTamanho, fp);

        // Lendo periodo
        fread(&auxTamanho, sizeof(int), 1, fp);
        fread(periodo, sizeof(char), auxTamanho, fp);

        // Lendo perc aprovacao
        fread(&prctConclusao, sizeof(int), 1, fp);

        // Lendo cra
        fread(&CRA, sizeof(float), 1, fp);

        alunos[i] = CriaAluno(nome, dataNasc, curso, periodo, prctConclusao, CRA);
    }

    fclose(fp);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    int i;
    for(i = 0; i < numeroAlunos; i++) {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataNasc);
        printf("Curso: %s\n", alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percentualConc);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}