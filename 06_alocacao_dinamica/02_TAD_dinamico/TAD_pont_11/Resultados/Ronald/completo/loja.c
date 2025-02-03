#include <stdio.h>
#include <stdlib.h>
#include "./loja.h"

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja* AbreLoja(int id, float aluguel) {
    int i;
    tLoja *loja = NULL;
    loja = (tLoja *) malloc(sizeof(tLoja));
    if(!loja) {
        printf("erro ao alocar loja!!\n");
        exit(0);
    }

    loja->id = id;
    loja->totalVendedores = 0;
    loja->maxVendedores = 10;
    loja->aluguel = aluguel;
    loja->lucro = 0;

    // Criando vetor vendedores
    loja->vendedores = (tVendedor **) malloc((loja->maxVendedores)*sizeof(tVendedor *));
    for(i = 0; i < loja->maxVendedores; i++) {
        loja->vendedores[i] = NULL;
    }

    return loja;
}

/**
 * @brief Libera a memória alocada para uma loja.
 * 
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja* loja) {
    if(loja) {
        if(loja->vendedores) {
            int i;
            for(i = 0; i < loja->maxVendedores; i++) {
                if(loja->vendedores[i]) {
                    ApagaVendedor(loja->vendedores[i]);
                }
            }
            free(loja->vendedores);
        }
        free(loja);
    }
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id) {
    if(loja->id == id) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor) {
    if(loja->totalVendedores < loja->maxVendedores) {
        int i;
        for(i = 0; i < loja->maxVendedores; i++) {
            if(!loja->vendedores[i]) {
                loja->vendedores[i] = vendedor;
                loja->totalVendedores++;
                return;
            }
        }
    }
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor) {
    int i;
    for(i = 0; i < loja->maxVendedores; i++) {
        // Se for null, pula
        if(!loja->vendedores[i]) continue;

        if(VerificaNomeVendedor(loja->vendedores[i], nome)) {
            ContabilizaVenda(loja->vendedores[i], valor);
            return;
        }
    }
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
void CalculaLucro(tLoja* loja) {
    int totalVendido = 0;
    int gastoSalarios = 0;
    int i;
    for(i = 0; i < loja->maxVendedores; i++) {
        if(loja->vendedores[i]) {
            totalVendido += GetTotalVendido(loja->vendedores[i]);
            gastoSalarios += GetTotalRecebido(loja->vendedores[i]);
        }
    }

    loja->lucro = totalVendido - (gastoSalarios + loja->aluguel);
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja* loja) {
    int i;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for(i = 0; i < loja->maxVendedores; i++) {
        if(loja->vendedores[i]) {
            ImprimeRelatorioVendedor(loja->vendedores[i]);
        }
    }
}