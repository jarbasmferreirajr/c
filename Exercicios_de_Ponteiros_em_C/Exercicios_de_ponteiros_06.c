/* 6. Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função
que recebe o endereço destes 2 números, calcule a soma do dobro dos dois números lidos.
A função dever á armazenar o dobro de A na própria variável A e o dobro de B na própria
variável B. */

#include <stdio.h>

void dobra_e_soma(int *a, int *b) {
    int soma_dobros = 2 * (*a) + 2 * (*b);

    *a = 2 * (*a);
    *b = 2 * (*b);

    printf("Soma dos dobros: %d\n", soma_dobros);
}

int main(void) {
    int a, b;

    printf("Digite A e B: ");
    scanf("%d %d", &a, &b);

    dobra_e_soma(&a, &b);

    printf("A dobrado: %d\n", a);
    printf("B dobrado: %d\n", b);

    return 0;
}