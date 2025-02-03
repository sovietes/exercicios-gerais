#include <stdio.h>
#include "./empresa.h"


int main() {
    int qtdEmpresas, i;
    scanf("%d\n", &qtdEmpresas);
    
    tEmpresa *empresas[qtdEmpresas];

    for(i = 0; i < qtdEmpresas; i++) {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }

    for(i = 0; i < qtdEmpresas; i++) {
        ImprimeEmpresa(empresas[i]);
        ApagaEmpresa(empresas[i]);
    }

    return 0;
}