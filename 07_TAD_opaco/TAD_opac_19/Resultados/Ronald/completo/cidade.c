#include <stdio.h>
#include <stdlib.h>
#include "./cidade.h"
#include "./missil.h"
#include "./defesa.h"

struct cidade {
    char nome[MAX_NOME];
    int qtdMisseis, qtdDefesas;
    tMissil misseis[QTD_MIS];
    tDefesa defesas[QTD_DEF];
    float maxX, maxY;
    float totalMitigado;
};

/**
 * @brief Cria uma nova cidade.
 * 
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade CriaCidade() {
    tCidade c;
    c = (tCidade) malloc(sizeof(struct cidade));
    if(!c) {
        printf("erro!!\n");
        exit(1);
    }
    c->qtdDefesas = 0;
    c->qtdMisseis = 0;
    c->maxX = 0;
    c->maxY = 0;
    c->totalMitigado = 0;
    return c;
}

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 * 
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
tCidade LeEntrada(tCidade cidade) {

    scanf("%*[^0-9]");

    scanf("%f %f", &cidade->maxX, &cidade->maxY);

    // Limpando buffer
    scanf("%*[^\n]");
    scanf("%*c");

    char aux;

    // Lendo misseis e defesas
    while (1)
    {   
        scanf("%c", &aux);
        switch (aux)
        {
        case DEFESA:
            cidade->defesas[cidade->qtdDefesas] = LeDefesa();
            cidade->qtdDefesas++;
            break;
        case MISSIL:
            cidade->misseis[cidade->qtdMisseis] = LeMissil();
            cidade->qtdMisseis++;
            break;
        case ENCERRAR:
            return cidade;
        }

        // Limpando buffer
        scanf("%*[^\n]");
        scanf("%*c");
    }
}

/**
 * @brief Imprime as informações da cidade.
 * 
 * @param cidade Ponteiro para a cidade que será impressa.
 */
void ImprimeCidade(tCidade cidade) {
    int i;

    for(i = 0; i < cidade->qtdDefesas; i++) {
        ImprimeDefesa(cidade->defesas[i]);
    }

    for(i = 0; i < cidade->qtdMisseis; i++) {
        ImprimeMissil(cidade->misseis[i]);
    }
}

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade) {
    if(cidade) {
        int i;
        for(i = 0; i < cidade->qtdMisseis; i++) {
            if(cidade->misseis[i]) {
                LiberaMissil(cidade->misseis[i]);
            }
        }
        for(i = 0; i < cidade->qtdDefesas; i++) {
            if(cidade->defesas[i]) {
                LiberaDefesa(cidade->defesas[i]);
            }
        }
        free(cidade);
    }
}

/**
 * @brief Processa os ataques na cidade.
 * 
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade cidade) {
    int i, j;
    for(i = 0; i < cidade->qtdMisseis; i++) {
        float xMissil = GetMissilX(cidade->misseis[i]), yMissil = GetMissilY(cidade->misseis[i]);
        // Missil pra fora cidade
        if(xMissil > cidade->maxX || yMissil > cidade->maxY) {
            continue;
        }

        cidade->totalMitigado += GetMissilPoder(cidade->misseis[i]);

        // Se defendendo dos misseis
        for(j = 0; j < cidade->qtdDefesas; j++) {

            if(VerificaSeDentroArea(cidade->defesas[j], xMissil, yMissil)) {
                if(PodeDefender(cidade->defesas[j])) {
                    UsaDefesa(cidade->defesas[j]);
                    ReduzPoder(cidade->misseis[i], GetDefesaPoder(cidade->defesas[j]));
                }
            }

        }

        cidade->totalMitigado -= GetMissilPoder(cidade->misseis[i]);
    }
}

/**
 * @brief Imprime os dados finais da cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade) {
    int i;
    float totalAtaque = 0;
    for(i = 0; i < cidade->qtdMisseis; i++) {
        totalAtaque += GetMissilPoder(cidade->misseis[i]);
    }
    totalAtaque += cidade->totalMitigado;

    ImprimeCidade(cidade);
    printf("Efetividade: %.2f%%", (cidade->totalMitigado/totalAtaque)*100);
    
}