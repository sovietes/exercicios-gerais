#include <stdio.h>
#include <stdlib.h>
#include "./vector.h"

struct Vector {
    data_type *data;
    int tamanho;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    v->data = NULL;
    v->tamanho = 0;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val) {
    v->tamanho++;
    v->data = (data_type *) realloc(v->data, sizeof(data_type)*v->tamanho);
    v->data[v->tamanho-1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i) {
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    int i;
    if(v) {
        if(v->data) {
            for(i = 0; i < v->tamanho; i++) {
                destroy(v->data[i]);
            }
            free(v->data);
        }
        free(v);
    }
}