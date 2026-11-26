/*1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada
variável usando os ponteiros.Imprima os valores das variáveis antes e após a modificação.*/

#include <stdio.h>

int main(void) {
    /* Declaração das variáveis */
    int    i = 10;
    float  f = 1.5f;
    char   c = 'A';

    /* Declaração dos ponteiros */
    int   *pi = NULL;
    float *pf = NULL;
    char  *pc = NULL;

    /* Associação dos ponteiros às variáveis (uso de &) */
    pi = &i;
    pf = &f;
    pc = &c;

    /* Impressão dos valores ANTES da modificação */
    printf("===== ANTES da modificacao =====\n");
    printf("Inteiro : %d\n", i);
    printf("Real    : %.2f\n", f);
    printf("Char    : %c\n", c);
    printf("\n");

    /* Modificação dos valores através dos ponteiros */
    *pi = 42;
    *pf = 3.14f;
    *pc = 'Z';

    /* Impressão dos valores DEPOIS da modificação */
    printf("===== DEPOIS da modificacao =====\n");
    printf("Inteiro : %d\n", i);
    printf("Real    : %.2f\n", f);
    printf("Char    : %c\n", c);
    printf("\n");

    return 0;
}