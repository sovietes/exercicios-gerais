#include <stdio.h>
#include "./imagem.h"
#include "./histograma.h"

int main() {
    char caminho[100];
    int nIntervalos;

    scanf("%[^\n]\n", caminho);
    scanf("%d\n", &nIntervalos);

    Imagem *img = LerImagem(caminho);
    Histograma *histograma = CalcularHistograma(img, nIntervalos);
    MostrarHistograma(histograma);

    DestruirImagem(img);
    DestruirHistograma(histograma);

    return 0;
}