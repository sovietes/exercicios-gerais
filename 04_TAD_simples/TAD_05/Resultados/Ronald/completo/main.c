#include <stdio.h>
#include "conta.h"

void LerConta(tConta *contas, int index);
void RealizarSaque(tConta *contas, int qtdContas);
void RealizarDeposito(tConta *contas, int qtdContas);
void ImprimirRelatorio(tConta *contas, int qtdContas);

int main() {
    int qtdMaxContas, qtdContasLidas = 0, op = -1;
    scanf("%d", &qtdMaxContas);
    tConta contas[qtdMaxContas];

    while(op) {
        scanf("%*[^0-9]");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            RealizarSaque(contas, qtdContasLidas);
            break;
        case 2:
            RealizarDeposito(contas, qtdContasLidas);
            break;
        case 3:
            LerConta(contas, qtdContasLidas);
            qtdContasLidas++;
            break;
        case 4:
            ImprimirRelatorio(contas, qtdContasLidas);
            break;
        }

    }

    return 0;
}

void LerConta(tConta *contas, int index) {
    char nome[20], cpf[15];
    int numero;
    scanf("%*[a-zA-Z]");
    scanf("%s %s %d", nome, cpf, &numero);
    contas[index] = CriaConta(numero, CriaUsuario(nome, cpf));
}

void RealizarSaque(tConta *contas, int qtdContas) {
    int i, numeroConta, valor;

    scanf("%*[^0-9]");
    scanf("%d %d", &numeroConta, &valor);

    for(i = 0; i < qtdContas; i++) {
        if(VerificaConta(contas[i], numeroConta)) {
            contas[i] = SaqueConta(contas[i], valor);
            return;
        }
    }
}

void RealizarDeposito(tConta *contas, int qtdContas) {
    int i, numeroConta, valor;

    scanf("%*[^0-9]");
    scanf("%d %d", &numeroConta, &valor);

    for(i = 0; i < qtdContas; i++) {
        if(VerificaConta(contas[i], numeroConta)) {
            contas[i] = DepositoConta(contas[i], valor);
            return;
        }
    }
}

void ImprimirRelatorio(tConta *contas, int qtdContas) {
    int i;
    printf("===| Imprimindo Relatorio |===\n");

    for(i = 0; i < qtdContas; i++) {
        ImprimeConta(contas[i]);
        printf("\n");
    }
}