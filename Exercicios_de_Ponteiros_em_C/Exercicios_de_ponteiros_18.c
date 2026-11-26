/* 18. Escreva uma função que recebo o ponteiro de um array de inteiros, e retorna o maior
valor de um array de tamanho N. Escreva um programa que leia N valores inteiros, imprima o
array com k elementos por linha, e chame a função para descobrir o maior elemento. O valor
de k também deve ser fornecido pelo usuário. */

#include <stdio.h>

int maior_elemento(int *v, int n) {
    int maior = v[0];

    for (int *p = v + 1; p < v + n; p++) {
        if (*p > maior) {
            maior = *p;
        }
    }

    return maior;
}

int main(void) {
    int n, k;
    int v[100];

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Digite %d valores inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("Digite k (elementos por linha): ");
    scanf("%d", &k);

    if (k <= 0) k = 1;

    printf("Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);

        if ((i + 1) % k == 0 || i == n - 1) {
            printf("\n");
        }
    }

    printf("Maior elemento: %d\n", maior_elemento(v, n));

    return 0;
}