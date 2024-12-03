#include <stdio.h>
#include "loja.h"

tLoja EsvaziaVetorLojas(tLoja *lojas, int qtdLojas);
tLoja EsvaziaLojaIndividual();

int main() {
    int MAX_LOJAS, operacao;
    scanf("%d", &MAX_LOJAS);
    tLoja lojas[MAX_LOJAS];
    EsvaziaVetorLojas(lojas, MAX_LOJAS);


    // Limpar o buffer ate a primeira opracao
    scanf("%*[^0-9]");


    while(scanf("%d", &operacao)) {
        // Para execucao
        if(operacao == 0) break;
        
        if(operacao == 1) { // Abrir loja
            int idLoja, i; float aluguelLoja;

            // Limpar o buffer ate o id que sera lido
            scanf("%*[^0-9]");
            scanf("%d %f", &idLoja, &aluguelLoja);

            // Cadastra loja no espaco vazio do vetor
            for(i = 0; i < MAX_LOJAS; i++) {
                if(VerificaIdLoja(lojas[i], -1)) {
                    // Cadastra a loja
                    lojas[i] = AbreLoja(idLoja, aluguelLoja);
                    // Para o loop
                    break;
                }
            }

        } else if(operacao == 2) { // Contratar vendedor
            tVendedor vendedor;
            char nome[50]; float salario, prct_comissao; int idLojaContratante, i;
            // Limpar o buffer ate o nome que sera lido
            scanf("%*[^a-zA-Z]");
            scanf("%s %f %f", nome, &salario, &prct_comissao);
            vendedor = RegistraVendedor(nome, salario, prct_comissao);
            // Limpar o buffer ate o id da loja que ira contratar
            scanf("%*[^0-9]");
            scanf("%d", &idLojaContratante);

            // Registrar funcionario na loja com id especificado
            for(i = 0; i < MAX_LOJAS; i++) {
                if(VerificaIdLoja(lojas[i], idLojaContratante)) {
                    // Registra o vendedor
                    lojas[i] = ContrataVendedor(lojas[i], vendedor);
                    // Para o loop
                    break;
                }
            }

        } else if(operacao == 3) { // Registrar venda
            int idLojaVenda, i; char nomeVendedor[50]; float valorVenda;

            // Limpar o buffer ate o id da loja que vai registrar a venda
            scanf("%*[^0-9]");
            scanf("%d %s %f", &idLojaVenda, nomeVendedor, &valorVenda);

            // Procura a loja em que sera registrada a venda e contabiliza ao funcionario
            for(i = 0; i < MAX_LOJAS; i++) {
                if(VerificaIdLoja(lojas[i], idLojaVenda)) {
                    // Registra a venda para o vendedor
                    lojas[i] = RegistraVenda(lojas[i], nomeVendedor, valorVenda);
                    // Para a procura
                    break;
                }
            }
            
        } else if(operacao == 4) { // Relatorio geral
            int i;
            for(i = 0; i < MAX_LOJAS; i++) {
                // Se o espaco nao estiver vazio, calcula o lucro e imprime loja
                if(!VerificaIdLoja(lojas[i], -1)) {
                    // Calcular lucro loja
                    lojas[i] = CalculaLucro(lojas[i]);
                    // Imprime a loja
                    ImprimeRelatorioLoja(lojas[i]);
                }
            }
        }
    }


    return 0;
}

tLoja EsvaziaVetorLojas(tLoja *lojas, int qtdLojas) {
    int i;
    for(i = 0; i < qtdLojas; i++) {
        lojas[i] = EsvaziaLojaIndividual();
    }
}

tLoja EsvaziaLojaIndividual() {
    tLoja loja;
    loja.id = -1;
    return loja;
}