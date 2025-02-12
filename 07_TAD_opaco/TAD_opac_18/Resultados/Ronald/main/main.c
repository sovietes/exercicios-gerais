#include <stdio.h>
#include "./agencia.h"

int main() {
    tAgencia *agencia;
    agencia = CriaAgencia();
    printf("--- Agencia Bancaria ---");
    LeOperacoes(agencia);
    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);
    DestroiAgencia(agencia);
}