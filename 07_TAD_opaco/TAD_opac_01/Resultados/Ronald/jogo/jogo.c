#include <stdio.h>
#include <stdlib.h>
#include "./jogo.h"

struct Jogo {
    tJogador *jogador1;
    tJogador *jogador2;
    tTabuleiro *tabuleiro;
};

void RealizaJogo(tJogo *jogo);

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo() {
    tJogo *j = NULL;
    j = (tJogo *) malloc(sizeof(tJogo));
    if(!j) {
        printf("erro ao alocar o jogo!!!\n");
        exit(0);
    }

    return j;
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

    RealizaJogo(jogo);
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
    char op;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &op);
    return (op == 's' ? 1 : 0);
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo) {
    if(jogo) {
        if(jogo->jogador1) DestroiJogador(jogo->jogador1);
        if(jogo->jogador2) DestroiJogador(jogo->jogador2);
        if(jogo->tabuleiro) DestroiTabuleiro(jogo->tabuleiro);
        free(jogo);
    }
}

void RealizaJogo(tJogo *jogo) {
    int idJogador = 0;
    tJogador *jogadorRodada;
    
    do {
        idJogador = idJogador == ID_JOGADOR_1 ? ID_JOGADOR_2 : ID_JOGADOR_1;
        jogadorRodada = idJogador == ID_JOGADOR_1 ? jogo->jogador1 : jogo->jogador2;
        JogaJogador(jogadorRodada, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
    } while(!AcabouJogo(jogo) && !VenceuJogador(jogadorRodada, jogo->tabuleiro));

    if(VenceuJogador(jogadorRodada, jogo->tabuleiro)) {
        printf("JOGADOR %d Venceu!\n", idJogador);
    } else {
        printf("Sem vencedor!\n");
    }
}