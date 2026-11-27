/*

8. Faça um programa para armazenar em memória um vetor de dados contendo 1500
valores do tipo int, usando a função de alocação dinâmica de memória CALLOC:

(a) Faça um loop e verifique se o vetor contém realmente os 1500 valores inicializados
com zero (conte os 1500 zeros do vetor).
(b) Atribua para cada elemento do vetor o valor do seu indice junto a este vetor.
(c) Exibir na tela os 10 primeiros e os 10 últimos elementos do vetor.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v = calloc(1500, sizeof(int));
    if (v == NULL) return 1;

    int zeros = 0;
    for (int i = 0; i < 1500; i++)
        if (v[i] == 0) zeros++;
    printf("Zeros encontrados: %d\n", zeros);

    for (int i = 0; i < 1500; i++)
        v[i] = i;

    printf("10 primeiros: ");
    for (int i = 0; i < 10; i++) printf("%d ", v[i]);

    printf("\n10 ultimos: ");
    for (int i = 1490; i < 1500; i++) printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}