/*

1) Preencher um vetor de inteiros
Criar um programa que leia do usuario o tamanho de um vetor a ser alocado, e
faça a alocação dinamica de memoria em um ponteiro numérico.
Em seguida, uma função vai solicitar o primeiro numero do vetor e preencher
todo o vetor, somando sempre dois (2) ao numero anterior.
Imprima, ao final, todo o vetor preenchido.

*/

/*
 * Exercício 1 — Preencher vetor somando 2
 *
 * Compile com:
 *   gcc Exercicio_Aloca-1.c -o Exercicio_Aloca-1.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

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

static void preencheVetor(int *v, int n)
{
    int primeiro = lerInt("\nDigite o primeiro numero: ");
    v[0] = primeiro;
    for (int i = 1; i < n; i++)
        v[i] = v[i - 1] + 2;
}

int main(void)
{
    int n = lerInt("Tamanho do vetor: ");
    if (n <= 0)
    {
        printf("Tamanho invalido.\n");
        return 1;
    }

    int *v = malloc((size_t)n * sizeof(int));
    if (v == NULL)
    {
        printf("Falha na alocacao.\n");
        return 1;
    }

    preencheVetor(v, n);

    printf("\nVetor preenchido:\n");
    for (int i = 0; i < n; i++)
        printf("v[%d] = %d\n", i, v[i]);

    free(v);
    return 0;
}