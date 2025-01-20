#include <stdio.h>
#include "tela.h"

void AcaoSalvar();
void AcaoExcluir();
void AcaoOpcoes();

int main() {
    Tela tela;
    tela = CriarTela(400, 200);
    Tela *ptrTela = &tela;

    RegistraBotaoTela(ptrTela, CriarBotao("Salvar", 12, "FFF", CLICK, AcaoSalvar));
    RegistraBotaoTela(ptrTela, CriarBotao("Excluir", 18, "000", CLICK, AcaoExcluir));
    RegistraBotaoTela(ptrTela, CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, AcaoOpcoes));

    DesenhaTela(tela);

    OuvidorEventosTela(tela);

    return 0;
}

void AcaoSalvar() {
    printf("- Botao de SALVAR dados ativado!\n");
}

void AcaoExcluir() {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void AcaoOpcoes() {
    printf("- Botao de OPCOES ativado!\n");
}