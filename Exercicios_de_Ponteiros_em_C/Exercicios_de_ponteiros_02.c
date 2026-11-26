/* 2. Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e
exiba na tela o maior endereço. */

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &a, &b);

    uintptr_t ea = (uintptr_t)&a;
    uintptr_t eb = (uintptr_t)&b;

    if (ea > eb)
        printf("Maior endereco: %p (variavel a)\n", (void *)&a);
    else if (eb > ea)
        printf("Maior endereco: %p (variavel b)\n", (void *)&b);
    else
        printf("Enderecos iguais\n");

    return 0;
}