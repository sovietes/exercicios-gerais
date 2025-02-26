#include <stdio.h>
#include <stdlib.h>
#include "./agendatarefas.h"
#include "./tarefasoma.h"
#include "./tarefamultiplica.h"
#include "./tarefaimprime.h"

int main() {
    int qtd;

    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &qtd);
    tAgendaTarefas *agenda = CriaAgendaDeTarefas(qtd);

    int prioridade, i, nCadastrados = 0;
    char tarefa;
    float n1, n2;
    char texto[100];



    while(nCadastrados < qtd) {
        scanf("%d %c", &prioridade, &tarefa);
        switch (tarefa)
        {
        case 'M':
            scanf("%f %f\n", &n1, &n2);
            void *m = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
            nCadastrados++;
            break;
        case 'S':
            scanf("%f %f\n", &n1, &n2);
            void *s = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, s, ExecutaTarefaSoma, DestroiTarefaSoma);
            nCadastrados++;
            break;
        case 'I':
            scanf("%*[^a-zA-Z]");
            scanf("%[^\n]", texto);
            scanf("%*c");
            void *i = CriaTarefaImprimir(texto);
            CadastraTarefaNaAgenda(agenda, prioridade, i, ExecutaTarefaImprimir, DestroiTarefaImprimir);
            nCadastrados++;
            break;
        default:
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);
    return 0;
}