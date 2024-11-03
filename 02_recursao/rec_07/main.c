#include <stdio.h>

int somaDigitos(int n);

int main(int argc, char *argv[]) {
    FILE *fArquivo;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    int n;
    
    sprintf(nomeArquivoEntrada, "./input/%s.txt", argv[1]);
    sprintf(nomeArquivoSaida, "./outprog/%s.txt", argv[1]);

    fArquivo = fopen(nomeArquivoEntrada, "r");
    fscanf(fArquivo, "%d", &n);
    fclose(fArquivo);

    fArquivo = fopen(nomeArquivoSaida, "w");
    fprintf(fArquivo, "%d\n", somaDigitos(n));
    fclose(fArquivo);

    return 0;
}

int somaDigitos(int n) {
    if(n/10 == 0) {
        return n;
    } else {
        return n%10 + somaDigitos(n/10);
    }
}