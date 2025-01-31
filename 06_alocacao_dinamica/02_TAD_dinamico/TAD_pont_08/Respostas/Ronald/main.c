#include <stdio.h>
#include "./departamento.h"

void RegistraDepartamento(tDepartamento **departamentos, tDepartamento *departamentoNovo, int qtdDepartamentos);

int main() {
    tDepartamento **departamentos = NULL;
    char nome[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], diretor[STRING_MAX];
    int m1, m2, m3;
    int qtdDeptos, i;

    // Lendo os departamentos
    scanf("%d\n", &qtdDeptos);
    departamentos = (tDepartamento **) malloc(qtdDeptos*sizeof(tDepartamento *));

    // Inicializando departamentos
    for(i = 0; i < qtdDeptos; i++) {
        departamentos[i] = NULL;
    }

    for(i = 0; i < qtdDeptos; i++) {
        // Lendo nome departamento
        scanf("%100[^\n]", nome);
        scanf("%*c");

        // Lendo diretor
        scanf("%100[^\n]", diretor);
        scanf("%*c");
        
        // Lendo cursos
        scanf("%100[^\n]", c1);
        scanf("%*c");
        scanf("%100[^\n]", c2);
        scanf("%*c");
        scanf("%100[^\n]", c3);
        scanf("%*c");

        // Lendo medias
        scanf("%d %d %d\n", &m1, &m2, &m3);

        // Registrando departamentos
        if(ValidaMediaDepartamento(m1) && ValidaMediaDepartamento(m2) && ValidaMediaDepartamento(m3)) {
            tDepartamento *departamentoNovo = CriaDepartamento();
            PreencheDadosDepartamento(departamentoNovo, c1, c2, c3, nome, m1, m2, m3, diretor);
            RegistraDepartamento(departamentos, departamentoNovo, qtdDeptos);
        } else {
            printf("Media(s) invalida(s)!\n");
        }

    }

    // Imprimindo relatorio final
    OrdenaPorMediaDepartamentos(departamentos, qtdDeptos);

    for(i = 0; i < qtdDeptos; i++) {
        ImprimeAtributosDepartamento(departamentos[i]);
    }

    // Liberando memoria alocada
    if(departamentos) {
        for(i = 0; i < qtdDeptos; i++) {
            LiberaMemoriaDepartamento(departamentos[i]);
        }
        free(departamentos);
    }


    return 0;
}

void RegistraDepartamento(tDepartamento **departamentos, tDepartamento *departamentoNovo, int qtdDepartamentos) {
    int i;
    for(i = 0; i < qtdDepartamentos; i++) {
        if(!departamentos[i]) {
            departamentos[i] = departamentoNovo;
            return;
        }
    }
}