#include <stdio.h>
#include <stdlib.h>
#include "./banco.h"

void LimpaBuffer() {
    scanf("%*[^a-zA-Z]");
}

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco() {
    int i;
    // Criando espaco para o banco na memoria
    tBanco *banco = NULL;
    banco = (tBanco *) malloc(sizeof(tBanco));
    if(!banco) {
        printf("erro ao criar banco!");
        exit(0);
    }

    // Criando espaco para as 5 primeiras contas serem cadastradas e inicializando
    banco->contas = NULL;
    banco->contas = (tConta **) malloc(5*sizeof(tConta *));
    if(!banco->contas) {
        printf("erro ao alocar contas!");
        exit(0);
    } 

    for(i = 0; i < 5; i++) {
        banco->contas[i] = NULL;
    }

    
    // Iniciando variaveis
    banco->contasAlocadas = 5;
    banco->qtdContas = 0;

    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {
    int i = 0;
    if(banco) {
        if(banco->contas) {
            for(i = 0; i < banco->qtdContas; i++) {
                DestroiConta(banco->contas[i]);
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
    int i;
    for(i = 0; i < banco->contasAlocadas; i++) {
        if(!banco->contas[i]) {
            banco->contas[i] = CriaConta();
            LeConta(banco->contas[i]);
            // Adicionando ao numero de contas
            banco->qtdContas++;
            break;
        }
    }
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco) {
    int i, numero = 0;
    float valor;
    scanf("%d %f", &numero, &valor);

    for( i = 0; i < banco->contasAlocadas; i++) {
        if(banco->contas[i]) {
            if(VerificaConta(banco->contas[i], numero)) {
                SaqueConta(banco->contas[i], valor);
                break;
            }
        }
    }

    LimpaBuffer();
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco) {
    int i, numero = 0;
    float valor;
    scanf("%d %f", &numero, &valor);

    for( i = 0; i < banco->contasAlocadas; i++) {
        if(banco->contas[i]) {
            if(VerificaConta(banco->contas[i], numero)) {
                DepositoConta(banco->contas[i], valor);
                break;
            }
        }
    }

    LimpaBuffer();
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco) {
    int i, j, numero1 = 0, numero2 = 0;
    float valor;

    scanf("%d %d %f\n", &numero1, &numero2, &valor);
    
    for(i = 0; i < banco->contasAlocadas; i++) {
        if(!banco->contas[i]) continue; // Caso seja null, proximo

        if(VerificaConta(banco->contas[i], numero1)) { // Se achar a primeira, procura a segunda

            for(j = 0; j < banco->contasAlocadas; j++) {
                if(!banco->contas[j]) continue; // Caso seja null, proximo
                
                // Faz a transferencia se achar a segunda conta
                if(VerificaConta(banco->contas[j], numero2)) {
                    TransferenciaConta(banco->contas[i], banco->contas[j], valor);
                    break;
                }

            }

        }

    }

    LimpaBuffer();
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco) {
    int i;

    printf("===| Imprimindo Relatorio |===\n");
    for(i = 0; i < banco->contasAlocadas; i++) {
        if(banco->contas[i]) {
            ImprimeConta(banco->contas[i]);
        }
    }
}