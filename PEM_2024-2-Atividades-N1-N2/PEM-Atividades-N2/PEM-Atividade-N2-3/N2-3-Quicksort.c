/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: QuickSort      *
* Data - 18/10/2024                                               * 
* Autor: Davi Gabriel Ribeiro Munhoz                      *
*--------------------------------------------------------*/
#include <stdio.h>

// Função para trocar os valores de duas posições do array
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para dividir o array em torno do pivô
int particiona(int arr[], int baixo, int alto) {
    int pivô = arr[alto]; // Escolhe o último elemento como pivô
    int i = (baixo - 1); // Índice do menor elemento

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivô) {
            i++; // Incrementa o índice do menor elemento
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função principal do Quicksort
void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Encontra o índice de partição
        int pi = particiona(arr, baixo, alto);

        // Chama o quicksort recursivamente para as duas partes
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

// Função para imprimir o array
void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(arr, n);
    
    return 0;
}

