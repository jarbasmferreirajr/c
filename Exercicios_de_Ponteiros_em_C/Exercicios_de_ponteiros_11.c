/* 11. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares. */

#include <stdio.h>

int main(void) {
    int v[5];
    int *p;

    printf("Digite 5 inteiros:\n");
    for (p = v; p < v + 5; p++) {
        scanf("%d", p);
    }

    printf("Enderecos das posicoes com valores pares:\n");
    for (p = v; p < v + 5; p++) {
        if (*p % 2 == 0) {
            printf("Valor %d -> endereco %p\n", *p, (void *)p);
        }
    }

    return 0;
}