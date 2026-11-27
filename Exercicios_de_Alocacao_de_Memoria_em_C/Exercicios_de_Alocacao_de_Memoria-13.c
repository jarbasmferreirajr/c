/*
 * Exercício 13 — Alocação dinâmica de memória
 *
 * Lê dimensões de uma matriz de inteiros, aloca dinamicamente,
 * lê os valores e usa uma função que retorna 1 se um valor
 * estiver na matriz, ou 0 caso contrário.
 *
 * Compile com:
 *   gcc Exercicios_de_Alocacao_de_Memoria-13.c -o Exercicios_de_Alocacao_de_Memoria-13.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/* Lê um inteiro com validação.                                       */
/* Limpa o buffer em caso de erro, então entradas como "846+"         */
/* viram "valor invalido, tente de novo" em vez de envenenar o scanf. */
/* ------------------------------------------------------------------ */
static int lerInt(const char *prompt) {
    int x;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1) {
            /* consome resto da linha (o '\n' e qualquer lixo após o número) */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            return x;
        }
        printf("  valor invalido, tente de novo.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

/* ------------------------------------------------------------------ */
/* Retorna 1 se 'valor' está na matriz, 0 caso contrário.             */
/* ------------------------------------------------------------------ */
static int busca(int **m, int l, int c, int valor) {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] == valor) return 1;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Libera a matriz alocada dinamicamente.                             */
/* ------------------------------------------------------------------ */
static void liberaMatriz(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; i++) free(m[i]);
    free(m);
}

int main(void) {
    /* ---------- 1) dimensões ---------- */
    int l = lerInt("Linhas: ");
    int c = lerInt("Colunas: ");
    if (l <= 0 || c <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    /* ---------- 2) alocação dinâmica ---------- */
    int **m = malloc((size_t)l * sizeof(int *));
    if (m == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }
    for (int i = 0; i < l; i++) {
        m[i] = malloc((size_t)c * sizeof(int));
        if (m[i] == NULL) {
            liberaMatriz(m, i);   /* libera só as linhas já alocadas */
            printf("Falha na alocacao.\n");
            return 1;
        }
    }

    /* ---------- 3) leitura dos valores ---------- */
    printf("\nDigite os %d valores da matriz %dx%d:\n", l * c, l, c);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            char prompt[32];
            snprintf(prompt, sizeof prompt, "m[%d][%d] = ", i, j);
            m[i][j] = lerInt(prompt);
        }
    }

    /* ---------- 4) echo da matriz (opcional, ajuda a depurar) ---------- */
    printf("\nMatriz lida:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            printf("%6d ", m[i][j]);
        printf("\n");
    }

    /* ---------- 5) busca ---------- */
    int valor = lerInt("\nValor a buscar: ");
    int achou = busca(m, l, c, valor);
    printf("\nResultado da busca: %d  (%s)\n",
           achou, achou ? "encontrado" : "nao encontrado");

    /* ---------- 6) liberação ---------- */
    liberaMatriz(m, l);
    return 0;
}