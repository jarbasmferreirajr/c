/* 5. Faça um programa que leia dois valores inteiros e chame uma função que receba
ponteiros destes 2 valores de entrada e devolva o maior valor na primeira variável e o menor
valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela. */

#include <stdio.h>

void maior_menor(int *a, int *b) {
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(void) {
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &a, &b);

    maior_menor(&a, &b);

    printf("Maior na primeira: %d\n", a);
    printf("Menor na segunda: %d\n", b);

    return 0;
}