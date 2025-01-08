#include <stdio.h>
#include "./pessoa.h"

int main() {

    int qtdPessoas, i;
    scanf("%d", &qtdPessoas);
    tPessoa pessoas[qtdPessoas];

    // Inicializando vetor
    for(i = 0; i < qtdPessoas; i++) {
        *(pessoas+i) = CriaPessoa();
    }
    // Lendo as pessoas
    for(i = 0; i < qtdPessoas; i++) {
        LePessoa(pessoas+i);
    }

    AssociaFamiliasGruposPessoas(pessoas);
    // Imprimindo vetor
    for(i = 0; i < qtdPessoas; i++) {
        ImprimePessoa(pessoas+i);
    }

    return 0;
}