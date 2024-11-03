#include <stdio.h>

int fatorial(int n);

int main(int argc, char *argv[]) {
    FILE *fArquivo;
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];

    int numero;

    sprintf(nomeArquivoEntrada, "./input/%s",argv[1]);
    sprintf(nomeArquivoSaida, "./outprog/%s",argv[1]);


    fArquivo = fopen(nomeArquivoEntrada, "r");

    if(!fArquivo) {
        printf("Erro ao abrir o arquivo!");
        return 0;
    }

    fscanf(fArquivo, "%d", &numero);
    fclose(fArquivo);

    fArquivo = fopen(nomeArquivoSaida, "w");
    fprintf(fArquivo, "%d\n", fatorial(numero));
    fclose(fArquivo);

    return 0;
}

int fatorial(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}
