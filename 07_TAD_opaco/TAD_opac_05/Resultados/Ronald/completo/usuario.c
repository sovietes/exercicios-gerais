#include <stdio.h>
#include <stdlib.h>
#include "./usuario.h"

struct Usuario {
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
};

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario() {
    tUsuario *u = NULL;
    u = (tUsuario *) malloc(sizeof(tUsuario));
    if(!u) {
        exit(1);
    }
    return u;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user) {
    if(user) {
        free(user);
    }
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user) {
    // Limpando buffer
    scanf("%*[^a-zA-Z]");
    // Lendo
    scanf("%49s %14s", user->nome, user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\nCPF: %s\n", user->nome, user->cpf);
}