#include "loja.h"

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;
    int i;
    loja.id = id;
    loja.lucro = 0;
    loja.totalVendedores = 0;
    loja.aluguel = aluguel;

    // Zerar o vetor de vendedores
    for(i = 0; i < MAX_VENDEDORES; i++) {
        loja.vendedores[i] = RegistraVendedor("\0", 0, 0);
    }

    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    if(loja.id == id) {
        return 1;
    } else {
        return 0;
    }
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    int i;
    for(i = 0; i < MAX_VENDEDORES; i++) {
        // Procura uma posicao vazia no vetor
        if(VerificaNomeVendedor(loja.vendedores[i], "\0")) {
            // Registra o vendedor na posicao vazia
            loja.vendedores[i] = vendedor;
            // Atualiza o numero de funcionarios
            loja.totalVendedores++;
            // Para o loop
            break;
        }
    }
    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
    int i;
    for(i = 0; i < MAX_VENDEDORES; i++) {
        // Procura o vendedor que fez a venda
        if(VerificaNomeVendedor(loja.vendedores[i], nome)) {
            // Registra a venda
            loja.vendedores[i].valor_vendido += valor;
            // Para o loop
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    int i, lucroBruto = 0, totalGastoSalario = 0, lucroLiquido = 0;

    // Contabilizar entradas e saidas
    for(i = 0; i < MAX_VENDEDORES; i++) {
        // Verifica se eh espaco valido no vetor
        if(!VerificaNomeVendedor(loja.vendedores[i], "\0")) {
            // Contabiliza lucro bruto
            lucroBruto += GetTotalVendido(loja.vendedores[i]);

            // Contabiliza total pago ao funcionario
            totalGastoSalario += GetTotalRecebido(loja.vendedores[i]);
        }
    }
    
    lucroLiquido = lucroBruto - (totalGastoSalario + loja.aluguel);
    loja.lucro = lucroLiquido;
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    int i;
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    // Imprimir funcionarios
    for(i = 0; i < MAX_VENDEDORES; i++) {
        if(!VerificaNomeVendedor(loja.vendedores[i], "\0")) {
            ImprimeRelatorioVendedor(loja.vendedores[i]);
        }
    }
}