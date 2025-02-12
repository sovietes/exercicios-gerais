#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./defesa.h"

struct defesa {
    char nome[MAX_TAM];
    char tipo;
    float x, y;
    float tamanho;
    float poder;
    int quantidade;
};

double CalculaDistPontos(double x1, double y1, double x2, double y2);

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa() {
    tDefesa d = (tDefesa) malloc(sizeof(struct defesa));
    if(!d) {
        printf("erro!!!\n");
        exit(1);
    }

    scanf("%s %f %f %c %f %f %d", d->nome, &d->x, &d->y, &d->tipo, &d->tamanho, &d->poder, &d->quantidade);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa) {
    printf("D-%s: %d\n", defesa->nome, defesa->quantidade);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa) {
    if(defesa) {
        free(defesa);
    }
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y) {
    float distPontos;
    distPontos = CalculaDistPontos(defesa->x, defesa->y, x, y);

    return ((distPontos > defesa->tamanho) ? 0 : 1);
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa) {
    defesa->quantidade--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa) {
    return defesa->poder;
}

/**
 * @brief Verifica se a defesa pode defender.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa) {
    return (defesa->quantidade > 0 ? 1 : 0);
}


double CalculaDistPontos(double x1, double y1, double x2, double y2) {
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1,2));
}