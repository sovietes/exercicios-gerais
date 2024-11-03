#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);
int ehPar(int num);
void LeVetor(int *vet, int qtd);
void ImprimeVetor(int vet[], int tam);

int main() {
    int qtdVetores, i, qtdElementos;
    scanf("%d", &qtdVetores);
    
    for(i = 0; i < qtdVetores; i++) {
        scanf("%d", &qtdElementos);

        int vetor[qtdElementos];
        LeVetor(vetor, qtdElementos);

        printf("%d\n", SomaElementosPares(vetor, qtdElementos));
    }
}


void LeVetor(int *vet, int qtd) {
    int i = 0;
    for(i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}

int SomaElementosPares(int* vet, int numElementos) {
    int i = 0;
    if(numElementos == 0) {
        return 0;
    } else {
        if(ehPar(vet[0])) {
            return vet[0] + SomaElementosPares(vet+1, numElementos-1);
        } else {
            return SomaElementosPares(vet+1, numElementos-1);
        }
    }
}

int ehPar(int num) {
    if(num%2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void ImprimeVetor(int vet[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}