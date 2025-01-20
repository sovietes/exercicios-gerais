#include "./tela.h"
#include "./botao.h"
#include <stdio.h>

/**
 * @brief Cria uma nova tela com a altura e largura especificadas e botões vazios (zero).
 * 
 * @param altura Altura da tela em pixels.
 * @param largura Largura da tela em pixels.
 * @return Tela Retorna a tela criada.
 */
Tela CriarTela(int altura, int largura) {
    int i;
    Tela t;

    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;

    return t;
}

/**
 * @brief Registra um botão na tela especificada se houver espaço.
 * 
 * @param t Ponteiro para a tela em que o botão será registrado.
 * @param b Botão a ser registrado na tela.
 */
void RegistraBotaoTela(Tela *t, Botao b) {
    if(t->qntBotoes < MAX_BOTOES) {
        t->botoes[t->qntBotoes] = b;
        t->qntBotoes++;
    }
}

/**
 * @brief Desenha a tela especificada na saída padrão se houver botões registrados.
 * 
 * @param t Tela a ser desenhada.
 */
void DesenhaTela(Tela t) {
    int i;
    printf("##################\n");
    for(i = 0; i < t.qntBotoes; i++) {
        DesenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n");
    printf("- Escolha sua acao: ");

}

/**
 * @brief Espera o usuário clicar em um botão da tela especificada e executa a ação correspondente.
 * se o usuário clicar em um botão que não existe, o programa é encerrado.
 * 
 * @param t Tela em que o usuário deve clicar em um botão.
 */
void OuvidorEventosTela(Tela t) {
    int idx;
    scanf("%d", &idx);
    if((idx < t.qntBotoes) && (idx >= 0)) {
        ExecutaBotao(t.botoes[idx]);
    } else {
        exit(0);
    }
}