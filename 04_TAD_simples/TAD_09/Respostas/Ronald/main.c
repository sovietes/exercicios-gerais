#include <stdio.h>
#include "empresa.h"

void LerEmpresasMain(tEmpresa *empresas, int qtdEmpresas);
void ImprimeEmpresasMain(tEmpresa *empresas, int qtdEmpresas);

int main() {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);
    tEmpresa empresas[qtdEmpresas];

    LerEmpresasMain(empresas, qtdEmpresas);
    ImprimeEmpresasMain(empresas, qtdEmpresas);

    return 0;
}

void LerEmpresasMain(tEmpresa *empresas, int qtdEmpresas) {
    int i;
    for(i = 0; i < qtdEmpresas; i++) {
        empresas[i] = leEmpresa();
    }
}

void ImprimeEmpresasMain(tEmpresa *empresas, int qtdEmpresas) {
    int i;
    for(i = 0; i < qtdEmpresas; i++) {
        imprimeEmpresa(empresas[i]);
    }
}
