#include <stdio.h>
#include <stdlib.h>
#include "./jogador.h"
#include "./jogada.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador) {
    tJogador *ptrJogador;
    ptrJogador = (tJogador *) malloc(sizeof(tJogador));
    ptrJogador->id = idJogador;
    return ptrJogador;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador) {
    if(jogador != NULL) {
        free(jogador);
    }
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    int peca;
    if(jogador->id == ID_JOGADOR_1) {
        peca = PECA_1;
    } else {
        peca = PECA_2;
    }

    tJogada *jogada = CriaJogada();

    do {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);

        if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                MarcaPosicaoTabuleiro(tabuleiro, peca, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                jogada->sucesso = 1;
            } else {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                jogada->sucesso = 0;
            }
        } else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            jogada->sucesso = 0;
        }
    } while(!FoiJogadaBemSucedida(jogada));

    DestroiJogada(jogada);

}

/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    char peca;
    if(jogador->id == ID_JOGADOR_1) {
        peca = PECA_1;
    } else {
        peca = PECA_2;
    }

    // Linhas
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca)) {
        return 1;
    } else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca)) {
        return 1;
    } else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)) {
        return 1;
    } // Colunas
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca)) {
        return 1;
    } else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca)) {
        return 1;
    } else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)) {
        return 1;
    } // Diagonais
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)) {
        return 1;
    } else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca)) {
        return 1;
    }

    // Caso chegue aqui, nao venceu
    return 0;
}