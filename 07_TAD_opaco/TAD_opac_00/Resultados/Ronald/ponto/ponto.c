#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./ponto.h"

struct ponto {
    float x;
    float y;
};

// typedef struct ponto *tPonto;

tPonto Pto_Cria (float x, float y) {
    tPonto ponto = NULL;
    ponto = (tPonto) malloc(sizeof(struct ponto));
    if(!ponto) {
        printf("erro ao alocar ponto!!\n");
        exit(0);
    }
    ponto->x = x;
    ponto->y = y;
    return ponto;
}

/**
 * @brief Apaga (Libera a memória) alocada pelo ponto
 * @param p A variável do tipo ponto que será apagada e terá sua memória liberada
 */
void Pto_Apaga (tPonto p) {
    if(p) {
        free(p);
    }
}

/**
 * @brief Função que acessa a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada x de um ponto p
 */
float Pto_Acessa_x (tPonto p) {
    return p->x;
}

/**
 * @brief Função que acessa a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada y de um ponto p
 */
float Pto_Acessa_y (tPonto p) {
    return p->y;
}

/**
 * @brief Função que atribui a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param x O novo valor da coordenada x do ponto p
 */
void Pto_Atribui_x (tPonto p, float x) {
    p->x = x;
}

/**
 * @brief Função que atribui a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param y O novo valor da coordenada y do ponto p
 */
void Pto_Atribui_y (tPonto p, float y) {
    p->y = y;
}

/**
 * @brief Função que calcula a distância euclidiana entre dois pontos: p1 e p2
 * @param p1 A variável que representa um primeiro ponto
 * @param p2 A variável que representa um segundo ponto
 * @return A distância euclidiana entre p1 e p2
 */
float Pto_Distancia (tPonto p1, tPonto p2) {
    return sqrt(pow(Pto_Acessa_y(p2)-Pto_Acessa_y(p1), 2) + pow(Pto_Acessa_x(p2)-Pto_Acessa_x(p1), 2));
}