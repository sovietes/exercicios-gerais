#include <stdio.h>
#include <stdlib.h>
#include "./missil.h"

struct missil {
    char nome[MAX_TAM];
    float x, y;
    float poder;
};

/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil() {
    tMissil m = (tMissil) malloc(sizeof(struct missil));
    if(!m) {
        printf("erro!!!\n");
        exit(1);
    }

    scanf("%s %f %f %f", m->nome, &m->x, &m->y, &m->poder);
    return m;
}

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil) {
    printf("M-%s: %.2f\n", missil->nome, missil->poder);
}

/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil) {
    if(missil) {
        free(missil);
    }
}

/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil) {
    return missil->y;
}

/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil) {
    return missil->x;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil) {
    return missil->poder;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor) {
    missil->poder -= valor;
    if(missil->poder < 0) {
        missil->poder = 0;
    }
}