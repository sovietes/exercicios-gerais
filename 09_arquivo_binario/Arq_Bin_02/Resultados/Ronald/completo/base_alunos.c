#include <stdio.h>
#include <stdlib.h>
#include "./base_alunos.h"
#include "./aluno.h"

struct BaseAlunos {
    int qtdAlunos;
    tAluno **alunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos() {
    tBaseAlunos *b = (tBaseAlunos *) malloc(sizeof(tBaseAlunos));
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos) {
    if(baseAlunos) {
        int i;
        for(i = 0; i < baseAlunos->qtdAlunos; i++) {
            DestruirAluno(baseAlunos->alunos[i]);
        }
        free(baseAlunos->alunos);

        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "rb");
    int i;

    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, fp);
    baseAlunos->alunos = (tAluno **) malloc(sizeof(tAluno *) * (baseAlunos->qtdAlunos));

    for(i = 0; i < baseAlunos->qtdAlunos; i++) {
        baseAlunos->alunos[i] = LeAluno(fp);
    }

    fclose(fp);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos) {
    float media = 0;
    int i;

    for(i = 0; i < baseAlunos->qtdAlunos; i++) {
        media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    media /= (baseAlunos->qtdAlunos);

    return media;
}