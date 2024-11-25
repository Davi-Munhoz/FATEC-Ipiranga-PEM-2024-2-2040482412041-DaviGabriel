/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Administrar os produtos de uma loja de produtos eletrônicos*
* Data - 25/11/2024                                              * 
* Autor: Davi Gabriel Ribeiro Munhoz*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 500
#define NOME_MAX 50
#define DESCRICAO_MAX 100

typedef struct {
    int id;
    char nome[NOME_MAX];
    char descricao[DESCRICAO_MAX];
    float precoUnitario; // Usar float para valores monetários
    int qteDispo;
} Produto;

void inserirProduto(Produto *produtos, int *cont);
void consultarProduto(Produto *produtos, int cont);
void alterarProduto(Produto *produtos, int cont);
void excluirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void comprarProduto(Produto *produtos, int cont);
void imprimirProduto(Produto *produto);
int isNumero(char *str);
int buscarProdutoPorId(Produto *produtos, int cont, int id);
void limparBuffer();
int confirmarAcao(char *acao);
int confirmarDesconto(); // Função de confirmação para o desconto

int main() {
    Produto produtos[MAX_PRODUTOS]; // Array para armazenar até 500 produtos
    int cont = 0; // Contador de produtos
    int opcao;

    do {
        printf("\n=====Loja Hitech=====:\n");
        printf("========Menu=========:\n");
        printf("\n1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Consultar produto\n");
        printf("4. Alterar produto\n");
        printf("5. Excluir produto\n");
        printf("6. Comprar produto\n");
        printf("7. Sair\n");

        // Verificação de entrada da opção
        do {
            printf("\nEscolha uma opcao (1 a 7): ");
            if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 7) {
                printf("Opcao invalida! Tente novamente.\n");
                limparBuffer(); // Limpar o buffer de entrada
            }
        } while (opcao < 1 || opcao > 7);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                consultarProduto(produtos, cont);
                break;
            case 4:
                alterarProduto(produtos, cont);
                break;
            case 5:
                excluirProduto(produtos, &cont);
                break;
            case 6:
                comprarProduto(produtos, cont);
                break;
            case 7:
                printf("Saindo...\n");
                printf("Obrigado por usar nosso sistema!\n");
                break;
        }
    } while (opcao != 7);

    return 0;
}

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont < MAX_PRODUTOS) { // Verifica se há espaço no array
        Produto novoProduto;
        char idStr[10];  // Usado para capturar a entrada do ID como string

        printf("Informe o ID do produto (somente numeros): ");
        while (1) {
            scanf("%s", idStr);
            if (isNumero(idStr)) {
                novoProduto.id = atoi(idStr);
                if (buscarProdutoPorId(produtos, *cont, novoProduto.id) == -1) {
                    break;
                } else {
                    printf("ID ja existe. Tente outro ID: ");
                }
            } else {
                printf("ID invalido. Somente numeros sao permitidos. Tente novamente: ");
            }
        }

        printf("Informe o nome do produto: ");
        scanf(" %[^\n]", novoProduto.nome); // Lê string com espaços
        printf("Informe a descricao do produto: ");
        scanf(" %[^\n]", novoProduto.descricao);

        // Garantir que o preço unitário seja um número válido
        while (1) {
            printf("Informe o preco unitario (somente numero): R$");
            if (scanf("%f", &novoProduto.precoUnitario) == 1) {
                break;
            } else {
                printf("Preco invalido. Tente novamente.\n");
                while(getchar() != '\n'); // Limpar o buffer
            }
        }

        // Garantir que a quantidade disponível seja um número válido
        while (1) {
            printf("Informe a quantidade disponivel (somente numero): ");
            if (scanf("%d", &novoProduto.qteDispo) == 1) {
                break;
            } else {
                printf("Quantidade invalida. Tente novamente.\n");
                while(getchar() != '\n'); // Limpar o buffer
            }
        }

        produtos[*cont] = novoProduto; // Adiciona o novo produto ao array
        (*cont)++; // Incrementa o contador
        printf("Produto inserido com sucesso!\n");
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

void listarProdutos(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("\n=====Loja Hitech=====:\n");
    printf("\n==Lista de Produtos:==\n");
    for (int i = 0; i < cont; i++) {
        imprimirProduto(&produtos[i]);
    }
}

void imprimirProduto(Produto *produto) {
    printf("ID: %d, Nome: %s, Descricao: %s, Preco: R$%.2f, Estoque: %d\n", 
        produto->id, produto->nome, produto->descricao, produto->precoUnitario, produto->qteDispo);
}

void consultarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja consultar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void alterarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Novo nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Nova descricao do produto: ");
            scanf(" %[^\n]", produtos[i].descricao);
            printf("Novo preco unitario: R$");
            scanf("%f", &produtos[i].precoUnitario);
            printf("Nova quantidade disponivel: ");
            scanf("%d", &produtos[i].qteDispo);
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void excluirProduto(Produto *produtos, int *cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja excluir: ");
    scanf("%d", &idProduto);

    int idx = buscarProdutoPorId(produtos, *cont, idProduto);
    if (idx != -1) {
        // Confirmação antes de excluir
        if (confirmarAcao("excluir o produto")) {
            for (int i = idx; i < *cont - 1; i++) {
                produtos[i] = produtos[i + 1]; // Move os produtos para preencher o espaço
            }
            (*cont)--; // Decrementa o contador
            printf("Produto excluido com sucesso!\n");
        } else {
            printf("Exclusao cancelada.\n");
        }
    } else {
        printf("Produto inexistente.\n");
    }
}

void comprarProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado para compra.\n");
        return;
    }

    int idProduto, quantidade;
    float descontoPorcentagem = 0.0f;
    int aplicarDesconto;

    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    int idx = buscarProdutoPorId(produtos, cont, idProduto);
    if (idx != -1) {
        printf("Informe a quantidade que deseja comprar: ");
        scanf("%d", &quantidade);

        if (quantidade > produtos[idx].qteDispo) {
            printf("Estoque insuficiente. Apenas %d disponiveis.\n", produtos[idx].qteDispo);
        } else {
            // Exibe o resumo da compra
            printf("Produto: %s\n", produtos[idx].nome);
            printf("Quantidade: %d\n", quantidade);
            float total = produtos[idx].precoUnitario * quantidade;
            printf("Total: R$%.2f\n", total);

            // Pergunta se o usuário deseja aplicar um desconto em porcentagem
            aplicarDesconto = confirmarDesconto();
            if (aplicarDesconto) {
                printf("Informe o valor do desconto em porcentagem (exemplo: 10 para 10%%): ");
                scanf("%f", &descontoPorcentagem);
                if (descontoPorcentagem >= 0 && descontoPorcentagem <= 100) {
                    float desconto = total * (descontoPorcentagem / 100);
                    total -= desconto; // Aplica o desconto
                    printf("Desconto de %.2f%% aplicado. Valor do desconto: R$%.2f\n", descontoPorcentagem, desconto);
                } else {
                    printf("Desconto invalido. Nenhum desconto aplicado.\n");
                }
            }

            // Exibe o valor final
            printf("Total final: R$%.2f\n", total);

            // Confirmação antes de realizar a compra
            if (confirmarAcao("comprar o produto")) {
                produtos[idx].qteDispo -= quantidade; // Atualiza a quantidade disponível
                printf("Compra realizada com sucesso!\n");
                printf("Muito obrigado pela preferência!\n");
            } else {
                printf("Compra cancelada.\n");
            }
        }
    } else {
        printf("Produto inexistente.\n");
    }
}

int buscarProdutoPorId(Produto *produtos, int cont, int id) {
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == id) {
            return i;
        }
    }
    return -1;
}

int isNumero(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void limparBuffer() {
    while(getchar() != '\n'); // Limpar o buffer
}

int confirmarAcao(char *acao) {
    char resposta;
    printf("Tem certeza que deseja %s? (S/N): ", acao);
    while (1) {
        scanf(" %c", &resposta);
        if (tolower(resposta) == 's') {
            return 1;
        } else if (tolower(resposta) == 'n') {
            return 0;
        } else {
            printf("Opcao invalida! Por favor, digite 'S' para sim ou 'N' para nao: ");
        }
    }
}

int confirmarDesconto() {
    char resposta;
    printf("Deseja aplicar um desconto? (S/N): ");
    while (1) {
        scanf(" %c", &resposta);
        if (tolower(resposta) == 's') {
            return 1;
        } else if (tolower(resposta) == 'n') {
            return 0;
        } else {
            printf("Opcao invalida! Por favor, digite 'S' para sim ou 'N' para nao: ");
        }
    }
}
