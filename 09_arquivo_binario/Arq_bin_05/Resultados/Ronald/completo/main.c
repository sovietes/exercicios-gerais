#include <stdio.h>
#include <stdlib.h>
#include "./estabelecimento.h"

int main() {
    tEstabelecimento *estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(estabelecimento);
    ImprimeProdutosEmFaltaEstabelecimento(estabelecimento);
    DestroiEstabelecimento(estabelecimento);
    return 0;
}