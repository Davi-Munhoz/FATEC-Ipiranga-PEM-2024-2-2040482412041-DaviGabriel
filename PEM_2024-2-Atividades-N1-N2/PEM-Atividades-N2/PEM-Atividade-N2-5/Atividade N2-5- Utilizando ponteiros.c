/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Simular o sistema de uma loja  *
* Data - 01/11/2024                                              * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/

#include <stdio.h>

#define NOME_MAX 50
#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[NOME_MAX];
    int quantidade;
    double valor;
} produto;

void exibirMenu();
void cadastrarProduto(produto *produtos, int *total);
void alterarProduto(produto *produtos, int total);
void consultarProduto(produto *produtos, int total);
void excluirProduto(produto *produtos, int *total);
void imprimirProduto(const produto *produto);

int main() {
    produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;
    do {
        printf("========= Hitech Store =========\n");
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("============================\n");
        switch(opcao) {
            case 1: cadastrarProduto(produtos, &totalProdutos); 
            break;
            case 2: alterarProduto(produtos, totalProdutos); 
            break;
            case 3: consultarProduto(produtos, totalProdutos); 
            break;
            case 4: excluirProduto(produtos, &totalProdutos); 
            break;
            case 5: printf("Saindo....\n"); 
            printf("Obrigado por usar nosso sistema!");
            break;
            default: printf("Opção Inválida!\n"); 
            break;
        }
    } while(opcao != 5);
    return 0;
}

void exibirMenu() {
    printf("[1] Cadastrar produto.\n");
    printf("[2] Alterar Produto cadastrado.\n");
    printf("[3] Consultar um produto.\n");
    printf("[4] Excluir produto cadastrado.\n");
    printf("[5] Sair do programa.\n");
}

void cadastrarProduto(produto *produtos, int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    produto *p = &produtos[*total];
    printf("Digite o código do produto: ");
    scanf("%d", &p->id);
    printf("Digite o nome do produto: ");
    scanf("%s", p->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%lf", &p->valor);
    (*total)++;
}

void alterarProduto(produto *produtos, int total) {
    int id;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &id);
    for(int i = 0; i < total; i++) {
        if(produtos[i].id == id) {
            printf("Novo nome: ");
            scanf("%s", produtos[i].nome);
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);
            printf("Novo valor: ");
            scanf("%lf", &produtos[i].valor);
            printf("Produto alterado!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void consultarProduto(produto *produtos, int total) {
    int id;
    printf("Digite o ID do produto que deseja consultar: ");
    scanf("%d", &id);
    for(int i = 0; i < total; i++) {
        if(produtos[i].id == id) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void excluirProduto(produto *produtos, int *total) {
    int id;
    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);
    for(int i = 0; i < *total; i++) {
        if(produtos[i].id == id) {
            for(int j = i; j < *total - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*total)--;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void imprimirProduto(const produto *p) {
    printf("---- Dados do produto ----\n");
    printf("ID: %d\n", p->id);
    printf("Nome: %s\n", p->nome);
    printf("Quantidade em estoque: %d\n", p->quantidade);
    printf("Valor: R$%.2lf\n", p->valor);
}