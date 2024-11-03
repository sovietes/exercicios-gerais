#include <stdio.h>

int palindromo(char *string, int tamanho);
int tamString(char *string);
int qtdComparacoes(char *string);

int main() {

    char word[100];

    while(scanf("%s", word) == 1) {
        if(palindromo(word, tamString(word))) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    

    return 0;
}

int palindromo(char *string, int tamanho) {
    if(tamanho <= 0) {
        return 1;
    } else {
        if(string[0] == string[tamanho-1]) {
            return palindromo(string+1, tamanho-2);
        } else {
            return 0;
        }
    }
}

    

int tamString(char *string) {
    if(string[0] == '\0') {
        return 0;
    } else {
        return 1+tamString(string+1);
    }
}

int qtdComparacoes(char *string) {
    return (tamString(string))/2;
}
