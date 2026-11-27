/*

9. Faça um programa que leia uma quantidade qualquer de números armazenando-os na
memória e pare a leitura quando o usuário entrar um número negativo. Em seguida,
imprima o vetor lido. Use a função REALLOC para alocar memória.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v = NULL;
    int n = 0, x;

    while (1) {
        printf("Digite um numero (negativo para parar): ");
        scanf("%d", &x);
        if (x < 0) break;

        int *tmp = realloc(v, (n + 1) * sizeof(int));
        if (tmp == NULL) {
            free(v);
            return 1;
        }
        v = tmp;
        v[n++] = x;
    }

    printf("Vetor lido: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}