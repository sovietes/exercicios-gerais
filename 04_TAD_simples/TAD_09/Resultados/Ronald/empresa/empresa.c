#include "empresa.h"

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;
    return empresa;
}

tEmpresa leEmpresa() {
    tEmpresa empresa; tFuncionario funcionario;
    int id, numeroFuncionariosCadastro, i;
    scanf("%*[^0-9]");
    scanf("%d %d", &id, &numeroFuncionariosCadastro);
    empresa = criaEmpresa(id);

    for(i = 0; i < numeroFuncionariosCadastro; i++) {
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    int i;
    // Loop para verificar se o funcionário ja está cadastrado, se estiver, não faz o cadastro dele
    for(i = 0; i < empresa.qtdFuncionarios; i++) {
        if(getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario)) {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
            return empresa;
        }
    }

    // Somente chegará nessa parte do código se o funcionário não estiver cadastrado
    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    // Adiciona 1 ao numero de funcionarios da empresa
    empresa.qtdFuncionarios++;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    int i;
    printf("Empresa %d:\n", empresa.id);
    for(i = 0; i < empresa.qtdFuncionarios; i++) {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}