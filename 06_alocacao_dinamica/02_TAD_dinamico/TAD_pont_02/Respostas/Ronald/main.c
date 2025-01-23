#include <stdio.h>
#include "./eleicao.h"

int main() {

    tEleicao *eleicao;
    eleicao = InicializaEleicao();
    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);

    return 0;
}