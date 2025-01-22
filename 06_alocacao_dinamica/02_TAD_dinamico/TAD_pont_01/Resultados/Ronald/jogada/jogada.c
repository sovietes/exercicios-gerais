#include <stdio.h>
#include <stdlib.h>
#include "./jogada.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada() {
    tJogada *ptrJogada;
    ptrJogada = (tJogada *) malloc(sizeof(tJogada));
    if(!ptrJogada) {
        exit(0);
    }
    ptrJogada->sucesso = 0;
    return ptrJogada;
}

/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada) {
    if(jogada != NULL) {
        free(jogada);
    } 
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada) {
    int x, y;
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d", &x, &y);

    jogada->x = x;
    jogada->y = y;
    jogada->sucesso = 1;
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