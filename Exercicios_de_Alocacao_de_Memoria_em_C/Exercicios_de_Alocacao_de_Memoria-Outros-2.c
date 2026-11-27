/* 

2) Aplicação de um valor financeiro:
> Solicitar um valor Inicial em Reais
> Solicitar o número de meses em que o valor inicial deve ficar aplicado
> Solicitar o percentual de juros a ser aplicado mensalmente
Declarar um ponteiro float, e alocar dinamicamente o número de meses que foram
inormados.
Preencher a primeira ocorrência do vetor com o valor inicial que foi informado e, a
seguir, ir aplicando o percentual de juros sobre o valor, em todas as ocorrências
seguintes.
Ao final, imprimir todo o vetor, exibindo na tela cada um dos valores mensais.

*/

/*
 * Exercício 2 — Aplicação financeira mensal
 *
 * Compile com:
 *   gcc Exercicio_Aloca-2.c -o Exercicio_Aloca-2.exe -Wall -Wextra -g
 */

#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    double valorInicial = lerDouble("Valor inicial (R$): ");
    int    meses        = lerInt   ("Numero de meses:     ");
    double taxaPct      = lerDouble("Juros mensal (%):    ");

    if (meses <= 0) { printf("Numero de meses invalido.\n"); return 1; }
    if (valorInicial < 0) { printf("Valor inicial invalido.\n"); return 1; }

    /* o enunciado pede explicitamente ponteiro float */
    float *v = malloc((size_t)meses * sizeof(float));
    if (v == NULL) { printf("Falha na alocacao.\n"); return 1; }

    float fator = (float)(1.0 + taxaPct / 100.0);
    v[0] = (float)valorInicial;
    for (int i = 1; i < meses; i++)
        v[i] = v[i - 1] * fator;

    printf("\nEvolucao mensal:\n");
    for (int i = 0; i < meses; i++)
        printf("Mes %2d: R$ %.2f\n", i + 1, v[i]);

    free(v);
    return 0;
}