#include <stdio.h>
#include <stdlib.h>

#define Notas_máximas 100
#define Testes_máximos 10


float NotaFinal(float notas[], int n) {
    float soma = 0.0;
    float maior = notas[0];
    float menor = notas[0];
    int maiorContagem = 0;
    int menorContagem = 0;


    for (int i = 0; i < n; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    
   
    for (int i = 0; i < n; i++) {
        if (notas[i] == maior) {
            maiorContagem++;
        }
        if (notas[i] == menor) {
            menorContagem++;
        }
    }
    
   
    int excluirMaior = 0;
    int excluirMenor = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] == maior && !excluirMaior) {
            excluirMaior = 1;
        } else if (notas[i] == menor && !excluirMenor) {
            excluirMenor = 1;
        } else {
            soma += notas[i];
        }
    }
    
    return soma;
}

int main() {
    int n;
    float notas[Notas_máximas];
    float Final[Testes_máximos];
    float notaFinalTotal = 0.0;
    int numerodeteste = 0;
    char* nomeTestes[] = {
        "Raciocínio lógico",
        "conceitos de gerenciamento de projetos",
        "lingua inglesa",
        "conceitos de metodologia ágil",
        "linguagem javascript"
    };

    while (1) {
        printf("Digite o número de notas (0 para encerrar): ");
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        printf("Digite as %d notas separadas por espaço: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%f", &notas[i]);
        }
        
        if (numerodeteste < Testes_máximos) {
            Final[numerodeteste] = NotaFinal(notas, n);
            numerodeteste++;
        }
    }
    
  
    for (int i = 0; i < numerodeteste; i++) {
        if (i < 5) { // Limitar a 5 testes de acordo com o exemplo
            printf("Nota %s = %.0f\n", nomeTestes[i], Final[i]);
        }
        notaFinalTotal += Final[i];
    }
    

    printf("Nota final do candidato = %.0f\n", notaFinalTotal);
    
    return 0;
}
