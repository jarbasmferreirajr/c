/* 

12. Considere um cadastro de produtos de um estoque, com as seguintes informações
para cada produto:
• Codigo de identificação do produto: representado por um valor inteiro
• Nome do produto: com ate 50 caracteres
• Quantidade disponível no estoque: representado por um número inteiro
• Preço de venda: representado por um valor real
(a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para
guardar as informações de um produto.
(b) Crie um conjunto de N produtos (N é um valor fornecido pelo usuário) alocando
memória dinamicamente, e peça ao usuário para entrar com as informações de cada
produto.
(c) Encontre o produto com o maior preço de venda.
(d) Encontre o produto com a maior quantidade disponível no estoque.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[51];
    int quantidade;
    float preco;
} Produto;

int main(void) {
    int n;
    printf("Numero de produtos: ");
    scanf("%d", &n);

    Produto *p = malloc(n * sizeof(Produto));
    if (p == NULL) return 1;

    for (int i = 0; i < n; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &p[i].codigo);
        printf("Nome: ");
        scanf("%50s", p[i].nome);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        printf("Preco: ");
        scanf("%f", &p[i].preco);
    }

    int idxPreco = 0, idxQtd = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].preco > p[idxPreco].preco) idxPreco = i;
        if (p[i].quantidade > p[idxQtd].quantidade) idxQtd = i;
    }

    printf("\nMaior preco: %s (R$ %.2f)\n", p[idxPreco].nome, p[idxPreco].preco);
    printf("Maior quantidade: %s (%d)\n", p[idxQtd].nome, p[idxQtd].quantidade);

    free(p);
    return 0;
}