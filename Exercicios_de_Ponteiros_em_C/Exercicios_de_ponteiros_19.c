/* 19. Escreva uma função que receba o ponteiro de um array de inteiros V e os endereços de
duas variáveis inteiras, min e max, e armazene nessas variáveis o valor mínimo e máximo do
array. Escreva também uma função main que chame essa função. */

#include <stdio.h>

void min_max(int *v, int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];

    for (int *p = v + 1; p < v + n; p++) {
        if (*p < *min) {
            *min = *p;
        }
        if (*p > *max) {
            *max = *p;
        }
    }
}

int main(void) {
    int n;
    int v[100];
    int min, max;

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Digite %d inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    min_max(v, n, &min, &max);

    printf("Minimo: %d\n", min);
    printf("Maximo: %d\n", max);

    return 0;
}