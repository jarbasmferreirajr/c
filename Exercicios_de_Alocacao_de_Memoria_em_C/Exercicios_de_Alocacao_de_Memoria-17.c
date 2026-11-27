/*
 * Exercício 17 — Cidades, distâncias e consulta
 *
 * Compile com:
 *   gcc Exercicios_de_Alocacao_de_Memoria-17.c -o Exercicios_de_Alocacao_de_Memoria-17.exe -Wall -Wextra -g -lm
 *
 * ATENÇÃO: precisa de -lm (biblioteca math) por causa de sqrt().
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char   nome[50];
    double x, y;
} Cidade;

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
/* Lê nome + x + y. Exige os 3 campos (retorno do scanf == 3).        */
/* Se o usuário digitar só o nome, reclama e pede de novo.            */
/* ------------------------------------------------------------------ */
static void lerCidade(Cidade *c, int idx) {
    char prompt[64];
    snprintf(prompt, sizeof prompt, "Cidade %d (nome x y): ", idx);
    while (1) {
        printf("%s", prompt);
        int ok = scanf("%49s %lf %lf", c->nome, &c->x, &c->y);
        if (ok == 3) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            return;
        }
        printf("  formato invalido. Use: Nome coordenadaX coordenadaY\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
    }
}

static double distancia(const Cidade *a, const Cidade *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

int main(void) {
    int n = lerInt("Numero de cidades: ");
    if (n <= 0) { printf("Numero invalido.\n"); return 1; }

    /* ---------- 1) vetor de cidades ---------- */
    Cidade *c = malloc((size_t)n * sizeof(Cidade));
    if (c == NULL) { printf("Falha na alocacao.\n"); return 1; }

    for (int i = 0; i < n; i++)
        lerCidade(&c[i], i);

    /* ---------- 2) matriz de distâncias ---------- */
    double **d = malloc((size_t)n * sizeof(double *));
    if (d == NULL) { free(c); return 1; }
    for (int i = 0; i < n; i++) {
        d[i] = malloc((size_t)n * sizeof(double));
        if (d[i] == NULL) {
            for (int k = 0; k < i; k++) free(d[k]);
            free(d); free(c);
            return 1;
        }
    }

    /* ---------- 3) calcular ---------- */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = distancia(&c[i], &c[j]);

    /* ---------- 4) exibir ---------- */
    printf("\nMatriz de distancias:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%10.2f ", d[i][j]);
        printf("\n");
    }

    /* ---------- 5) consulta ---------- */
    printf("\nConsulta de distancia:\n");
    int i = lerInt("  Indice cidade A: ");
    int j = lerInt("  Indice cidade B: ");
    if (i < 0 || i >= n || j < 0 || j >= n) {
        printf("Indices invalidos.\n");
    } else {
        printf("  %s -> %s : %.2f\n", c[i].nome, c[j].nome, d[i][j]);
    }

    /* ---------- 6) liberar ---------- */
    for (int k = 0; k < n; k++) free(d[k]);
    free(d);
    free(c);
    return 0;
}