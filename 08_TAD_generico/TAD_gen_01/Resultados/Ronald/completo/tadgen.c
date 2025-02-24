#include <stdio.h>
#include <stdlib.h>
#include "./tadgen.h"

struct generic {
    void *data;
    int qtdElementos;
    Type tipo;
};

// typedef enum {
//     FLOAT = 0,
//     INT = 1
// } Type;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric *g;
    g = (tGeneric *) malloc(sizeof(tGeneric));
    g->tipo = type;

    if(type == FLOAT) {
        g->data = (float *) malloc(sizeof(float)*numElem);
    } else if(type == INT) {
        g->data = (int *) malloc(sizeof(int)*numElem);
    }
    g->qtdElementos = numElem;
    
    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {
    if(gen) {
        if(gen->data) {
            if(gen->tipo == FLOAT) {
                free((float *) gen->data);
            } else if(gen->tipo == INT) {
                free((int *) gen->data);
            }
        }
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {
    int i;

    printf("\nDigite o vetor:\n");
    for(i = 0; i < gen->qtdElementos; i++) {
        if(gen->tipo == INT) {
            scanf("%d", &((int *)gen->data)[i]);
        } else if(gen->tipo == FLOAT) {
            scanf("%f", &((float *)gen->data)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {
    int i;
    for(i = 0; i < gen->qtdElementos; i++) {
        if(gen->tipo == INT) {
            printf("%d ", ((int *)gen->data)[i]);
        } else if(gen->tipo == FLOAT) {
            printf("%.2f ", ((float *)gen->data)[i]);
        }
    }
    printf("\n");
}