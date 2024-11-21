#include "jogo.h"
#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogo CriaJogo() {
    tJogo jogo;
    tJogador jogador1;
    tJogador jogador2;
    tTabuleiro tabuleiro;

    jogador1 = CriaJogador(ID_JOGADOR_1);
    jogador2 = CriaJogador(ID_JOGADOR_2);
    tabuleiro = CriaTabuleiro();

    jogo.jogador1 = jogador1;
    jogo.jogador2 = jogador2;
    jogo.tabuleiro = tabuleiro;

    return jogo;
}

int AcabouJogo(tJogo jogo) {
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 0;
    } else {
        return 1;
    }
}

int ContinuaJogo() {
    char opcao;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%c", &opcao);
    if(opcao == 's') {
        return 1;
    } else if(opcao == 'n') {
        return 0;
    }
}

void ComecaJogo(tJogo jogo) {
    tJogador jogadorAtual;
    int idJogadorAtual = ID_JOGADOR_1;

    while(!AcabouJogo(jogo)) {
        // Caso o jogador anterior tenha vencido
        if(VenceuJogador(jogadorAtual, jogo.tabuleiro)) break;

        if(idJogadorAtual == ID_JOGADOR_1) {
            jogadorAtual = jogo.jogador1;
        } else {
            jogadorAtual = jogo.jogador2;
        }

        jogo.tabuleiro = JogaJogador(jogadorAtual, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if(idJogadorAtual == ID_JOGADOR_1) {
           idJogadorAtual = ID_JOGADOR_2;
       } else {
            idJogadorAtual = ID_JOGADOR_1;
        }
    }
        
    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
        printf("JOGADOR 1 Venceu!\n");
    } else if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
        printf("JOGADOR 2 Venceu!\n");
    } else {
        printf("Sem vencedor!\n");
    }
    
}

