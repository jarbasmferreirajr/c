/* 

2. Faça um programa que leia do usuario o tamanho de um vetor a ser lido e faça a
alocação dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o
vetor lido. 

*/

#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        while (scanf("%d", &v[i]) != 1) {
            printf("  valor invalido, tente de novo: ");
            /* limpa o buffer até o fim da linha */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

    printf("Vetor lido: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}