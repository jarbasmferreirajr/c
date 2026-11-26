/* 7. Crie um programa que contenha uma função que permita passar por parâmetro o
endereço de dois números inteiros A e B. A função deverá calcular a soma entre estes dois
números e armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas
deverá modificar o valor do primeiro parâmetro. Imprima os valoresde A e B na função
principal. */

#include <stdio.h>

void soma_em_a(int *a, int *b) {
    *a = *a + *b;
}

int main(void) {
    int a, b;

    printf("Digite A e B: ");
    scanf("%d %d", &a, &b);

    soma_em_a(&a, &b);

    printf("A = %d\n", a);
    printf("B = %d\n", b);

    return 0;
}