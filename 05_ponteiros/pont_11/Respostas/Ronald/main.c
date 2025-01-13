#include <stdio.h>
#include "./calculadora.h"

float add(float, float);
float sub(float, float);
float mult(float, float);
float div(float, float);

int main() {
    float n1, n2;
    char caractere;

    while(1) {
        // Limpa o buffer e le a op
        scanf("%*[^a-z]");
        scanf("%c", &caractere);
        // Limpar o buffer e le os numeros
        scanf("%*[^0-9]");
        scanf("%f %f", &n1, &n2);
        // Faz a operacao
        switch (caractere) {
            case 'a':
                printf("%.2f + %.2f = %.2f\n", n1, n2, Calcular(n1, n2, add));
                break;
            case 's':
                printf("%.2f - %.2f = %.2f\n", n1, n2, Calcular(n1, n2, sub));
                break;
            case 'm':
                printf("%.2f x %.2f = %.2f\n", n1, n2, Calcular(n1, n2, mult));
                break;
            case 'd':
                printf("%.2f / %.2f = %.2f\n", n1, n2, Calcular(n1, n2, div));
                break;
            default:
                break;
            }
        // Para o loop
        if(caractere == 'f') break;
    }

    return 0;
}

float add(float num1, float num2) {
    return num1+num2;
};
float sub(float num1, float num2) {
    return num1 - num2;
}
float mult(float num1, float num2) {
    return num1*num2;
}
float div(float num1, float num2) {
    return num1/num2;
}