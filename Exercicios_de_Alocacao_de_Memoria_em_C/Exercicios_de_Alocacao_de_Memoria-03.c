/*

3. Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a
alocação dinâmica de memória. Em seguida, em uma função separada que receba o
endereço do vetor, leia do usuário seus valores. Ao retornar, mostre quantos dos números
são pares e quantos são ímpares.

*/

#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        while (scanf("%d", &v[i]) != 1) {
            printf("  valor invalido, tente de novo: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

int main(void) {
    int n;
    printf("Tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }

    lerVetor(v, n);

    int pares = 0, impares = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) pares++;
        else               impares++;
    }

    printf("\nPares:   %d\n", pares);
    printf("Impares: %d\n", impares);

    free(v);
    return 0;
}