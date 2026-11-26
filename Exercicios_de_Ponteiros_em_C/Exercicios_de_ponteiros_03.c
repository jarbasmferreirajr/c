/* 3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do
teclado. Em seguida,compare seus endereços e exiba o conteúdo do maior endereço. */

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &a, &b);

    int *maior;

    if ((uintptr_t)&a > (uintptr_t)&b)
        maior = &a;
    else
        maior = &b;

    printf("Conteudo do maior endereco: %d\n", *maior);

    return 0;
}