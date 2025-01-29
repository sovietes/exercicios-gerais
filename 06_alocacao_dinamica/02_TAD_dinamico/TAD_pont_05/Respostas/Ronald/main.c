#include <stdio.h>
#include "./banco.h"

int main() {
    tBanco *banco;
    banco = CriaBanco();
    int bancoAberto = 1;
    char opcao;

    while(bancoAberto) {
        scanf("%c", &opcao);

        switch (opcao)
        {
        case 'A':
            AbreContaBanco(banco);
            break;
        case 'D':
            DepositoContaBanco(banco);
            break;
        case 'S':
            SaqueContaBanco(banco);
            break;
        case 'T':
            TransferenciaContaBanco(banco);
            break;
        case 'R':
            ImprimeRelatorioBanco(banco);
            break;
        case 'F':
            bancoAberto = 0;
        }

    }

    DestroiBanco(banco);

    return 0;
}