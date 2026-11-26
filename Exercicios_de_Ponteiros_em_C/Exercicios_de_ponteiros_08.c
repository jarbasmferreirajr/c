/* 8. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereço de cada posição desse array. */

#include <stdio.h>

int main(void) {
    float v[10];

    for (int i = 0; i < 10; i++) {
        printf("Endereco de v[%d]: %p\n", i, (void *)&v[i]);
    }

    return 0;
}