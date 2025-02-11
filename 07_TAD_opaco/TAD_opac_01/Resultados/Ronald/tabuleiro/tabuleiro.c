#include <stdio.h>
#include <stdlib.h>
#include "./tabuleiro.h"

struct Tabuleiro {
    char **posicoes;
    char peca1;
    char peca2;
    char pecaVazio;
};

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro() {
    int i, j;
    tTabuleiro *t = NULL;
    t = (tTabuleiro *) malloc(sizeof(tTabuleiro));
    if(!t) {
        printf("erro ao alocar tabuleiro!!\n");
        exit(0);
    }

    t->peca1 = 'X';
    t->peca2 = '0';
    t->pecaVazio = '-'; 
    // Criando tabuleiro no heap
    t->posicoes = (char **) malloc(TAM_TABULEIRO*sizeof(char *));
    for(i = 0; i < TAM_TABULEIRO; i++) {
        t->posicoes[i] = (char *) malloc(TAM_TABULEIRO*sizeof(char));
    }
    // Preenchendo tabuleiro com pecas vazias
    for(i = 0; i < TAM_TABULEIRO; i++) {
        for(j = 0; j < TAM_TABULEIRO; j++) {
            t->posicoes[i][j] = t->pecaVazio;
        }
    }

    return t;
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
                free(tabuleiro->posicoes[i]);
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
    peca_c = peca == PECA_1 ? tabuleiro->peca1 : tabuleiro->peca2;

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
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++) {
        for(j = 0; j < TAM_TABULEIRO; j++) {
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio) {
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
    peca_c = peca == PECA_1 ? tabuleiro->peca1 : tabuleiro->peca2;
    return (tabuleiro->posicoes[x][y] == peca_c ? 1 : 0);
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
    return (tabuleiro->posicoes[x][y] == tabuleiro->pecaVazio ? 1 : 0);
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