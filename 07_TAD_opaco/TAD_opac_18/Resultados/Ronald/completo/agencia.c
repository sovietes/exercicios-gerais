#include <stdio.h>
#include <stdlib.h>
#include "./agencia.h"
#include "./operacao.h"

struct Agencia {
    tConta **contas;
    tOperacao **operacoes;
    int qtdContas;
    int qtdOperacoes;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia* CriaAgencia() {
    tAgencia *a = (tAgencia *) malloc(sizeof(tAgencia));
    if(!a) {
        printf("erro!!!\n");
        exit(1);
    }
    a->contas = NULL;
    a->operacoes = NULL;
    a->qtdContas = a->qtdOperacoes = 0;
    return a;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia* agencia) {
    if(agencia) {
        int i;
        if(agencia->contas) {
            for(i = 0; i < agencia->qtdContas; i++) {
                if(agencia->contas[i]) DestroiConta(agencia->contas[i]);
            }
            free(agencia->contas);
        }
        if(agencia->operacoes) {
            for(i = 0; i < agencia->qtdOperacoes; i++) {
                if(agencia->operacoes[i]) DestroiOperacao(agencia->operacoes[i]);
            }
            free(agencia->operacoes);
        }
        free(agencia);
    }
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia) {
    int i, id;
    float valor;
    int qtdEntradasC, qtdEntradasO;
    // Lendo qtd contas
    scanf("%d\n", &qtdEntradasC);

    // Alocando espaco
    agencia->contas = (tConta **) malloc((qtdEntradasC)*sizeof(tConta *));
    //Lendo as contas
    for(i = 0; i < qtdEntradasC; i++) {
        while(1) {
            scanf("%d\n", &id);
            if(id > 0) {
                if(BuscaContaPorId(agencia, id) == NULL) {
                    agencia->contas[i] = CriaConta(id);
                    agencia->qtdContas++;
                    break;
                } else {
                    printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
                }
            } else {
                printf("\nDigite um id valido para a conta a ser cadastrada!");
            }
        }
    }

    // Lendo qtd operacoes
    scanf("%d\n", &qtdEntradasO);
    // Alocando espaco
    agencia->operacoes = (tOperacao **) malloc((qtdEntradasO)*sizeof(tOperacao *));
    // Lendo as operacoes
    for(i = 0; i < qtdEntradasO; i++) {
        while(1) {
            scanf("%d %f\n", &id, &valor);
            if(BuscaContaPorId(agencia, id) != NULL) {
                agencia->operacoes[i] = CriaOperacao(BuscaContaPorId(agencia, id), valor);
                AlteraSaldoConta(BuscaContaPorId(agencia, id), valor);
                agencia->qtdOperacoes++;
                break;
            } else {
                printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
            }
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta* BuscaContaPorId(tAgencia *agencia, int id) {
    int i;
    for(i = 0; i < agencia->qtdContas; i++) {
        if(ConfereIdConta(agencia->contas[i], id)) {
            return agencia->contas[i];
        }
    }
    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia) {
    int i;
    printf("\nA lista de operações suspeitas:");
    for(i = 0; i < agencia->qtdOperacoes; i++) {
        if(ConsultaValorOperacao(agencia->operacoes[i]) > 20000 || ConsultaValorOperacao(agencia->operacoes[i]) < -20000) {
            ImprimeOperacao(agencia->operacoes[i]);
        }
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia) {
    tConta *ptr_conta1 = NULL, *ptr_conta2 = NULL;
    int i;
    for(i = 0; i < agencia->qtdContas; i++) {
        if(ptr_conta1 == NULL || (RetornaSaldoConta(agencia->contas[i]) > RetornaSaldoConta(ptr_conta1))) {
            ptr_conta2 = ptr_conta1;
            ptr_conta1 = agencia->contas[i];
        } else if(ptr_conta2 == NULL || (RetornaSaldoConta(agencia->contas[i]) > RetornaSaldoConta(ptr_conta2))) {
            ptr_conta2 = agencia->contas[i];
        }
    }

    printf("\nOs dois correntistas com maior saldo são:");
    printf("\nId: %d, Saldo: %.2f", RetornaIdConta(ptr_conta1), RetornaSaldoConta(ptr_conta1));
    printf("\nId: %d, Saldo: %.2f", RetornaIdConta(ptr_conta2), RetornaSaldoConta(ptr_conta2));
}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia* agencia) {
    float saldo = 0;
    int i;
    for(i = 0; i < agencia->qtdContas; i++) {
        saldo += RetornaSaldoConta(agencia->contas[i]);
    }
    printf("\nO saldo total da agencia eh: %.2f", saldo);
}