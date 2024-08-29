

#include <stdio.h>
#include <string.h>
#define tamanho 8
#define celula 5
void inicializar(char tabuleiro[tamanho][tamanho][celula]) {
    const char* brancas[] = {"BT1 ", "BC2 ", "BB3 ", "BD4 ", "BR5 ", "BB6 ", "BC7 ", "BT8 "};
    const char* pretas[] = {"PT1 ", "PC2 ", "PB3 ", "PR4 ", "PD5 ", "PB6 ", "PC7 ", "PT8 "};
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
    printf("---------------------------------\n");
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