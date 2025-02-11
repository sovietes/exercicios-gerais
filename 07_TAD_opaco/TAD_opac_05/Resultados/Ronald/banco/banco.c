#include <stdio.h>
#include <stdlib.h>
#include "./banco.h"
#include "./conta.h"

#define QTD_MIN_CONTAS 5

struct Banco {
    tConta **contas;
    int qtdContas;
    int qtdContasAlocadas;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco() {
    tBanco *b;
    b = (tBanco *) malloc(sizeof(tBanco));
    if(!b) {
        exit(1);
    }
    b->contas = (tConta **) malloc(QTD_MIN_CONTAS*sizeof(tConta *));
    b->qtdContas = 0;
    b->qtdContasAlocadas = 5;
    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {
    if(banco) {
        if(banco->contas) {
            int i;
            for(i = 0; i < banco->qtdContas; i++) {
                if(banco->contas[i]) {
                    DestroiConta(banco->contas[i]);
                }
            }
            free(banco->contas);
        }
        free(banco);
    }
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco) {
    if(banco->qtdContas == banco->qtdContasAlocadas) {
        banco->contas = (tConta **) realloc(banco->contas, (QTD_MIN_CONTAS+banco->qtdContasAlocadas)*sizeof(tConta *));
        banco->qtdContasAlocadas += QTD_MIN_CONTAS;
    }

    tConta *conta = CriaConta();

    
    LeConta(conta);

    
    banco->contas[banco->qtdContas] = conta;
    banco->qtdContas++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco) {
    int numero, valor, i;
    scanf("%d %d\n", &numero, &valor);

    for(i = 0; i < banco->qtdContas; i++) {
        if(VerificaConta(banco->contas[i], numero)) {
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco) {
    int numero, valor, i;
    scanf("%d %d\n", &numero, &valor);

    for(i = 0; i < banco->qtdContas; i++) {
        if(VerificaConta(banco->contas[i], numero)) {
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco) {
    int contaOrigem, contaDestino, valor, i, j;
    scanf("%d %d %d\n", &contaOrigem, &contaDestino, &valor);

    for(i = 0; i < banco->qtdContas; i++) {
        if(VerificaConta(banco->contas[i], contaOrigem)) {
            for(j = 0; j < banco->qtdContas; j++) {
                if(VerificaConta(banco->contas[j], contaDestino)) {
                    TransferenciaConta(banco->contas[i], banco->contas[j], valor);
                    break;
                }
            }
        }
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco) {
    int i;
    printf("===| Imprimindo Relatorio |===\n");
    for(i = 0; i < banco->qtdContas; i++) {
        ImprimeConta(banco->contas[i]);
    }
}