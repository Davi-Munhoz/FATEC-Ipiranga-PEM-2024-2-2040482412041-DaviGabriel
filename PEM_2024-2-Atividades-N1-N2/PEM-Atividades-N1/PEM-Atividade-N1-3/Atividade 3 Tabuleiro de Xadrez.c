/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Construir um tabuleiro de xadrez     *
* Data - 29/08/2024                                               * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define tamanho 8
#define celula 5 
void inicializar(char tabuleiro[tamanho][tamanho][celula]) {
    const char* brancas[] = {"BT1 ", "BC1 ", "BB1 ", "BD1 ", "BR1 ", "BB2 ", "BC2 ", "BT2 "};
    const char* pretas[] = {"PT1 ", "PC1 ", "PB1 ", "PD1 ", "PR1 ", "PB2 ", "PC2 ", "PT2 "};
    
    for (int i = 0; i < 8; i++) {
        snprintf(tabuleiro[0][i], celula, "%s", brancas[i]);
        snprintf(tabuleiro[1][i], celula, "BP%d ", i + 1);
        snprintf(tabuleiro[6][i], celula, "PP%d ", i + 1);
        snprintf(tabuleiro[7][i], celula, "%s", pretas[i]);
    }
    
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            snprintf(tabuleiro[i][j], celula, "X   ");
        }
    }
}

void imprimir(char tabuleiro[tamanho][tamanho][celula]) {
    printf("  a    b   c   d   e   f   g   h\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", tamanho - i);
        for (int j = 0; j < tamanho; j++) {
            printf("%s", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[tamanho][tamanho][celula];

    inicializar(tabuleiro);
    imprimir(tabuleiro);

    return 0;
}
