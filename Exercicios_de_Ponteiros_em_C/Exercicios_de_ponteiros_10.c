/* 10. Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor
lido. */

#include <stdio.h>

int main(void) {
    int v[5];
    int *p = v;

    printf("Digite 5 inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", p + i);
    }

    printf("Dobro de cada valor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", 2 * (*(p + i)));
    }
    printf("\n");

    return 0;
}