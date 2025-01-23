#include <stdio.h>
#include <stdlib.h>
#include "./eleicao.h"

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao() {
    tEleicao *eleicao; tCandidato *candidatoVago = CriaCandidato();
    int qtdCandidatos, i;
    eleicao = (tEleicao *) malloc(sizeof(tEleicao));
    
    // Iniciando ponteiro de eleitores
    eleicao->eleitores = NULL;

    // Zerando quantidade de presidentes e governadores
    eleicao->totalGovernadores = 0;
    eleicao->totalPresidentes = 0;
    eleicao->totalEleitores = 0;

    // Zerando a quantidade de votos
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosPresidente = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosGovernador = 0;

    // Lendo qtd de candidatos
    scanf("%d", &qtdCandidatos);

    // Alocando memória para presidentes e governadores
    eleicao->governadores = (tCandidato **) malloc(qtdCandidatos*sizeof(tCandidato *));
    eleicao->presidentes = (tCandidato **) malloc(qtdCandidatos*sizeof(tCandidato *));
    
    // Lendo os candidatos e guardando nos respectivos lugares
    for(i = 0; i < qtdCandidatos; i++) {
        LeCandidato(candidatoVago);

        if(ObtemCargo(candidatoVago) == 'P') {
            eleicao->presidentes[eleicao->totalPresidentes] = CriaCandidato();
            *eleicao->presidentes[eleicao->totalPresidentes] = *candidatoVago;

            eleicao->totalPresidentes++;
        } else {
            eleicao->governadores[eleicao->totalGovernadores] = CriaCandidato();
            *eleicao->governadores[eleicao->totalGovernadores] = *candidatoVago;

            eleicao->totalGovernadores++;
        }
    }

    //Liberando o candidato vago
    if(candidatoVago) {
        free(candidatoVago);
    }

    return eleicao;
}

