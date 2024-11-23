#include "eleicao.h"
#include <stdio.h>

tEleicao InicializaEleicao() {
    tEleicao eleicao; tCandidato candidatosGeral[MAX_CANDIDATOS_POR_CARGO*2];
    int qtdCandidatos, i, j;

    // Zerando votos invalidos
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    // Lendo candidatos
    scanf("%d", &qtdCandidatos);
    for(i = 0; i < qtdCandidatos; i++) {
        candidatosGeral[i] = LeCandidato();
    }

    // Separando presidentes
    for(i = 0, j = 0; i < qtdCandidatos; i++) {
        if(ObtemCargo(candidatosGeral[i]) == 'P') {
            eleicao.presidentes[j] = candidatosGeral[i];
            j++;
        }
        eleicao.totalPresidentes = j;
    }

    // Separando governadores
    for(i = 0, j = 0; i < qtdCandidatos; i++) {
        if(ObtemCargo(candidatosGeral[i]) == 'G') {
            eleicao.governadores[j] = candidatosGeral[i];
            j++;
        }
        eleicao.totalGovernadores = j;
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao) {
    int qtdEleitores, i, votoGovernador, votoPresidente;
    scanf("%d", &eleicao.totalEleitores);


    // Armazena todos os eleitores
    for(i = 0; i < eleicao.totalEleitores; i++) {
        eleicao.eleitores[i] = LeEleitor();
    }

    // Separa os votos de governador
    for(i = 0; i < eleicao.totalEleitores; i++) {
        votoGovernador = ObtemVotoGovernador(eleicao.eleitores[i]);

        if(votoGovernador == 0) {
            eleicao.votosBrancosGovernador++;
        } else if(VotoValido(votoGovernador, eleicao.governadores, eleicao.totalGovernadores)) {
            eleicao.governadores[RetornaPosicaoVetor(votoGovernador, eleicao.governadores, eleicao.totalGovernadores)] = IncrementaVotoCandidato(eleicao.governadores[RetornaPosicaoVetor(votoGovernador, eleicao.governadores, eleicao.totalGovernadores)]);
        } else {
            eleicao.votosNulosGovernador++;
        }

    }

    //Separa os votos de presidente
    for(i = 0; i < eleicao.totalEleitores; i++) {
        votoPresidente = ObtemVotoPresidente(eleicao.eleitores[i]);

        if(votoPresidente == 0) {
            eleicao.votosBrancosPresidente++;
        } else if(VotoValido(votoPresidente, eleicao.presidentes, eleicao.totalPresidentes)) {
            eleicao.presidentes[RetornaPosicaoVetor(votoPresidente, eleicao.presidentes, eleicao.totalPresidentes)] = IncrementaVotoCandidato(eleicao.presidentes[RetornaPosicaoVetor(votoPresidente, eleicao.presidentes, eleicao.totalPresidentes)]);
        } else {
            eleicao.votosNulosPresidente++;
        }

    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
    int totalNulos, totalBrancos;
    totalNulos = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
    totalBrancos = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;

    if(eleicao.totalEleitores > MAX_ELEITORES || eleicao.totalGovernadores > MAX_CANDIDATOS_POR_CARGO || eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO) {
        // Anular eleicao se tiver mais candidatos do que o possivel
        printf("ELEICAO ANULADA\n");
    } else if(HaEleitorVotandoNovamente(eleicao.eleitores, eleicao.totalEleitores)) {
        // Anular se algum eleitor votou novamente
        printf("ELEICAO ANULADA\n");
    } else {
        printf("- PRESIDENTE ELEITO: ");
        ResultadoPresidente(eleicao);
        printf("- GOVERNADOR ELEITO: ");
        ResultadoGovernador(eleicao);
        printf("- NULOS E BRANCOS: %d, %d", totalNulos, totalBrancos);
    }
}

int VotoValido(int voto, tCandidato *candidatos, int qtdCandidatos) {
    int i;
    
    for(i = 0; i < qtdCandidatos; i++) {
        if(VerificaIdCandidato(candidatos[i], voto)) {
            return 1;
        }
    }

    return 0;
}

int RetornaPosicaoVetor(int voto, tCandidato *candidatos, int qtdCandidatos) {
    int i;
    for(i = 0; i < qtdCandidatos; i++) {
        if(VerificaIdCandidato(candidatos[i], voto)) {
            return i;
        }
    }
}

int HaEleitorVotandoNovamente(tEleitor *eleitores, int qtdEleitores) {
    int i, j;
    for(i = 0; i < qtdEleitores; i++) {
        for(j = i + 1; j < qtdEleitores; j++) {
            if(EhMesmoEleitor(eleitores[i], eleitores[j])) {
                return 1;
            }
        }
    }
    return 0;
}

void ResultadoPresidente(tEleicao eleicao) {
    int maiorNumeroDeVotos = 0, i, j;
    int totalBrancosENulos;
    tCandidato candidatoMaisVotado;

    // Escolhe o maior numero de votos
    for(i = 0; i < eleicao.totalPresidentes; i++) {
        if(ObtemVotos(eleicao.presidentes[i]) > maiorNumeroDeVotos) {
            maiorNumeroDeVotos = ObtemVotos(eleicao.presidentes[i]);
            candidatoMaisVotado = eleicao.presidentes[i];
        }
    }

    // Verifica se há empate entre dois candidatos
    for(i = 0; i < eleicao.totalPresidentes; i++) {
        for(j = i + 1; j < eleicao.totalPresidentes; j++) {
            if(ObtemVotos(eleicao.presidentes[i]) == ObtemVotos(eleicao.presidentes[j])) {
                if(ObtemVotos(eleicao.presidentes[i]) == maiorNumeroDeVotos) {
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    return;
                }
            }
        }
    }

    // Verifica se tem mais votos nulos do que validos
    totalBrancosENulos = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
    if(totalBrancosENulos > maiorNumeroDeVotos) {
        printf("SEM DECISAO\n");
        return;
    }

    // Se chegar aqui, entao algum presidente ganhou
    ImprimeCandidato(candidatoMaisVotado, CalculaPercentualVotos(candidatoMaisVotado, eleicao.totalEleitores));
}

void ResultadoGovernador(tEleicao eleicao) {
    int maiorNumeroDeVotos = 0, i, j;
    tCandidato candidatoMaisVotado;
    int totalBrancosENulos;


    // Escolhe o maior numero de votos
    for(i = 0; i < eleicao.totalGovernadores; i++) {
        if(ObtemVotos(eleicao.governadores[i]) > maiorNumeroDeVotos) {
            maiorNumeroDeVotos = ObtemVotos(eleicao.governadores[i]);
            candidatoMaisVotado = eleicao.governadores[i];
        }
    }

    // Verifica se há empate entre dois candidatos
    for(i = 0; i < eleicao.totalGovernadores; i++) {
        for(j = i + 1; j < eleicao.totalGovernadores; j++) {
            if(ObtemVotos(eleicao.governadores[i]) == ObtemVotos(eleicao.governadores[j])) {
                if(ObtemVotos(eleicao.governadores[i]) == maiorNumeroDeVotos) {
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    return;
                }
            }
        }
    }

    // Verifica se tem mais votos nulos do que validos
    totalBrancosENulos = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;
    if(totalBrancosENulos > maiorNumeroDeVotos) {
        printf("SEM DECISAO\n");
        return;
    }

    // Se chegar aqui, entao algum governador ganhou
    ImprimeCandidato(candidatoMaisVotado, CalculaPercentualVotos(candidatoMaisVotado, eleicao.totalEleitores));
}