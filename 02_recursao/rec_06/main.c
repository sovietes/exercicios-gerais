#include <stdio.h>

int fibonacci(int n);

int main(int argc, char *argv[]) {
    FILE *fArquivo;
    char nomeArquivoEntrada[100]; char nomeArquivoSaida[100];
    int n = 15;

    sprintf(nomeArquivoEntrada, "./input/%s.txt", argv[1]);
    sprintf(nomeArquivoSaida, "./outprog/%s.txt", argv[1]);

    fArquivo = fopen(nomeArquivoEntrada, "r");
    if(!fArquivo) {
        printf("Erro ao abrir o arquivo.");
        return 0;
    }

    fscanf(fArquivo, "%d", &n);
    fclose(fArquivo);

    fArquivo = fopen(nomeArquivoSaida, "w");
    fprintf(fArquivo, "%d\n", fibonacci(n));
    fclose(fArquivo);
    
    return 0;
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}