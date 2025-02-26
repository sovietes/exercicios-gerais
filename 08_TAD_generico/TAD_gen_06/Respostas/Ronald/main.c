#include <stdio.h>
#include <stdlib.h>

#include "./matrizgenerica.h"
#include "./numcomplexo.h"

tMatrizGenerica * LerMatrizGenerico(tMatrizGenerica *mat, int linhas, int colunas, int tipo);

void LerMatrizInt(tMatrizGenerica *mat);
void LerMatrizFloat(tMatrizGenerica *mat);
void LerMatrizDouble(tMatrizGenerica *mat);
void LerMatrizChar(tMatrizGenerica *mat);
void LerMatrizComplexo(tMatrizGenerica *mat);


void imprime_generico(tMatrizGenerica *mat, int tipo);

void imprime_int (void *);
void imprime_char (void *);
void imprime_float (void *);
void imprime_double (void *);

tMatrizGenerica *ConverterMatrizParaCmplx(tMatrizGenerica *mat, int tipo);

void *ConverterIntParaCplx(void *elemento);
void *ConverterFloatParaCplx(void *elemento);
void *ConverterDoubleParaCplx(void *elemento);
void *ConverterCharParaCplx(void *elemento);
void *ConverterCplxParaCplx(void *elemento);

void ImprimeMenu();
void ExecutaAcao(tMatrizGenerica *mat, int acao, int tipo);
int ContinuarOperacoes();

int main() {

    tMatrizGenerica *mat;

    int linhas, colunas, tipo;

    do {
        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): ");

        scanf("%d %d %d\n", &linhas, &colunas, &tipo);
        // Se o tipo n for suportado
        while(!(tipo >= 0 && tipo <= 4)) {
            printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): ");
            scanf("%d %d %d\n", &linhas, &colunas, &tipo);
        }
        printf("\n");

        mat = LerMatrizGenerico(mat, linhas, colunas, tipo);

        // Executar acao
        ImprimeMenu();

        int acao;
        scanf("%d\n", &acao);
        // Se a acao n for suportada
        while(!(acao >= 1 && acao <= 3)) {
            printf("\n");
            ImprimeMenu();
            scanf("%d\n", &acao);
        }

        ExecutaAcao(mat, acao, tipo);
        
        DestroiMatrizGenerica(mat);

    } while(ContinuarOperacoes());





    return 0;
}

int ContinuarOperacoes() {
    int op;
    while(1) {
        printf("\nDigite a operação desejada\n");
        printf("\t1 - Entrar com uma nova matriz\n");
        printf("\t2 - Encerrar o Programa\n");
        scanf("%d", &op);
        if(op == 1) {
            return 1;
        } else if(op == 2) {
            return 0;
        }
    }

}

void ImprimeMenu() {
    printf("Digite a operação desejada\n");
    printf("\t1 - Apenas imprimir a matriz\n");
    printf("\t2 - Converter para o tipo complexo e imprimir\n");
    printf("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");
}

void ExecutaAcao(tMatrizGenerica *mat, int acao, int tipo) {
    tMatrizGenerica *novaMatriz;
    switch (acao)
    {
    case 1:
        imprime_generico(mat, tipo);
        break;
    case 2:
        novaMatriz = ConverterMatrizParaCmplx(mat, tipo);
        imprime_generico(novaMatriz, 4);
        DestroiMatrizGenerica(novaMatriz);
        break;
    case 3:
        novaMatriz = ConverterMatrizParaCmplx(mat, tipo);
        tMatrizGenerica *matTransposta = MatrizTransposta(novaMatriz);
        tMatrizGenerica *matrizResultado = MultiplicaMatrizes(novaMatriz, matTransposta, RetornaNumBytesComplexo(),(void *)MultComplexos, (void *)SomaComplexos);
        imprime_generico(matrizResultado, 4);
        DestroiMatrizGenerica(novaMatriz);
        DestroiMatrizGenerica(matTransposta);
        DestroiMatrizGenerica(matrizResultado);
        break;
    }
}

tMatrizGenerica * LerMatrizGenerico(tMatrizGenerica *mat, int linhas, int colunas, int tipo) {
    switch (tipo)
    {
    case 0:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(int *));
        LerMatrizInt(mat);
        break;
    case 1:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(float *));
        LerMatrizFloat(mat);
        break;
    case 2:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(double *));
        LerMatrizDouble(mat);
        break;
    case 3:
        mat = CriaMatrizGenerica(linhas, colunas, sizeof(char *));
        LerMatrizChar(mat);
        break;
    case 4:
        mat = CriaMatrizGenerica(linhas, colunas, RetornaNumBytesComplexo());
        LerMatrizComplexo(mat);
        break;
    }

    return mat;
}

