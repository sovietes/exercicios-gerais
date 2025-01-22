#include <stdio.h>
#include <stdlib.h>
#include "./tabuleiro.h"

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro() {
    int i, j;
    tTabuleiro *tabuleiro;
    tabuleiro = (tTabuleiro *) malloc(sizeof(tTabuleiro));
    if(!tabuleiro) {
        exit(0);
    }

    // Criando matriz de posicoes
    tabuleiro->posicoes = (char **) malloc(TAM_TABULEIRO*sizeof(char *));
    for(i = 0; i < TAM_TABULEIRO; i++) {
        tabuleiro->posicoes[i] = (char *) malloc(TAM_TABULEIRO*sizeof(char));
    }

    // Definindo pecas
    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';

    // Definindo o mapa
    for(i = 0; i < TAM_TABULEIRO; i++) {
        for(j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
        }
    }

    return tabuleiro;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    int i;

    if(tabuleiro) {
        if(tabuleiro->posicoes) {
            for(i = 0; i < TAM_TABULEIRO; i++) {
                if(tabuleiro->posicoes[i]) {
                    free(tabuleiro->posicoes[i]);
                }
            }

            free(tabuleiro->posicoes);
        }
        free(tabuleiro);
    }


}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y) {
    char peca_c;
    if(peca == PECA_1) {
        peca_c = tabuleiro->peca1;
    } else {
        peca_c = tabuleiro->peca2;
    }

    tabuleiro->posicoes[x][y] = peca_c;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro) {
    int x, y;

    for(x = 0; x < TAM_TABULEIRO; x++) {
        for(y = 0; y < TAM_TABULEIRO; y++) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca) {
    char peca_c;
    if(peca == PECA_1) {
        peca_c = tabuleiro->peca1;
    } else {
        peca_c = tabuleiro->peca2;
    }

    if(tabuleiro->posicoes[x][y] == peca_c) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y) {
    if(tabuleiro->posicoes[x][y] == tabuleiro->pecaVazio) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y) {
    if(x >= 0 && x < TAM_TABULEIRO) {
        if(y >= 0 && y < TAM_TABULEIRO) {
            return 1;
        }
    }
    return 0;
}

/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro) {
    int i, j;

    for(i = 0; i < TAM_TABULEIRO; i++) {
        printf("\t");
        for(j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro->posicoes[j][i]);
        }
        printf("\n");
    }

}