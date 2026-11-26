/* 12. Faça um programa que leia três valores inteiros e chame uma função que receba estes 3
valores de entrada e ordene esses valores nas variáveis recebidas, ou seja, o menor valor na
primeira variável, o segundo menor valor na variável do meio, e o maior valor na ultima
variável. A função deve retornar o valor 1 se os três valores forem iguais e 0 se existirem
valores diferentes. Exibir os valores ordenados na tela. */

#include <stdio.h>

int ordena3(int *a, int *b, int *c) {
    int iguais = (*a == *b && *b == *c);

    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }

    return iguais ? 1 : 0;
}

int main(void) {
    int a, b, c;

    printf("Digite tres inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    int retorno = ordena3(&a, &b, &c);

    printf("Valores ordenados: %d %d %d\n", a, b, c);
    printf("Retorno: %d\n", retorno);

    return 0;
}