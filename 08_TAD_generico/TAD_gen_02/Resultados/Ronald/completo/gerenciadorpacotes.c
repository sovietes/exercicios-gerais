#include <stdio.h>
#include <stdlib.h>
#include "./gerenciadorpacotes.h"

#define QTD_PADRAO_PACOTES 5

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtdPacotes;
    int qtdPacotesAlocados;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador() {
    tGerenciador *gerenciador = (tGerenciador *) malloc(sizeof(tGerenciador));
    if(!gerenciador) {
        printf("erro ao alocar gerenciador!\n");
        exit(0);
    }

    gerenciador->pacotes = (tPacote **) malloc(sizeof(tPacote *)*QTD_PADRAO_PACOTES);
    gerenciador->qtdPacotes = 0;
    gerenciador->qtdPacotesAlocados = 5;

    return gerenciador;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    if(geren->qtdPacotes == geren->qtdPacotesAlocados) {
        geren->qtdPacotesAlocados *= 2;
        geren->pacotes = (tPacote **) realloc(geren->pacotes, sizeof(tPacote *)*(geren->qtdPacotesAlocados));
    }

    geren->pacotes[geren->qtdPacotes] = pac;
    geren->qtdPacotes++;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren) {
    if(geren) {
        if(geren->pacotes) {
            int i;
            for(i = 0; i < geren->qtdPacotes; i++) {
                DestroiPacote(geren->pacotes[i]);
            }
            free(geren->pacotes);
        }
        free(geren);
    }
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    ImprimePacote(geren->pacotes[idx]);
}

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren) {
    int i;
    for(i = 0; i < geren->qtdPacotes; i++) {
        ImprimirPacoteNoIndice(geren, i);
    }
}