#include <stdio.h>
#include <stdlib.h>
#include "./conta.h"

#define TAM_MAX_NOME 100

struct Conta {
    int numero;
    float saldo;
    char nome[TAM_MAX_NOME];
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta() {
    tConta *c = (tConta *) malloc(sizeof(tConta));
    c->numero = c->saldo = 0;
    return c;
}

void DestroiChar(DataType dado) {
    if(dado) {
        free((char *)dado);
    }
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta) {
    scanf("%*[^0-9]");
    scanf("%d;", &conta->numero);

    scanf("%[^;];", conta->nome);
    // char c;

    // while(1) {
    //     scanf("%c", &c);
    //     if(c == ';') {
    //         char *finalizador = malloc(sizeof(char));
    //         *finalizador = '\0';
    //         VectorPushBack(conta->nome, finalizador);
    //         break;
    //     } else {
    //         char *novoCaractere = malloc(sizeof(char));
    //         *novoCaractere = c;
    //         VectorPushBack(conta->nome, novoCaractere);
    //     }
    // }

    scanf("%f\n", &conta->saldo);
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta) {
    if(conta) {
        free(conta);
    }
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta) {
    return conta->saldo;
}
