#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./tarefaimprime.h"

struct impr {
    char *msg;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg) {
    tImpr *i = (tImpr *) malloc(sizeof(tImpr));
    i->msg = (char *) malloc(sizeof(char)*(strlen(msg)+1));
    strcpy(i->msg, msg);

    return i;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp) {
    printf("\n%s", ((tImpr *)imp)->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp) {
    if(imp) {
        if(((tImpr *)imp)->msg) {
            free(((tImpr *)imp)->msg);
        }
        free(imp);
    }
}