#include <stdio.h>
#include <stdlib.h>
#include "./aluno.h"
#include "./relatorio.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {
    int i, qtdAprovados = 0, qtdM = 0, qtdF = 0, qtdO = 0;
    float mediaNotas = 0;
    for(i = 0; i < VectorSize(alunos); i++) {
        // Para calcular a media das notas
        mediaNotas += GetNotaAluno(VectorGet(alunos, i));

        // Para quantificar os aprovados
        if(GetNotaAluno(VectorGet(alunos, i)) >= 6) {
            qtdAprovados++;

        }
        // Quantificando os generos
        if(GetGeneroAluno(VectorGet(alunos, i)) == 'M') {
            qtdM++;
        } else if(GetGeneroAluno(VectorGet(alunos, i)) == 'F') {
            qtdF++;
        } else {
            qtdO++;
        }
    }

    mediaNotas /= VectorSize(alunos);

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", ((float)qtdAprovados/(float)VectorSize(alunos))*100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", ((float)qtdM/(float)VectorSize(alunos))*100);
    printf("Feminino: %.2f%%\n", ((float)qtdF/(float)VectorSize(alunos))*100);
    printf("Outro: %.2f%%\n", ((float)qtdO/(float)VectorSize(alunos))*100);

}