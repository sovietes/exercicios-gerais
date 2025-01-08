#include "./tDepartamento.h"
#include <stdio.h>

void LimpaBuffer();
int SaoMediasValidas(int m1, int m2, int m3);

int main() {
    int nDeptos, i;
    scanf("%d", &nDeptos);
    tDepartamento departamentos[nDeptos];

    for(i = 0; i < nDeptos; i++) {
        // Variaveis padroes
        char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
        // As medias comecarao invalidas
        int m1, m2, m3;

        do {
            LimpaBuffer();
            scanf("%s", nome);
            
            LimpaBuffer();
            scanf("%s", diretor);

            LimpaBuffer();
            scanf("%s", curso1);

            LimpaBuffer();
            scanf("%s", curso2);

            LimpaBuffer();
            scanf("%s", curso3);

            LimpaBuffer();
            scanf("%d %d %d", &m1, &m2, &m3);
        } while(!SaoMediasValidas(m1, m2, m3));

        *(departamentos+i) = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }

    for(i = 0; i < nDeptos; i++) {
        ImprimeAtributosDepartamento(*(departamentos+i));
        if(i == nDeptos-1) printf("\n");
    }

    return 0;
}

void LimpaBuffer() {
    scanf("%*[^a-zA-Z0-9]");  
}

int SaoMediasValidas(int m1, int m2, int m3) {
    if((m1 >= 0 && m2 >= 0 && m3 >= 0) && (m1 <= 10 && m2 <= 10 && m3 <= 10)) {
        return 1;
    } else {
        printf("\nDigite um departamento com médias válidas");
        return 0;
    }
}