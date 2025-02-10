#include <stdio.h>
#include "./circulo.h"

int main() {
    tCirculo circulo;
    tPonto ponto;
    // Para o circulo
    float c_x, c_y, c_r;
    // Para pontos
    float p_x, p_y;

    scanf("%f %f %f %f %f\n", &c_x, &c_y, &c_r, &p_x, &p_y);

    circulo = Circulo_Cria(c_x, c_y, c_r);

    ponto = Pto_Cria(p_x, p_y);

    printf("%d", Circulo_Interior(circulo, ponto));

    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);

    return 0;
}