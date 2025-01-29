#include <stdio.h>
#include <stdlib.h>
#include "./conta.h"

/**
 * @brief Cria uma nova conta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta() {
    tConta *conta = NULL;
    conta = (tConta *) malloc(sizeof(tConta));

    if(!conta) {
        printf("erro ao alocar conta!!");
        exit(0);
    }

    conta->saldo = 0;
    conta->user = CriaUsuario();

    return conta;
}

/**
 * @brief Desaloca a memória de uma conta.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta) {
    if(conta) {
        if(conta->user) {
            DestroiUsuario(conta->user);
        }
        free(conta);
    }
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta) {
    // Limpando o comeco do buffer
    scanf("%*[^a-zA-Z]");

    LeUsuario(conta->user);

    // Limpando buffer
    scanf("%*[^0-9]");

    // Lendo o numero da conta
    scanf("%d", &conta->numero);

    // Limpando o restante da linha
    scanf("%*[^\n]");
    scanf("%*c");
}

/**
 * @brief Imprime os dados de uma conta e do proprietário.
 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero) {
    if(conta->numero == numero) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor) {
    if(valor <= conta->saldo) {
        conta->saldo -= valor;
    }
}

/**
 * @brief Realiza um depósito em uma conta.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if(origem->saldo >= valor) {
        SaqueConta(origem, valor);
        DepositoConta(destino, valor);
    }
}