void LerMatrizInt(tMatrizGenerica *mat) {
    int elemento, i, j;
    int *elemento_ptr = &elemento;

    for(i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for(j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            scanf("%d", &elemento);
            AtribuiElementoMatrizGenerica(mat, i, j, elemento_ptr);
        }
    }
}

void LerMatrizFloat(tMatrizGenerica *mat) {
    int i, j;
    float elemento;
    float *elemento_ptr = &elemento;

    for(i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for(j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            scanf("%f", &elemento);
            AtribuiElementoMatrizGenerica(mat, i, j, elemento_ptr);
        }
    }
}

void LerMatrizDouble(tMatrizGenerica *mat) {
    int i, j;
    double elemento;
    double *elemento_ptr = &elemento;

    for(i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for(j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            scanf("%lf", &elemento);
            AtribuiElementoMatrizGenerica(mat, i, j, elemento_ptr);
        }
    }
}

void LerMatrizChar(tMatrizGenerica *mat) {
    int i, j;
    char elemento;
    char *elemento_ptr = &elemento;

    for(i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for(j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            scanf("%*[^a-zA-Z0-9]");
            scanf("%c", &elemento);
            AtribuiElementoMatrizGenerica(mat, i, j, elemento_ptr);
        }
    }
}

void LerMatrizComplexo(tMatrizGenerica *mat) {
    int i, j;
    float real, img;
    tNumComplexo *num;
    for(i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for(j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            scanf("%*[^(]");
            scanf("(%f,%f)", &real, &img);
            num = CriaNumComplexo(real, img);
            AtribuiElementoMatrizGenerica(mat, i, j, num);
            free(num);
        }
    }
}

void imprime_generico(tMatrizGenerica *mat, int tipo) {
    switch (tipo)
    {
    case 0:
        ImprimirMatrizGenerica(mat, imprime_int);
        break;
    case 1:
        ImprimirMatrizGenerica(mat, imprime_float);
        break;
    case 2:
        ImprimirMatrizGenerica(mat, imprime_double);
        break;
    case 3:
        ImprimirMatrizGenerica(mat, imprime_double);
        break;
    case 4:
        ImprimirMatrizGenerica(mat, (void *)ImprimeNumeroComplexo);
        break;
    }
}


void imprime_int (void *valor) {
    printf("%d", *((int *)valor));
}

void imprime_float (void *valor) {
    printf("%.2f", *((float *)valor));
}

void imprime_double (void *valor) {
    printf("%.2f", *((double *)valor));
}

void imprime_char (void *valor) {
    printf("%c", *((char *)valor));
}

tMatrizGenerica *ConverterMatrizParaCmplx(tMatrizGenerica *mat, int tipo) {
    tMatrizGenerica *novaMatriz;
    switch (tipo)
    {
    case 0:
        novaMatriz = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverterIntParaCplx);
        break;
    case 1:
        novaMatriz = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverterFloatParaCplx);
        break;
    case 2:
        novaMatriz = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverterDoubleParaCplx);
        break;
    case 3:
        novaMatriz = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverterCharParaCplx);
        break;
    case 4:
        novaMatriz = ConverteTipoMatriz(mat, RetornaNumBytesComplexo(), ConverterCplxParaCplx);
        break;
    }

    return novaMatriz;
}


void *ConverterIntParaCplx(void *elemento) {
    int elementoNovo = *((int *)elemento);
    void *cmplx;
    cmplx = CriaNumComplexo((float)elementoNovo, 0);
    return cmplx;
}

void *ConverterFloatParaCplx(void *elemento) {
    float elementoNovo = *((float *)elemento);
    void *cmplx;
    cmplx = CriaNumComplexo((float)elementoNovo, 0);
    return cmplx;
}


void *ConverterDoubleParaCplx(void *elemento) {
    double elementoNovo = *((double *)elemento);
    void *cmplx;
    cmplx = CriaNumComplexo((float)elementoNovo, 0);
    return cmplx;
}

void *ConverterCharParaCplx(void *elemento) {
    char elementoNovo = *((char *)elemento);
    int elementoConvertido = (elementoNovo - '0');
    void *cmplx;
    cmplx = CriaNumComplexo((float)elementoConvertido, 0);
    return cmplx;
}

void *ConverterCplxParaCplx(void *elemento) {
    void *cmplx = CriaNumComplexo(PegaParteRealComplexo((tNumComplexo *)elemento), PegaParteImagComplexo((tNumComplexo *)elemento));
    return cmplx;
}