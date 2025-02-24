#include <stdio.h>
#include <stdlib.h>
#include "./pacote.h"

struct pacote {
    void *data;
    int numElem;
    int somaPct;
    Type tipo;
};


/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem) {
    tPacote *pct = (tPacote *) malloc(sizeof(tPacote));
    if(!pct) {
        printf("erro ao alocar pacote!!!\n");
        exit(0);
    }
    pct->tipo = type;
    pct->numElem = numElem;
    pct->somaPct = 0;

    switch (type)
    {
    case CHAR:
        pct->data = (char *) malloc(sizeof(char)*numElem);
        break;
    case INT:
        pct->data = (int *) malloc(sizeof(int)*numElem);
        break;
    }

    return pct;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac) {
    if(pac) {
        if(pac->data) {
            free(pac->data);
        }
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac) {
    int i;

    printf("\nDigite o conteúdo do vetor/mensagem:");
    scanf("%*[^a-zA-Z0-9]");

    char caractere;
 
    for(i = 0; i < pac->numElem; i++) {
        switch (pac->tipo)
        {
        case CHAR:
            scanf("%c", &((char *)pac->data)[i]);
            // Se ler um \n antes de terminar a quantidade, para a funcao
            if(((char *)pac->data)[i] == '\n') {
                ((char *)pac->data)[i] = '\0';
                pac->numElem = i;
            }
            break;
        case INT:
            scanf("%d", &((int *)pac->data)[i]);
            break;
        }
    }

    scanf("%*[\n]");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac) {
    int i;

    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaPct);

    for(i = 0; i < pac->numElem; i++) {
        if(pac->tipo == INT) {
            printf("%d", ((int *)pac->data)[i]);
            i == (pac->numElem-1) ? printf("") : printf(" "); 
        } else if(pac->tipo == CHAR) {
            printf("%c", ((char *)pac->data)[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac) {
    int i;
    for(i = 0; i < pac->numElem; i++) {
        if(pac->tipo == INT) {
            pac->somaPct += ((int *)pac->data)[i];
        } else if(pac->tipo == CHAR) {
            pac->somaPct += (int)(((char *)pac->data)[i]);
        }
    }
}