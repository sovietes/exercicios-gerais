#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./histograma.h"

struct tHistograma {
    int *nPixelsIntervalo;
    int nIntervalos;
    int tamanhoIntervalo;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
    int i;
    void *dadosImagem = ObterDadosImagem(img);

    Histograma *hst = (Histograma *) malloc(sizeof(Histograma));
    // Salvando o numero de intervalos
    hst->nIntervalos = nIntervalos;
    // Separando espaco para salvar o numero de pixels de cada intervalo
    hst->nPixelsIntervalo = (int *) malloc(sizeof(int)*(hst->nIntervalos));
    memset(hst->nPixelsIntervalo, 0, (hst->nIntervalos)*sizeof(int));
    // Calculando o tamanho do intervalo
    float tamanhoIntervalo = ((float)256)/((float)hst->nIntervalos);
    hst->tamanhoIntervalo = (int)ceil(tamanhoIntervalo);

    // Somando a quantidade de pixels de cada intervalo
    int qtdValores = ObterLarguraImagem(img) * ObterAlturaImagem(img);

    // Varrendo todos os valores para cada intervalo
    for(i = 0; i < qtdValores; i++) {
        if(ObterTipoImagem(img) == INT) {
            int auxValorPixelint = ((int *)dadosImagem)[i];
            int intervalo = (int) ((float)auxValorPixelint/(float)(hst->tamanhoIntervalo));
            (hst->nPixelsIntervalo[intervalo])++;
        } else if(ObterTipoImagem(img) == FLOAT) {
            float auxValorPixelfloat = ((float *)dadosImagem)[i];
            auxValorPixelfloat *= 255;
            int intervalo = (int) ((float)auxValorPixelfloat/(float)(hst->tamanhoIntervalo));
            (hst->nPixelsIntervalo[intervalo])++;
        }
    }

    return hst;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma) {
    int i;
    int intervaloAnterior = 0;
    int proximoIntervalo = 0;

    for(i = 0; i < histograma->nIntervalos; i++) {
        proximoIntervalo = ((histograma->tamanhoIntervalo) + intervaloAnterior);
        printf("[%d, %d): %d\n", intervaloAnterior, proximoIntervalo, histograma->nPixelsIntervalo[i]);
        intervaloAnterior = proximoIntervalo;
    }
        
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma) {
    if(histograma) {
        if(histograma->nPixelsIntervalo) {
            free(histograma->nPixelsIntervalo);
        }
        free(histograma);
    }
}