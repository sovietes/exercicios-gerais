#include <stdio.h>
#include <stdlib.h>
#include "./loja.h"
#define TRUE 1

tLoja *RetornaLojaComID(tLoja **lojas, int id, int qtdLojas);

int main() {
    int qtdLojas, operacao, i;
    scanf("%d", &qtdLojas);
    // Inicializando lojas
    tLoja *lojas[qtdLojas];
    for(i = 0; i < qtdLojas; i++) {
        lojas[i] = NULL;
    }

    char nome[50];
    int id;
    float aluguel, salario, prctComissao, valorVenda;

    while(TRUE) {
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 1: // Cria loja num espaco vazio
            scanf("%d %f", &id, &aluguel);
            for(i = 0; i < qtdLojas; i++) {
                if(!lojas[i]) {
                    lojas[i] = AbreLoja(id, aluguel);
                    break;
                }
            }
            break;
        case 2: // Contrata vendedor
            scanf("%s %f %f\n", nome, &salario, &prctComissao);
            scanf("%d", &id);
            ContrataVendedor(RetornaLojaComID(lojas, id, qtdLojas), RegistraVendedor(nome, salario, prctComissao));
            break;
        case 3: // Registra venda
            scanf("%d %s %f", &id, nome, &valorVenda);
            RegistraVenda(RetornaLojaComID(lojas, id, qtdLojas), nome, valorVenda);
            break;
        case 4:
            for(i = 0; i < qtdLojas; i++) {
                if(lojas[i]) {
                    CalculaLucro(lojas[i]);
                    ImprimeRelatorioLoja(lojas[i]);
                }
            }
            break;
        case 0: // Sair do programa
            for(i = 0; i < qtdLojas; i++) {
                if(lojas[i]) {
                    ApagaLoja(lojas[i]);
                }
            }
            exit(0);
            break;
        }


    }


    return 0;
}

tLoja *RetornaLojaComID(tLoja **lojas, int id, int qtdLojas) {
    int i;
    for(i = 0; i < qtdLojas; i++) {
        if(!lojas[i]) continue;
        if(VerificaIdLoja(lojas[i], id)) {
            return lojas[i];
        }
    }
    return NULL;
}