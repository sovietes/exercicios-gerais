#include <stdio.h>
#include <stdlib.h>
#include "./array.h"

void ImprimeArray(Array *array);

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray() {
    Array *array = NULL;
    array = (Array *) malloc(sizeof(Array));
    if(!array) {
        printf("erro ao alocar array!!\n");
        exit(0);
    }
    array->data = NULL;
    array->tamanho = 0;
    return array;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array) {
    if(array) {
        if(array->data) {
            free(array->data);
        }
        free(array);
    }
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array) {
    int entrada;
    while(scanf("%d", &entrada) == 1) {
        array->tamanho++;
        array->data = (int *) realloc(array->data, sizeof(int)*(array->tamanho));
        array->data[(array->tamanho)-1] = entrada;
    }
    scanf("%*[^0-9]");
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array) {
    int i, j, aux;
    for(i = 0; i < array->tamanho; i++) {
        for(j = i+1; j < array->tamanho; j++) {
            if(array->data[i] > array->data[j]) {
                aux = array->data[i];
                array->data[i] = array->data[j];
                array->data[j] = aux;
            }
        }
    }
}

void ImprimeArray(Array *array) {
    int i, j;
    for(i = 0; i < array->tamanho; i++) {
        printf("%d ", array->data[i]);
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int indiceMeio = (array->tamanho)/2;
    while(array->tamanho > 0) {
        if(array->data[indiceMeio] == elementoBuscado) {
            return indiceMeio;
        } else if(array->data[indiceMeio] > elementoBuscado) {
            // Tira metade do tamanho, so quero os da esquerda
            array->tamanho /= 2;
            indiceMeio -= (array->tamanho / 2);
        } else if(array->data[indiceMeio] < elementoBuscado) {
            // Quero avancar no array e dividir o tamanho
            array->tamanho /= 2;
            indiceMeio += (array->tamanho / 2);
        }
    }
    return -1;
}