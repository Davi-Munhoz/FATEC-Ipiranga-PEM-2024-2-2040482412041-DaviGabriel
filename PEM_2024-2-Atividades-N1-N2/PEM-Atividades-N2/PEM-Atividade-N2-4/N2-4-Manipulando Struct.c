/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Manipulando Struct   *
* Data - 18/10/2024                                               * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Estrutura que representa um produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco_unitario;
    int quantidade_estoque;
} Produto;

// Funções utilizadas no programa
void inserirProduto(Produto *produtos, int *num_produtos);
void listarProdutos(Produto *produtos, int num_produtos);
void ordenarProdutos(Produto *produtos, int num_produtos);
void comprarProduto(Produto *produtos, int num_produtos);
Produto *buscarProduto(Produto *produtos, int num_produtos, int id);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    do {
        printf("\n---- Menu Loja de Produtos Eletrônicos ----\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &num_produtos);
                break;
            case 2:
                listarProdutos(produtos, num_produtos);
                break;
            case 3:
                comprarProduto(produtos, num_produtos);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para inserir um produto na lista
void inserirProduto(Produto *produtos, int *num_produtos) {
    if (*num_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novo_produto;
    printf("Inserir produto %d:\n", *num_produtos + 1);
    printf("ID do produto: ");
    scanf("%d", &novo_produto.id);
    printf("Nome do produto: ");
    scanf(" %[^\n]", novo_produto.nome);
    printf("Descricao do produto: ");
    scanf(" %[^\n]", novo_produto.descricao);
    printf("Preco unitario: ");
    scanf("%f", &novo_produto.preco_unitario);
    printf("Quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade_estoque);

    produtos[*num_produtos] = novo_produto;
    (*num_produtos)++;

    printf("Produto inserido com sucesso!\n");
}

// Função para listar os produtos na tela, em ordem alfabética
void listarProdutos(Produto *produtos, int num_produtos) {
    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    ordenarProdutos(produtos, num_produtos);

    printf("\n---- Lista de Produtos ----\n");
    for (int i = 0; i < num_produtos; i++) {
        printf("ID: %d | Nome: %s | Descricao: %s | Preco: %.2f | Estoque: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco_unitario, produtos[i].quantidade_estoque);
    }
}

// Função para ordenar os produtos por nome (Bubble Sort)
void ordenarProdutos(Produto *produtos, int num_produtos) {
    for (int i = 0; i < num_produtos - 1; i++) {
        for (int j = 0; j < num_produtos - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// Função para simular a compra de um produto
void comprarProduto(Produto *produtos, int num_produtos) {
    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int id, quantidade;
    printf("Digite o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    Produto *produto = buscarProduto(produtos, num_produtos, id);
    if (produto == NULL) {
        printf("Produto inexistente.\n");
        return;
    }

    printf("Quantidade que deseja comprar: ");
    scanf("%d", &quantidade);

    if (quantidade > produto->quantidade_estoque) {
        printf("Quantidade insuficiente em estoque!\n");
    } else {
        produto->quantidade_estoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: R$ %.2f\n", quantidade * produto->preco_unitario);
    }
}

// Função para buscar um produto pelo ID
Produto *buscarProduto(Produto *produtos, int num_produtos, int id) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].id == id) {
            return &produtos[i];
        }
    }
    return NULL;
}