/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Resolução bubblesort   *
* Data - 02/10/2024                                              * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/

#include <stdio.h>

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função que implementa o Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Trocar arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função principal
int main() {
    int n;

    // Solicita ao usuário a quantidade de números
    printf("Digite a quantidade de números que deseja inserir: ");
    scanf("%d", &n);

    // Declara um array para armazenar os números
    int arr[n];

    // Solicita a entrada dos números
    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Mostra o array original
    printf("Array original:\n");
    imprimirArray(arr, n);

    // Classifica o array usando Bubble Sort
    bubbleSort(arr, n);

    // Mostra o array ordenado
    printf("Array ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}
