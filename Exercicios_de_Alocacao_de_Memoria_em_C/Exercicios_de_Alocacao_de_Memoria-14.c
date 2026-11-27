/*
 * Exercício 14 — Alocação dinâmica de memória
 *
 * Lê o número de linhas e de colunas de uma matriz de números reais,
 * aloca espaço dinamicamente para ela, inicializa com valores
 * fornecidos pelo usuário e retorna a matriz na saída padrão com
 * layout apropriado.
 *
 * Compile com:
 *   gcc Exercicios_de_Alocacao_de_Memoria-14.c -o Exercicios_de_Alocacao_de_Memoria-14.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/* Lê um inteiro com validação (para linhas/colunas).                 */
/* ------------------------------------------------------------------ */
static int lerInt(const char *prompt) {
    int x;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1) {
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
/* Lê um double com validação (para os elementos da matriz).          */
/* ------------------------------------------------------------------ */
static double lerDouble(const char *prompt) {
    double x;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &x) == 1) {
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
/* Libera a matriz alocada dinamicamente.                             */
/* ------------------------------------------------------------------ */
static void liberaMatriz(double **m, int l) {
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
    double **m = malloc((size_t)l * sizeof(double *));
    if (m == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }
    for (int i = 0; i < l; i++) {
        m[i] = malloc((size_t)c * sizeof(double));
        if (m[i] == NULL) {
            liberaMatriz(m, i);
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
            m[i][j] = lerDouble(prompt);
        }
    }

    /* ---------- 4) impressão com layout ---------- */
    printf("\nMatriz %dx%d:\n", l, c);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            printf("%10.2f ", m[i][j]);
        printf("\n");
    }

    /* ---------- 5) liberação ---------- */
    liberaMatriz(m, l);
    return 0;
}