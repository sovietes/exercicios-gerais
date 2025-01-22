#include <stdio.h>
#include <stdlib.h>
#include "./jogo.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo() {
    tJogo *ptrJogo;
    ptrJogo = (tJogo *) malloc(sizeof(tJogo));
    if(!ptrJogo) {
        exit(0);
    }
    return ptrJogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo) {

    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo->tabuleiro = CriaTabuleiro();
    int idAtual = ID_JOGADOR_1;
    tJogador *jogadorAtual = jogo->jogador1;

    do {
        JogaJogador(jogadorAtual, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        // Para alternar os jogadores
        if(idAtual == ID_JOGADOR_1) {
            idAtual = ID_JOGADOR_2;
            jogadorAtual = jogo->jogador2;
        } else {
            idAtual = ID_JOGADOR_1;
            jogadorAtual = jogo->jogador1;
        }

        if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)) {
            printf("JOGADOR 1 Venceu!\n");
            break;
        
        } else if (VenceuJogador(jogo->jogador2, jogo->tabuleiro)) {
            printf("JOGADOR 2 Venceu!\n");
            break;
        }

    } while(!AcabouJogo(jogo));



        
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo) {
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro)) {
        printf("Sem vencedor!\n");
        return 1;
    } else {
        return 0;
    }
}

/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char c;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &c);
    if(c == 's') {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo) {
    if(jogo != NULL) {
        if(jogo->jogador1 != NULL) {
            DestroiJogador(jogo->jogador1);
        }
        if(jogo->jogador2 != NULL) {
            DestroiJogador(jogo->jogador2);
        }
        if(jogo->tabuleiro != NULL) {
            DestroiTabuleiro(jogo->tabuleiro);
        }

        free(jogo);
    }
}