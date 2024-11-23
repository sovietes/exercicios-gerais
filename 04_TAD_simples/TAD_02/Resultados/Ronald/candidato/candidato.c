#include "candidato.h"
#include <string.h>

//Funcao auxiliar
// void strCopy(char *origem, char *destino) {
//     int i = 0;
//     while(origem[i] != '\0') {
//         destino[i] = origem[i];
//         i++;
//     }
//     destino[i] = '\0';
// }

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);

    // strCopy(nome, candidato.nome);
    // strCopy(partido, candidato.partido);
    candidato.cargo = cargo;
    candidato.id = id;

    return candidato;
}

tCandidato LeCandidato() {
    tCandidato candidato;
    char nome[50], partido[50], cargo;
    int id;

    scanf("%*[^A-Z]");

    scanf("%[^,]", nome);
    scanf("%*c%*c");

    scanf("%[^,]", partido);
    scanf("%*c%*c");

    scanf("%c", &cargo);
    scanf("%*c%*c");

    scanf("%d", &id);

    scanf("%*[^A-Z]");

    candidato = CriaCandidato(nome, partido, cargo, id);
    // ImprimeCandidato(candidato, 10);
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id) {
    if(candidato.id == id) {
        return 1;
    } else {
        return 0;
    }
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
    if(candidato1.id == candidato2.id) {
        return 1;
    } else {
        return 0;
    }
}

char ObtemCargo(tCandidato candidato) {
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato) {
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato) {
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
    float percentual;
    percentual = (totalVotos/ObtemVotos(candidato)) * 100;
    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, ObtemVotos(candidato), percentualVotos);
}
