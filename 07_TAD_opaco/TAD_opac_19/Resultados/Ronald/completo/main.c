#include <stdio.h>
#include "./cidade.h"


int main() {
    tCidade cidade;
    cidade = CriaCidade();
    
    cidade = LeEntrada(cidade);
    ProcessaAtaques(cidade);
    ImprimeDados(cidade);
    LiberaCidade(cidade);
}