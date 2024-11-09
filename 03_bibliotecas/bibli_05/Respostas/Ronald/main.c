#include <stdio.h>
#include "./string_utils.h"

void menuInterativo();
void executa_op(int opcao, char * str);

int main() {
    int opcao;
    char str[1000];
    scanf("%[^\n]", str);

    while(scanf("%d", &opcao) == 1) {
        menuInterativo();
        if(opcao == 6) break;
        executa_op(opcao, str);
    }

    return 0;
}

void menuInterativo() {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

void executa_op(int opcao, char * str) {
    if(opcao == 1) {
        printf("Tamanho da string: %d\n", string_length(str));
    } else if(opcao == 2) {
        char dest[string_length(str)];
        string_copy(str, dest);
        printf("String copiada: %s\n", dest);
    } else if(opcao == 3) {
        string_upper(str);
        printf("String convertida para maiusculas: %s\n", str);
    } else if(opcao == 4) {
        string_lower(str);
        printf("String convertida para minusculas: %s\n", str);
    } else if(opcao == 5) {
        string_reverse(str);
        printf("String invertida: %s\n", str);
    }

    printf("\n");
}