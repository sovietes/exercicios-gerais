#include <stdio.h>
#include "./temperature_conversor.h"

void print_result(float temp, char escalaAtual, char escalaFinal);

int main() {
    float temp;
    char escalaAtual, escalaFinal;

    scanf("%f %c %c", &temp, &escalaAtual, &escalaFinal);

    print_result(temp, escalaAtual, escalaFinal);

    return 0;
}

void print_result(float temp, char escalaAtual, char escalaFinal) {
    if(escalaAtual == 'c') {
        if(escalaFinal == 'f') {
            printf("Temperature: %.2fFº", convert_temperature(temp, convert_celsius_to_fahrenheit));
        } else if(escalaFinal == 'k') {
            printf("Temperature: %.2fK", convert_temperature(temp, convert_celsius_to_kelvin));
        }
    } else if(escalaAtual == 'k') {
        if(escalaFinal == 'c') {
            printf("Temperature: %.2fCº", convert_temperature(temp, convert_kelvin_to_celsius));
        } else if(escalaFinal == 'f') {
            printf("Temperature: %.2fFº", convert_temperature(temp, convert_kelvin_to_fahrenheit));
        }
    } else if(escalaAtual == 'f') {
        if(escalaFinal == 'c') {
            printf("Temperature: %.2fCº", convert_temperature(temp, convert_fahrenheit_to_celsius));
        } else if(escalaFinal == 'k') {
            printf("Temperature: %.2fK", convert_temperature(temp, convert_fahrenheit_to_kelvin));
        }
    }
}