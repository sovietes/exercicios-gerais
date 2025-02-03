#include <stdio.h>
#include <stdlib.h>
#include "./empresa.h"

int EhFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario);

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa() {
    tEmpresa *empresa = NULL;
    empresa = (tEmpresa *) malloc(sizeof(tEmpresa));
    if(!empresa) {
        printf("erro ao alocar empresa!!!\n");
        exit(0);
    }

    empresa->funcionarios = NULL;
    empresa->id = -1;
    empresa->qtdFuncionarios = -1;

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa) {
    int i, qtdCandidatos;
    // Lendo id empresa
    scanf("%d %d", &empresa->id, &qtdCandidatos);
    tFuncionario *funcionariosCandidatos[qtdCandidatos];

    // Inicializando vetor funcionarios
    empresa->funcionarios = (tFuncionario **) malloc(qtdCandidatos*sizeof(tFuncionario *));
    empresa->qtdFuncionarios = 0;

    // Lendo os candidatos
    for(i = 0; i < qtdCandidatos; i++) {
        funcionariosCandidatos[i] = CriaFuncionario();
        LeFuncionario(funcionariosCandidatos[i]);
    }

    // Contratando
    for(i = 0; i < qtdCandidatos; i++) {
        ContrataFuncionarioEmpresa(empresa, funcionariosCandidatos[i]);
    }


}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa) {
    if(empresa) {
        int i;
        if(empresa->funcionarios) {
            for(i = 0; i < empresa->qtdFuncionarios; i++) {
                if(empresa->funcionarios[i]) {
                    ApagaFuncionario(empresa->funcionarios[i]);
                }
            }
            free(empresa->funcionarios);
        }
        free(empresa);
    }
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario) {
    if(!EhFuncionarioEmpresa(empresa, funcionario)) {
        // Salva no espaco
        empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
        // Aumenta 1 funcionario
        empresa->qtdFuncionarios++;
    } else {
        printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, GetIdFuncionario(funcionario));
        ApagaFuncionario(funcionario);
    }
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa) {
    int i;
    printf("Empresa %d:\n", empresa->id);
    for(i = 0; i < empresa->qtdFuncionarios; i++) {
        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}


// Retorna 1 caso seja funcionario da empresa e 0 caso nao seja
int EhFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario) {
    int i;
    for(i = 0; i < empresa->qtdFuncionarios; i++) {
        if(GetIdFuncionario(empresa->funcionarios[i]) == GetIdFuncionario(funcionario)) {
            return 1;
        }
    }

    return 0;
}