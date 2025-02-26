#include <stdio.h>
#include <stdlib.h>
#include "./agendatarefas.h"

typedef void (*fPtr_executa)(void*);
typedef void (*fPtr_destroi)(void*);

int aux_RetornaIdxMaiorPrioridade(tAgendaTarefas *tar);

struct agendatarefas {
    void **tarefas;
    int *prioridade;

    fPtr_executa *funcoesParaExec;
    fPtr_destroi *funcoesParaDest;

    int nTarefas;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *a = (tAgendaTarefas *) malloc(sizeof(tAgendaTarefas));

    a->tarefas = (void **) malloc(sizeof(void *)*numElem);
    a->prioridade = (int *) malloc(sizeof(int)*numElem);
    a->funcoesParaExec = (fPtr_executa *) malloc(sizeof(fPtr_executa)*numElem);
    a->funcoesParaDest = (fPtr_destroi *) malloc(sizeof(fPtr_destroi)*numElem);

    a->nTarefas = 0;

    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    if(tar) {
        if(tar->tarefas) {
            free(tar->tarefas);
            free(tar->prioridade);
            free(tar->funcoesParaDest);
            free(tar->funcoesParaExec);
        }
        free(tar);
    }
}


/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ) {
    tar->tarefas[tar->nTarefas] = tarefa;
    tar->prioridade[tar->nTarefas] = prioridade;
    tar->funcoesParaExec[tar->nTarefas] = executa;
    tar->funcoesParaDest[tar->nTarefas]= destroi;
    tar->nTarefas++;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    int i;
    for(i = 0; i < tar->nTarefas; i++) {
        int idx = aux_RetornaIdxMaiorPrioridade(tar);
        tar->funcoesParaExec[idx](tar->tarefas[idx]);
        tar->funcoesParaDest[idx](tar->tarefas[idx]);
        tar->tarefas[idx] = NULL;
    }

}

int aux_RetornaIdxMaiorPrioridade(tAgendaTarefas *tar) {
    int maiorPrioridade = -1, idxMaiorPrioridade = 0, i;
    int flagEnter = 0;
    for(i = 0; i < tar->nTarefas; i++) {
        if(tar->tarefas[i] != NULL) {
            if(flagEnter == 0) {
                maiorPrioridade = tar->prioridade[i];
                idxMaiorPrioridade = i;
                flagEnter = 1;
            } else if(maiorPrioridade < tar->prioridade[i]) {
                maiorPrioridade = tar->prioridade[i];
                idxMaiorPrioridade = i;
            }
        }
    }
    return idxMaiorPrioridade;
}

