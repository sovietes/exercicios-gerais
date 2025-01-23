#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./candidato.h"

/**
 * @brief Cria um candidato "vazio".
 * Os ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1.
 * @return Candidato criado.
 */
tCandidato* CriaCandidato() {
    tCandidato *candidato;
    candidato = (tCandidato *) malloc(sizeof(tCandidato));

    candidato->nome = NULL;
    candidato->partido = NULL;
    candidato->id = -1;
    candidato->votos = -1;

    return candidato;
}

/**
 * @brief Apaga toda a memória alocada dinamicamente para guardar as informações de um candidato
 * @param candidato Ponteiro para o candidato que terá a memória desalocada
 * @return Candidato criado.
 */
void ApagaCandidato(tCandidato* candidato) {
    if(candidato) {
        if(candidato->nome) {
            free(candidato->nome);
        }
        if(candidato->partido) {
            free(candidato->partido);
        }
        free(candidato);
    }
}

/**
 * @brief Lê um candidato. O número de votos de um candidato deve ser zerado aqui.
 * @param candidato Candidato a ser lido.
 */
void LeCandidato(tCandidato *candidato) {
    // Buffer temporario
    char buffer[100];
    // Lendo o nome
    scanf("%*[^A-Za-z]");
    scanf("%[^,]", buffer);
    candidato->nome = (char *) malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(candidato->nome, buffer);

    // Lendo o partido
    scanf("%*[^A-Za-z]");
    scanf("%[^,]", buffer);
    candidato->partido = (char *) malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(candidato->partido, buffer);

    // Lendo o cargo
    scanf("%*[^PG]");
    scanf("%c", &candidato->cargo);

    // Lendo o id
    scanf("%*[^0-9]");
    scanf("%d", &candidato->id);

    // Zerando os votos
    candidato->votos = 0;
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato *candidato, int id) {
    if(candidato->id == id) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    if(candidato1->id == candidato2->id) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato* candidato) {
    return candidato->cargo;
}

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 */
void IncrementaVotoCandidato(tCandidato* candidato) {
    candidato->votos++;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato* candidato) {
    return candidato->votos;
}

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato* candidato, int totalVotos) {
    float qtdVotosCandidato = ObtemVotos(candidato);
    float percentual = (qtdVotosCandidato/(float)totalVotos)*100;
    return percentual;
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato (tCandidato* candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato->nome, candidato->partido, ObtemVotos(candidato), percentualVotos);
}