void ApagaEleicao(tEleicao* eleicao) {
    int i;

    if(eleicao) {
        // Apagando governadores
        if(eleicao->governadores) {
            for(i = 0; i < (eleicao->totalGovernadores); i++) {
                if(eleicao->governadores[i]) {
                    ApagaCandidato(eleicao->governadores[i]);
                }
            }
            free(eleicao->governadores);
        }

        // Apagando presidentes
        if(eleicao->presidentes) {
            for(i = 0; i < eleicao->totalPresidentes; i++) {
                if(eleicao->presidentes[i]) {
                    ApagaCandidato(eleicao->presidentes[i]);
                }
            }
            free(eleicao->presidentes);
        }

        // Apagando eleitores
        if(eleicao->eleitores) {
            for(i = 0; i < eleicao->totalEleitores; i++) {
                if(eleicao->eleitores[i]) {
                    ApagaEleitor(eleicao->eleitores[i]);
                }
            }
            free(eleicao->eleitores);
        }

        // Apagando eleicao
        free(eleicao);
    }
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao) {
    int i, j, votoValido = 0;
    scanf("%d", &eleicao->totalEleitores);
    
    // Separando espaco para os eleitores
    eleicao->eleitores = (tEleitor **) malloc((eleicao->totalEleitores)*sizeof(tEleitor *));

    //Lendo e armazenando os eleitores
    for(i = 0; i < eleicao->totalEleitores; i++) {
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);
    }

    // Contabilizando votos para governadores
    for(i = 0; i < eleicao->totalEleitores; i++) {
        votoValido = 0;
        // Procura o governador com o id votado
        for(j = 0; j < eleicao->totalGovernadores; j++) {
            if(VerificaIdCandidato(eleicao->governadores[j], ObtemVotoGovernador(eleicao->eleitores[i]))) {
                votoValido = 1;
                IncrementaVotoCandidato(eleicao->governadores[j]);
                break;
            }
        }
        // Pra caso nao tenha sido encontrado governador com o id
        if(!votoValido) {
            if(ObtemVotoGovernador(eleicao->eleitores[i]) == 0) {
                eleicao->votosBrancosGovernador++;
            } else {
                eleicao->votosNulosGovernador++;
            }
        }
    }

    // Contabilizando votos para presidentes
    for(i = 0; i < eleicao->totalEleitores; i++) {
        votoValido = 0;
        // Procura o presidente com o id votado
        for(j = 0; j < eleicao->totalPresidentes; j++) {
            if(VerificaIdCandidato(eleicao->presidentes[j], ObtemVotoPresidente(eleicao->eleitores[i]))) {
                votoValido = 1;
                IncrementaVotoCandidato(eleicao->presidentes[j]);
                break;
            }
        }
        // Pra caso nao tenha sido encontrado presidente com o id
        if(!votoValido) {
            if(ObtemVotoPresidente(eleicao->eleitores[i]) == 0) {
                eleicao->votosBrancosPresidente++;
            } else {
                eleicao->votosNulosPresidente++;
            }
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao) {
    int i, j, votosInvalidosG = 0, votosInvalidosP = 0, houveEmpate = 0;
    int totalVotosP = 0, totalVotosG = 0;

    // Definindo valores.
    votosInvalidosG = (eleicao->votosBrancosGovernador) + (eleicao->votosNulosGovernador);
    votosInvalidosP = (eleicao->votosBrancosPresidente) + (eleicao->votosNulosPresidente);
    totalVotosP = (eleicao->totalEleitores);
    totalVotosG = (eleicao->totalEleitores);

    tCandidato *maiorG = CriaCandidato(); tCandidato *maiorP = CriaCandidato();

    // Verificando se alguem votou mais de uma vez
    for(i = 0; i < eleicao->totalEleitores; i++) {
        for(j = i+1; j < eleicao->totalEleitores; j++) {
            if(EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                free(maiorG);
                free(maiorP);
                return;
            }
        }
    }

    // Verifica governador com maior qntd de votos
    for(i = 0; i < eleicao->totalGovernadores; i++) {
        if(ObtemVotos(eleicao->governadores[i]) > ObtemVotos(maiorG)) {
            *maiorG = *eleicao->governadores[i];
        }
    }

    // Verifica presidente com maior qntd de votos
    for(i = 0; i < eleicao->totalPresidentes; i++) {
        if(ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(maiorP)) {
            *maiorP = *eleicao->presidentes[i];
        }
    }

    // Imprime presidente eleito
    printf("- PRESIDENTE ELEITO: ");
    houveEmpate = 0;

    // Caso tenha empate
    for(i = 0; i < eleicao->totalPresidentes; i++) {
        if(ObtemVotos(eleicao->presidentes[i]) == ObtemVotos(maiorP)) {
            if(!EhMesmoCandidato(eleicao->presidentes[i], maiorP)) {
                houveEmpate = 1;
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                break;
            }
        }
    }

    // Caso nao tenha tido empate
    if(!houveEmpate) {
        if(ObtemVotos(maiorP) < votosInvalidosP) {
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(maiorP, CalculaPercentualVotos(maiorP, totalVotosP));
        }
    }

    // Imprime governador eleito
    printf("- GOVERNADOR ELEITO: ");
    houveEmpate = 0;

    // Caso tenha empate
    for(i = 0; i < eleicao->totalGovernadores; i++) {
        if(ObtemVotos(eleicao->governadores[i]) == ObtemVotos(maiorG)) {
            if(!EhMesmoCandidato(eleicao->governadores[i], maiorG)) {     
                houveEmpate = 1;
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                break;
            }
        }
    }

    // Caso nao tenha tido empate
    if(!houveEmpate) {
        if(ObtemVotos(maiorG) < votosInvalidosG) {
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(maiorG, CalculaPercentualVotos(maiorG, totalVotosG));
        }
    }

    free(maiorG);
    free(maiorP);

    // Nulos e brancos
    printf("- NULOS E BRANCOS: %d, %d", (eleicao->votosNulosGovernador + eleicao->votosNulosPresidente), (eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente));
}
