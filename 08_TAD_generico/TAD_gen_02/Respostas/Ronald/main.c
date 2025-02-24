#include <stdio.h>
#include <stdlib.h>
#include "./gerenciadorpacotes.h"

void ImprimirMenu();

int main() {
    tGerenciador *gerenciador = CriaGerenciador();

    printf("tad_gen_02\n");
    int op;

    while(1) {
        ImprimirMenu();
        scanf("%d\n", &op);
        switch (op)
        {
        case 1:
            int tipo, qtdElem;
            tPacote *pacote;
            printf("\nDigite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d\n", &tipo, &qtdElem);

            if(tipo == 0) {
                pacote = CriaPacote(CHAR, qtdElem);
            } else if(tipo == 1) {
                pacote = CriaPacote(INT, qtdElem);
            } else {
                printf("\nDigite um tipo valido!");
                break;
            }
            
            LePacote(pacote);
            AdicionaPacoteNoGerenciador(gerenciador, pacote);
            break;
        case 2:
            int idx;
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(gerenciador, idx);
            break;
        case 3:
            printf("\n");
            ImprimirTodosPacotes(gerenciador);
            DestroiGerenciador(gerenciador);
            exit(0);
        default:
            printf("\nEscolha uma opcao valida para o menu!");
        }
    }




    return 0;
}

void ImprimirMenu() {
    printf("\nEscolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote específico\n");
    printf("\t(3) Imprimir todos os pacotes e sair");
    
	
	
	
}