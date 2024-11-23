#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;
    int peca, idJogador;
    idJogador = jogador.id;

    if(idJogador == ID_JOGADOR_1) {
        peca = PECA_1;
    } else {
        peca = PECA_2;
    }

    while(1) {
        printf("Jogador %d\n", idJogador);
        jogada = LeJogada();

        if(FoiJogadaBemSucedida(jogada)) {
            if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    break;
                } else {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            } else {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
    }



    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int venceu = 0;
    char peca;

    if(jogador.id == ID_JOGADOR_1) {
        peca = tabuleiro.peca1;
    } else {
        peca = tabuleiro.peca2;
    }
    // Verifica as linhas
    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[0][2] == peca) {
        venceu = 1;
    } else if(tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca) {
        venceu = 1;
    } else if(tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca) {
        venceu = 1;
    } // Verifica as colunas
    else if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[2][0] == peca) {
        venceu = 1;
    } else if(tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][1] == peca) {
        venceu = 1;
    } else if(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[2][2] == peca) {
        venceu = 1;
    } // Verifica as diagonais
    else if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca) {
        venceu = 1;
    } else if(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca) {
        venceu = 1;
    }

    return venceu;
}