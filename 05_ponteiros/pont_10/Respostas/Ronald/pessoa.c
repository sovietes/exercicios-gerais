#include "./pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) {
    // Limpando buffer
    scanf("%*[^A-Z]");
    // Lendo o nome
    scanf("%[^\n]", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    if((pessoa->mae != NULL) || (pessoa->pai != NULL)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {
    if(VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        printf("PAI: %s\n", pessoa->pai == NULL ? "NAO INFORMADO" : pessoa->pai);
        printf("MAE: %s\n", pessoa->mae == NULL ? "NAO INFORMADO" : pessoa->mae);
        printf("IRMAO: %s\n", pessoa->irmao == NULL ? "NAO INFORMADO" : pessoa->irmao);
        printf("\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int mae, pai, filho, qtdAssociacoes, i, j;
    char associacao[100];
    // Limpando buffer pra ver a quantidade de associacoes que vao ser feitas
    scanf("%*[^0-9]");
    scanf("%d", &qtdAssociacoes);

    // Associando pais
    for(i = 0; i < qtdAssociacoes; i++) {
        // Le tudo ate achar a primeira letra
        scanf("%*[^m]");
        // Guarda toda a associacao ate o \n
        scanf("%[^\n]", associacao);
        // Pega as infos
        sscanf(associacao, "mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

        // Guardando o nome do pai e da mae
        if(pai != -1) {
            (pessoas+filho)->pai = (pessoas+pai);
        }
        if(mae != -1) {
            (pessoas+filho)->mae = (pessoas+mae);
        }
    }

    // Associando irmaos
    for(i = 0; i < numPessoas; i++) {
        for(j = i+1; j < numPessoas; j++) {
            if(VerificaIrmaoPessoa(pessoas+i, pessoas+j)) {
                (pessoas+i)->irmao = (pessoas+j);
                (pessoas+j)->irmao = (pessoas+i);
                break;
            }
        }
    }


}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    if((pessoa1->mae == pessoa2->mae) && (pessoa1->pai == pessoa2->pai)) {
        return 1;
    } else {
        return 0;
    }
}