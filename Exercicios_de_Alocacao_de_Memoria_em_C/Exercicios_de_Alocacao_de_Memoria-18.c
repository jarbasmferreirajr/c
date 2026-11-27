/*
 * Exercício 18 — Produto de duas matrizes alocadas dinamicamente
 *
 * Compile com:
 *   gcc Exercicios_de_Alocacao_de_Memoria-18.c -o Exercicios_de_Alocacao_de_Memoria-18.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/* Lê um inteiro com validação.                                       */
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
/* Aloca matriz l x c de int. Retorna NULL em falha.                  */
/* ------------------------------------------------------------------ */
static int **alocaMatriz(int l, int c) {
    int **m = malloc((size_t)l * sizeof(int *));
    if (m == NULL) return NULL;
    for (int i = 0; i < l; i++) {
        m[i] = malloc((size_t)c * sizeof(int));
        if (m[i] == NULL) {
            for (int k = 0; k < i; k++) free(m[k]);
            free(m);
            return NULL;
        }
    }
    return m;
}

static void liberaMatriz(int **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; i++) free(m[i]);
    free(m);
}

/* ------------------------------------------------------------------ */
/* Lê os elementos de uma matriz l x c com prompts.                   */
/* ------------------------------------------------------------------ */
static void lerMatriz(int **m, int l, int c, const char *nome) {
    printf("\nDigite os %d valores da matriz %s (%dx%d):\n", l * c, nome, l, c);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            char prompt[32];
            snprintf(prompt, sizeof prompt, "  %s[%d][%d] = ", nome, i, j);
            m[i][j] = lerInt(prompt);
        }
    }
}

static void imprimeMatriz(int **m, int l, int c, const char *titulo) {
    printf("\n%s (%dx%d):\n", titulo, l, c);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            printf("%6d ", m[i][j]);
        printf("\n");
    }
}

int main(void) {
    /* ---------- 1) dimensões ---------- */
    printf("Dimensoes das matrizes:\n");
    int a = lerInt("  a (linhas de A):   ");
    int b = lerInt("  b (colunas de A):  ");
    int c = lerInt("  c (linhas de B):   ");
    int d = lerInt("  d (colunas de B):  ");

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    /* ---------- 2) alocação ---------- */
    int **A = alocaMatriz(a, b);
    int **B = alocaMatriz(c, d);
    if (A == NULL || B == NULL) {
        liberaMatriz(A, a);
        liberaMatriz(B, c);
        printf("Falha na alocacao.\n");
        return 1;
    }

    /* ---------- 3) leitura ---------- */
    lerMatriz(A, a, b, "A");
    lerMatriz(B, c, d, "B");

    /* ---------- 4) impressão ---------- */
    imprimeMatriz(A, a, b, "Matriz A");
    imprimeMatriz(B, c, d, "Matriz B");

    /* ---------- 5) produto ---------- */
    if (b != c) {
        printf("\nO produto A x B nao existe: colunas de A (%d) != linhas de B (%d).\n", b, c);
    } else {
        int **P = alocaMatriz(a, d);
        if (P == NULL) {
            liberaMatriz(A, a);
            liberaMatriz(B, c);
            return 1;
        }

        for (int i = 0; i < a; i++)
            for (int j = 0; j < d; j++) {
                P[i][j] = 0;
                for (int k = 0; k < b; k++)
                    P[i][j] += A[i][k] * B[k][j];
            }

        imprimeMatriz(P, a, d, "Produto A x B");
        liberaMatriz(P, a);
    }

    /* ---------- 6) liberação ---------- */
    liberaMatriz(A, a);
    liberaMatriz(B, c);
    return 0;
}