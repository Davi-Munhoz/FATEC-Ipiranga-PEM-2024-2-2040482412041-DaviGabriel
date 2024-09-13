/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Simular jogada Xeque Pastor modularizado   *
* Data - 12/09/2024                                               * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define TAMANHO 256

void inicializarTabuleiro(char *tabuleiro) {
    for (int i = 0; i < TAMANHO; i += 4) {
        snprintf(&tabuleiro[i], 4, ".x.");
    }

    snprintf(&tabuleiro[0], 4, "PT1"); // Torre de a1
    snprintf(&tabuleiro[4], 4, "PC1"); // Cavalo de b1
    snprintf(&tabuleiro[8], 4, "PB1"); // Bispo de c1
    snprintf(&tabuleiro[12], 4, "PD1"); // Dama de d1
    snprintf(&tabuleiro[16], 4, "PR1"); // Rei de e1
    snprintf(&tabuleiro[20], 4, "PB2"); // Bispo de f1
    snprintf(&tabuleiro[24], 4, "PC2"); // Cavalo de g1
    snprintf(&tabuleiro[28], 4, "PT2"); // Torre de h1

    for (int i = 32; i < 64; i += 4) {
        snprintf(&tabuleiro[i], 4, "PP%d", (i - 32) / 4 + 1); // Peões de a2 a h2
    }

    snprintf(&tabuleiro[224], 4, "BT1"); // Torre de a8
    snprintf(&tabuleiro[228], 4, "BC1"); // Cavalo de b8
    snprintf(&tabuleiro[232], 4, "BB1"); // Bispo de c8
    snprintf(&tabuleiro[236], 4, "BD1"); // Dama de d8
    snprintf(&tabuleiro[240], 4, "BR1"); // Rei de e8
    snprintf(&tabuleiro[244], 4, "BB2"); // Bispo de f8
    snprintf(&tabuleiro[248], 4, "BC2"); // Cavalo de g8
    snprintf(&tabuleiro[252], 4, "BT2"); // Torre de h8

    for (int i = 192; i < 224; i += 4) {
        snprintf(&tabuleiro[i], 4, "BP%d", (i - 192) / 4 + 1); // Peões de a7 a h7
    }
}

void imprimirTabuleiro(const char *tabuleiro, int inicial) {
    if (inicial) {
        printf("===============================\n");
        printf("       Tabuleiro inicial:      \n");
        printf("===============================\n");
        printf("\n");
    }
    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
}

void realizarMovimento(char *tabuleiro, const char *movimento, int posOrigem, int posDestino) {
    snprintf(&tabuleiro[posDestino], 4, "%s", &tabuleiro[posOrigem]);
    snprintf(&tabuleiro[posOrigem], 4, "...");
}

void mostrarMovimento(const char *movimento) {
    printf("===============================\n");
    printf("         %s:          \n", movimento);
    printf("===============================\n");
    printf("\n");
}

int main() {
    char tabuleiro[TAMANHO];

    inicializarTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro, 1); 

    mostrarMovimento("Jogada #1:\n BRANCAS JOGAM PE2 PARA PE4");
    realizarMovimento(tabuleiro, "BP5", 208, 144);
    imprimirTabuleiro(tabuleiro, 0);  

    mostrarMovimento("\nPRETAS JOGAM PE7 PARA PE5");
    realizarMovimento(tabuleiro, "PP5", 48, 112);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("Jogada #2:\n BRANCAS JOGAM BF1 PARA BC4");
    realizarMovimento(tabuleiro, "BB2", 244, 136);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("\nPRETAS JOGAM CB8 PARA CC6");
    realizarMovimento(tabuleiro, "PC1", 4, 72);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("Jogada #3:\n BRANCAS JOGAM DD1 PARA DH5");
    realizarMovimento(tabuleiro, "BD1", 236, 124);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("\nPRETAS JOGAM CG8 PARA CF6");
    realizarMovimento(tabuleiro, "PC1", 24, 84);
    imprimirTabuleiro(tabuleiro, 0);

    printf("=================================================\n");
    printf("            Jogada #4(Xeque Mate):               \n");
    printf("=================================================\n");
    printf("\nBRANCAS CAPTURAM PP6 EM F7 E XEQUE MATE (DxF7#)\n");
    printf("-------------------------------------------------\n");
    snprintf(&tabuleiro[52], 4, "BD1"); 
    snprintf(&tabuleiro[124], 4, "..."); 
    imprimirTabuleiro(tabuleiro, 0);

    printf("\nFim de jogo.");

    return 0;
}
