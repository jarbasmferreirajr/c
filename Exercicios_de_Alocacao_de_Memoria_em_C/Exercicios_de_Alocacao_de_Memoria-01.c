/*

1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Peça para o usuario digitar os 5 numeros no espaço alocado,
(c) Mostre na tela os 5 numeros,
(d) Libere a memoria alocada.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *v = malloc(5 * sizeof(int));
    if (v == NULL)
        return 1;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}