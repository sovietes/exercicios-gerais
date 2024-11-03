#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);
void LerVetor(int *vet, int qtd);

int main() {
    int qtdCasos, numeroProcurado, qtdElementos, i;
    scanf("%d", &qtdCasos); 

    for(i = 0; i < qtdCasos; i++) {
        scanf("%d %d", &numeroProcurado, &qtdElementos);

        int vet[qtdElementos];
        LerVetor(vet, qtdElementos);

        printf("%d\n", ContaOcorrencias(vet, qtdElementos, numeroProcurado));
    }


    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    if(numElementos == 0) {
        return 0;
    } else {
        if(numeroProcurado == vet[0]) {
            return 1 + ContaOcorrencias(vet+1, numElementos-1, numeroProcurado);
        } else {
            ContaOcorrencias(vet+1, numElementos-1, numeroProcurado);
        }
    }
}

void LerVetor(int *vet, int qtd) {
    int i;
    for(i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}