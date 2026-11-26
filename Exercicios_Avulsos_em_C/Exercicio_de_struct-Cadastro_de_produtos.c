#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 1. Declaração da struct (antes das funções) */
struct produto
{
    int codigo;
    char nome[30];
    float preco;
};

/* Função auxiliar: imprime um float com vírgula no lugar do ponto */
void imprimir_preco(float preco)
{
    char buf[32];
    sprintf(buf, "%.2f", preco); /* formata com ponto: "12.00" */

    char *ponto = strchr(buf, '.');
    if (ponto != NULL)
    {
        *ponto = ','; /* troca por vírgula: "12,00" */
    }
    printf("%s", buf);
}

/* 2. Lê um produto do teclado e devolve a struct preenchida */
struct produto ler(void)
{
    struct produto p;

    printf("Codigo: ");
    scanf("%d", &p.codigo);

    printf("Nome: ");
    scanf(" %29[^\n]", p.nome); /* aceita espaços no nome */

    printf("Preco: ");
    char buf[32];
    scanf(" %31s", buf); /* lê como texto: "12,50" ou "12.50" */

    char *virgula = strchr(buf, ',');
    if (virgula != NULL)
    {
        *virgula = '.'; /* normaliza para ponto */
    }
    p.preco = atof(buf); /* converte texto → float */

    return p;
}

/* 3. Exibe um produto na tela (preço com vírgula) */
void exibir(struct produto p)
{
    printf("%d - %s - R$ ", p.codigo, p.nome);
    imprimir_preco(p.preco);
    printf("\n");
}

/* 4. Devolve o índice do produto de maior preço */
int indiceMaisCaro(struct produto lista[], int n)
{
    int i, indice = 0;
    for (i = 1; i < n; i++)
    {
        if (lista[i].preco > lista[indice].preco)
        {
            indice = i;
        }
    }
    return indice;
}

/* 5. main */
int main(void)
{
    struct produto estoque[4];
    int i, mais_caro;

    printf("--- Cadastro ---\n");
    for (i = 0; i < 4; i++)
    {
        printf("\nProduto %d:\n", i + 1);
        estoque[i] = ler();
    }

    printf("\n--- Produtos cadastrados ---\n");
    for (i = 0; i < 4; i++)
    {
        exibir(estoque[i]);
    }

    mais_caro = indiceMaisCaro(estoque, 4);

    printf("\nProduto mais caro:\n");
    exibir(estoque[mais_caro]);

    return 0;
}