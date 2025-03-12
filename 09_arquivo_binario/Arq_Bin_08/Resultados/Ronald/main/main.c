#include <stdio.h>
#include <stdlib.h>
#include "./lista_contato.h"

void imprimirMenu();
void menuSecundario();

int main() {

    char endereco[100];
    scanf("%[^\n]\n", endereco);
    tListaContato *l = CriarListaContato();
    CarregarListaContato(l, endereco);

    tContato *cAux;
    int operacao, operacao2, i;
    while (1)
    {
        imprimirMenu();
        scanf("%d\n", &operacao);

        switch (operacao)
        {
        case 0:
            scanf("%[^\n]\n", endereco);
            SalvarListaContato(l, endereco);

            DestruirListaContato(l);
            exit(0);
            break;
        case 1:
            cAux = LeContato();
            AdicionarContatoListaContato(l, cAux);
            break;
        case 2:
            RemoverContatoListaContato(l);
            break;
        case 3:
            menuSecundario();
            scanf("%d\n", &operacao2);
            switch (operacao2)
            {
            case 1:
                BuscarPorNomeListaContato(l);
                break;
            case 2:
                BuscarPorNumeroTelefoneListaContato(l);
                break;
            }
            break;
        case 4:
            ImprimirListaContato(l);
            break;
        }
    }
    
    return 0;
}

void imprimirMenu() {
    printf("1 - Cadastrar contato\n2 - Remover contato\n3 - Realizar busca\n4 - Exibir todos os contatos\n0 - Sair da lista de contatos\n");
    printf("Opcao escolhida: \n");
}

void menuSecundario() {
    printf("1 - Buscar pelo nome\n2 - Buscar pelo numero de telefone\n");
    printf("Opcao escolhida: \n");
}