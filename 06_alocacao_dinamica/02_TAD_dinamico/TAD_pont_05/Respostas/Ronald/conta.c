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
        DestroiConta(conta);
    }
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta) {

    // Limpando buffer
    scanf("%*[^a-zA-Z]");

    LeUsuario(conta->user);
    // Lendo o numero da conta
    scanf("%d", &conta->numero);

}