/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Melhoria do bubblesort apresentado  *
* Data - 02/10/2024                                              * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100 // Definindo um limite máximo para o array

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0; // Inicializa o flag

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1; // Indica que houve uma troca
            }
        }

        // Se não houve troca, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_NUM];
    int n = 0;
    char input[20]; // Para armazenar a entrada do usuário

    // Solicita a entrada dos números
    printf("Digite os números que deseja ordenar (digite 'sair' para finalizar):\n");

    while (1) {
        scanf("%s", input); // Lê a entrada como string

        if (strcmp(input, "sair") == 0) {
            break; // Encerra a entrada se o usuário digitar "sair"
        }

        // Converte a string para um número inteiro
        int num = atoi(input);

        if (n >= MAX_NUM) {
            printf("Número máximo de elementos atingido!\n");
            break;
        }

        arr[n] = num; // Armazena o número no array
        n++; // Incrementa o contador de elementos
    }

    if (n > 0) { // Verifica se houve alguma entrada
        printf("Array original:\n");
        printArray(arr, n);
        
        bubbleSort(arr, n);
        
        printf("Array ordenado:\n");
        printArray(arr, n);
    } else {
        printf("Nenhum número foi inserido!\n");
    }

    return 0;
}
