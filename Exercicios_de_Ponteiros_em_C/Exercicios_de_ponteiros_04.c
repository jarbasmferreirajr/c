/* 4. Faça um programa que leia 2 valores inteiros e chame uma função que receba o ponteiro
destas 2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B terá o
valor de A. */

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a, b;

    printf("Digite A e B: ");
    scanf("%d %d", &a, &b);

    printf("Antes: A=%d, B=%d\n", a, b);
    troca(&a, &b);
    printf("Depois: A=%d, B=%d\n", a, b);

    return 0;
}