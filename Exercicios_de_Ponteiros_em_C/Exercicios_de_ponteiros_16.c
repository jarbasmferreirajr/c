/* 16. Escreva um programa que declare um array de inteiros e um ponteiro para inteiros.
Associe o ponteiro ao array. Agora, some mais um (+1) a cada posição do array usando o
ponteiro (use *). */

#include <stdio.h>

int main(void) {
    int v[5] = {1, 2, 3, 4, 5};
    int *p = v;

    for (int i = 0; i < 5; i++) {
        *(p + i) += 1;
    }

    printf("Array apos somar 1 em cada posicao:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}