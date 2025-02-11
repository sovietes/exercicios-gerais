#include <stdio.h>
#include <stdlib.h>
#include "./jogada.h"

struct Jogada {
    int x;
    int y;
    int sucesso;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada() {
    tJogada *jogada = NULL;
    jogada = (tJogada *) malloc(sizeof(tJogada));
    if(!jogada) {
        printf("erro ao alocar jogada!!!\n");
        exit(0);
    }
    jogada->x = -1;
    jogada->y = -1;
    jogada->sucesso = 0;
    return jogada;
}


/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada) {
    if(jogada) {
        free(jogada);
    }
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada) {
    int retorno;
    printf("Digite uma posicao (x e y):\n");
    retorno = scanf("%d %d", &jogada->x, &jogada->y);
    if(retorno == 2) {
        jogada->sucesso = 1;
    }
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada) {
    return jogada->x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada) {
    return jogada->y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada) {
    return jogada->sucesso;
}