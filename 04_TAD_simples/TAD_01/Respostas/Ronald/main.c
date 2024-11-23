#include <stdio.h>
#include "jogo.h"

int main() {
    tJogo jogo;
    int queroJogar = 1;
    jogo = CriaJogo();

    do {
        ComecaJogo(jogo);
        queroJogar = ContinuaJogo();
    } while(queroJogar);

    return 0;
}