#include <stdio.h>
#include "./banco.h"

int main() {

    tBanco *banco;
    banco = CriaBanco();
    char opcao;

    while (1)
    {
        scanf("%c", &opcao);
        switch (opcao)
        {
        case 'A':
            AbreContaBanco(banco);
            break;
        case 'S':
            SaqueContaBanco(banco);
            break;
        case 'D':
            DepositoContaBanco(banco);
            break;
        case 'T':
            TransferenciaContaBanco(banco);
            break;
        case 'R':
            ImprimeRelatorioBanco(banco);
            break;
        case 'F':
            DestroiBanco(banco);
            exit(0);
            break;
        }
    }

    return 0;
}