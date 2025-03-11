#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./aluno.h"

struct Aluno {
    char nome[100], dataNasc[11], curso[50];
    int periodo;
    float cra;
};

tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento) {
    tAluno *a = (tAluno *) malloc(sizeof(tAluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->cra = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno) {
    if(aluno) {
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario) {
    char nome[100], dataNasc[11], curso[50];
    int periodo;
    float cra;

    fread(nome, sizeof(char), 100, arquivo_binario);
    fread(dataNasc, sizeof(char), 11, arquivo_binario);
    fread(curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&cra, sizeof(float), 1, arquivo_binario);

    tAluno *a = CriarAluno(nome, dataNasc, curso, periodo, cra);

    return a;
} 

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno) {
    return aluno->cra;
}