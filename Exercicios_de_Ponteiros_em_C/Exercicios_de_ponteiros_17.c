/* 17. Crie uma função para somar dois arrays. Esta função deve receber o ponteiro de dois
arrays e retornar a soma em um terceiro array. Caso o tamanho do primeiro e segundo array
seja diferente então a função retornará ZERO (0). Caso a função seja concluída com
sucesso a mesma deve retornar o valor UM (1). */

#include <stdio.h>

int soma_arrays(int *a, int *b, int *c, int n1, int n2) {
    if (n1 != n2) {
        return 0;
    }

    for (int i = 0; i < n1; i++) {
        c[i] = a[i] + b[i];
    }

    return 1;
}

int main(void) {
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int c[3];

    if (soma_arrays(a, b, c, 3, 3)) {
        printf("Soma dos arrays:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", c[i]);
        }
        printf("\n");
    } else {
        printf("Tamanhos diferentes. Retorno 0.\n");
    }

    return 0;
}