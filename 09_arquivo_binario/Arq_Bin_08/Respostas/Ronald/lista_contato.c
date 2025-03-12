#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lista_contato.h"
#include "./vector.h"

struct ListaContato {
    Vector *lista;
};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato() {
    tListaContato *l = (tListaContato *) malloc(sizeof(tListaContato));
    l->lista = VectorConstruct();
    return l;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l) {
    int i;
    if(l) {
        VectorDestroy(l->lista, DestruirContato);
        free(l);
    }
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato) {
    int i;
    for(i = 0; i < VectorSize(l->lista); i++) {
        if(ComparaNomeContato(VectorGet(l->lista, i), contato) || ComparaTelefoneContato(VectorGet(l->lista, i), contato)) {
            printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }
    }
    VectorPushBack(l->lista, contato);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l) {
    int i;
    unsigned long int telefone;
    scanf("%lu\n", &telefone);

    for(i = 0; i < VectorSize(l->lista); i++) {
        if(GetTelefoneContato(VectorGet(l->lista, i)) == telefone) {
            ImprimirContato(VectorGet(l->lista, i));
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l) {
    int i;
    char nome[100];
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]\n", nome);

    for(i = 0; i < VectorSize(l->lista); i++) {
        if(strcmp(GetNomeContato(VectorGet(l->lista, i)), nome) == 0) {
            ImprimirContato(VectorGet(l->lista, i));
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo) {
    int qtdContatos, i;
    FILE *fp = fopen(nomeArquivo, "rb");
    if(!fp) return;
    fread(&qtdContatos, sizeof(int), 1, fp);

    for(i = 0; i < qtdContatos; i++) {
        tContato *contato = CarregarContato(fp);
        AdicionarContatoListaContato(l, contato);
    }
    fclose(fp);
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo) {
    int i, tamanhoVetor = VectorSize(l->lista);
    FILE *fp = fopen(nomeArquivo, "wb");
    fwrite(&tamanhoVetor, sizeof(int), 1, fp);

    for(i = 0; i < VectorSize(l->lista); i++) {
        SalvarContato(VectorGet(l->lista, i), fp);
    }
    fclose(fp);
}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l) {
    int i;

    printf("\nLista de contatos cadastrados\n");
    for(i = 0; i < VectorSize(l->lista); i++) {
        ImprimirContato(VectorGet(l->lista, i));
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l) {
    int i;
    unsigned long int numero;
    scanf("%lu", &numero);
    for(i = 0; i < VectorSize(l->lista); i++) {
        if(GetTelefoneContato(VectorGet(l->lista, i)) == numero) {
            DestruirContato(VectorGet(l->lista, i));
            VectorRemove(l->lista, i);
            printf("\nContato removido com sucesso\n");
            return;
        }
    }

    printf("\nNao existe um contato cadastrado com esse numero de telefone\n");
}