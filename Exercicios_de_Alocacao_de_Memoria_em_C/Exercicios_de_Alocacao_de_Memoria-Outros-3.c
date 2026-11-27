/*

3) Criando uma lista dinamicamente:
struct Lista
{
int anterior;
int codigo;
int próximo
};
> Criar um Menu com opções de Incluir e Listar
> Utilizando a estrutura acima, criar uma variável, do tipo ponteiro, para essa
estrutura
> Alocar memória na variável do tipo ponteiro para uma estrutura de cada vez
> A lista inicia com os campos zerados, e o código é solicitado na tela
> A cada nova inclusão, incrementar o tamanho alocado para a estrutura, solicitar
o código na tela e indexar os campos "anterior" e "próximo" com os códigos da
estrutura anterior e da próxima.

*/

/*
 * Exercício 3 — Lista dinâmica com struct
 *
 * struct Lista { int anterior; int codigo; int proximo; }
 * - "anterior" e "proximo" guardam os CÓDIGOS dos vizinhos (não ponteiros)
 * - A lista cresce 1 struct por vez via realloc
 *
 * Compile com:
 *   gcc Exercicio_Aloca-3.c -o Exercicio_Aloca-3.exe -Wall -Wextra -g
 */

/*
 * Exercício 3 — Lista dinâmica com struct
 *
 * struct Lista { int anterior; int codigo; int proximo; }
 *
 * - Menu com opções: Incluir, Listar, Sair
 * - A lista cresce 1 struct por vez via realloc
 * - "anterior" e "proximo" guardam os CÓDIGOS dos vizinhos
 * - Sentinela 0 = "não existe" (primeiro não tem anterior, último não tem próximo)
 *
 * Compile com:
 *   gcc Exercicios_de_Alocacao_de_Memoria-Outros-3.c -o Exercicios_de_Alocacao_de_Memoria-Outros-3.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int anterior;
    int codigo;
    int proximo;
} Lista;

/* ------------------------------------------------------------------ */
/* Lê um inteiro com validação.                                       */
/* ------------------------------------------------------------------ */
static int lerInt(const char *prompt)
{
    int x;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            return x;
        }
        printf("  valor invalido, tente de novo.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }
}

/* ------------------------------------------------------------------ */
/* Inclui um novo elemento no fim da lista.                           */
/*  - cresce o vetor em 1 struct (realloc)                            */
/*  - lê o código                                                     */
/*  - ajusta "anterior" do novo e "proximo" do anterior               */
/* ------------------------------------------------------------------ */
static void incluir(Lista **lista, int *n)
{
    /* 1) cresce o bloco em 1 struct */
    Lista *tmp = realloc(*lista, (size_t)(*n + 1) * sizeof(Lista));
    if (tmp == NULL)
    {
        printf("Falha na alocacao.\n");
        return; /* *lista continua válido; realloc em falha não libera */
    }
    *lista = tmp;

    /* 2) lê o código do novo elemento */
    int codigo = lerInt("Digite o codigo: ");

    /* 3) preenche o novo elemento */
    Lista *novo = &(*lista)[*n];
    novo->codigo = codigo;
    novo->proximo = 0; /* ainda não tem próximo */

    if (*n == 0)
    {
        novo->anterior = 0; /* primeiro elemento da lista */
    }
    else
    {
        novo->anterior = (*lista)[*n - 1].codigo;
        (*lista)[*n - 1].proximo = codigo;
    }

    (*n)++;
}

/* ------------------------------------------------------------------ */
/* Lista todos os elementos em formato de tabela.                     */
/* ------------------------------------------------------------------ */
static void listar(Lista *lista, int n)
{
    if (n == 0)
    {
        printf("\nLista vazia.\n");
        return;
    }
    printf("\n%-10s %-10s %-10s\n", "anterior", "codigo", "proximo");
    printf("%-10s %-10s %-10s\n", "--------", "------", "-------");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-10d %-10d\n",
               lista[i].anterior,
               lista[i].codigo,
               lista[i].proximo);
    }
}

/* ------------------------------------------------------------------ */
/* Menu principal.                                                    */
/* ------------------------------------------------------------------ */
int main(void)
{
    Lista *lista = NULL;
    int n = 0;

    while (1)
    {
        printf("\n1 - Incluir\n2 - Listar\n0 - Sair\n");
        int op = lerInt("Opcao: ");

        switch (op)
        {
        case 0:
            free(lista);
            printf("Saindo...\n");
            return 0;
        case 1:
            incluir(&lista, &n);
            break;
        case 2:
            listar(lista, n);
            break;
        default:
            printf("Opcao invalida.\n");
        }
    }
}