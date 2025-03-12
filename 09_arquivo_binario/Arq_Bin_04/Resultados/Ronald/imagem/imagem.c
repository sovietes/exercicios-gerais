#include <stdio.h>
#include <stdlib.h>
#include "./imagem.h"

struct tImagem {
    int linhas, colunas;
    Tipo tipo;
    void *imagem;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho) {
    Imagem *img = (Imagem *) malloc(sizeof(Imagem));
    FILE *fp = fopen(caminho, "rb");
    
    fread(&img->linhas, sizeof(int), 1, fp);
    fread(&img->colunas, sizeof(int), 1, fp);
    fread(&img->tipo, sizeof(int), 1, fp);
    
    int qtdValores = (img->linhas)*(img->colunas);
    int i;
    
    if(img->tipo == INT) {
        img->imagem = malloc(sizeof(int) * qtdValores);

        for(i = 0; i < qtdValores; i++) {
            fread(&img->imagem[i*sizeof(int)], sizeof(int), 1, fp);
        }
    } else if(img->tipo == FLOAT) {
        img->imagem = malloc(sizeof(float) * qtdValores);

        for(i = 0; i < qtdValores; i++) {
            fread(&img->imagem[i*sizeof(float)], sizeof(float), 1, fp);
        }
    }

    fclose(fp);

    return img;
}


/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img) {
    if(img) {
        if(img->imagem) {
            free(img->imagem);
        }
        free(img);
    }
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img) {
    return img->colunas;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img) {
    return img->linhas;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img) {
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img) {
    return img->imagem;
}