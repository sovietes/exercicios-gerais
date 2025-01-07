#include "./utils.h"
#include <stdio.h>

/**
 * @brief Lê do usuário um intervalo de números inteiros.
 * 
 * Esta função recebe como parâmetro dois ponteiros para inteiros e lê do usuário os valores correspondentes ao início e fim de um intervalo.
 * 
 * @param m Ponteiro para a variável que receberá o valor do início do intervalo.
 * @param n Ponteiro para a variável que receberá o valor do fim do intervalo.
 */
void LeIntervalo(int * m, int * n) {
    scanf("%d %d", m, n);
}

int EhPrimo(int n) {
    int i = 1, cont = 0;
    while(i <= n) {
        if(n%i == 0) cont++;
        i++;
    }

    if(cont == 2) {
        return 1;
    } else {
        return 0;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
    *menor = n; *maior = m;
    while(m <= n) {
        if(EhPrimo(m)) {
            if(m < *menor) {
                *menor = m;
            }
            if(m > *maior) {
                *maior = m;
            }
        }
        m++;
    }
}
