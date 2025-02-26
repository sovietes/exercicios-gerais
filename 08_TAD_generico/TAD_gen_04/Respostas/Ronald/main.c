#include <stdio.h>
#include "./banco.h"

int main() {

    tBanco *banco = CriaBanco();
    LeBanco(banco);
    char c;
    while(1) {
        scanf("%c\n", &c);
        switch (c)
        {
        case 'A':
            tAgencia *agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
            break;
        case 'C':
            int numAgencia;
            tConta *conta = CriaConta();
            LeConta(conta);
            scanf("%d", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);
            break;
        case 'F':
            ImprimeRelatorioBanco(banco);
            DestroiBanco(banco);
            exit(0);
        }
    }



    return 0;
}