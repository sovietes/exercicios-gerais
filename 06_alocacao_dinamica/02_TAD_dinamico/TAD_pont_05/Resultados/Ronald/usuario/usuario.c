#include <stdio.h>
#include <stdlib.h>
#include "./usuario.h"

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario() {
    tUsuario *usuario = NULL;
    usuario = (tUsuario *) malloc(sizeof(tUsuario));
    if(!usuario) {
        printf("erro ao alocar usuario!");
        exit(0);
    }
    return usuario;
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
    // Limpar o buffer
    scanf("%*[^a-zA-Z]");

    // Lerei com o scanf pois preciso parar no espaco
    scanf("%49[^ ] %14[^ ]", user->nome, user->cpf);   
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}