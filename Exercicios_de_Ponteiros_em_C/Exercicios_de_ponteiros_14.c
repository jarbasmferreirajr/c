/* 14. Crie uma função que receba dois parâmetros: um array e um valor do mesmo tipo do
array. A função dever á preencher os elementos de array com esse valor. Não utilize íındices
para percorrer o array, apenas aritmética de ponteiros. */

#include <stdio.h>

void preencher(int *arr, int n, int valor) {
    for (int *p = arr; p < arr + n; p++) {
        *p = valor;
    }
}

int main(void) {
    int v[10];

    preencher(v, 10, 7);

    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}