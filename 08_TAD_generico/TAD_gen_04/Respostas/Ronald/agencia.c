#include <stdio.h>
#include <stdlib.h>
#include "./agencia.h"

#define TAM_MAX_NOME 100

struct Agencia {
    int id;
    char nome[TAM_MAX_NOME];
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia() {
    tAgencia *a = (tAgencia *) malloc(sizeof(tAgencia));
    a->contas = VectorConstruct();
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia) {
    if(agencia) {
        if(((tAgencia *)agencia)->contas) {
            VectorDestroy(((tAgencia *)agencia)->contas, DestroiConta);
        }
        free(agencia);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia) {
    scanf("%d;%[^\n]\n", &agencia->id, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta) {
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    if(agencia2->id == numAgencia) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia) {
    int i;
    float saldo = 0;
    for(i = 0; i < VectorSize(agencia->contas); i++) {
        saldo += GetSaldoConta(VectorGet(agencia->contas, i));
    }
    saldo /= VectorSize(agencia->contas);
    return saldo;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->id);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}