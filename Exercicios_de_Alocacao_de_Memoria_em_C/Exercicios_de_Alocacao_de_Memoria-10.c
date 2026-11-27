/*

10. Faça um programa que pergunte ao usuário quantos valores ele deseja armazenar em
um vetor de double, depois use a função MALLOC para reservar (alocar) o espaço de
memória de acordo com o especificado pelo usuário. Esse vetor deve ter um tamanho
maior ou igual a 10 elementos. Use este vetor dinâmico como um vetor comum, atribuindo
aos 10 primeiros elementos do vetor valores aleatórios (usando a função rand) entre 0 e
100 (faça isso em uma função separada). Exiba na tela os valores armazenados nos 10
primeiros elementos do vetor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche(double *v) {
    for (int i = 0; i < 10; i++)
        v[i] = rand() % 101;
}

int main(void) {
    srand((unsigned)time(NULL));

    int q;
    do {
        printf("Quantidade de valores (>= 10): ");
        scanf("%d", &q);
    } while (q < 10);

    double *v = malloc(q * sizeof(double));
    if (v == NULL) return 1;

    preenche(v);

    printf("10 primeiros valores:\n");
    for (int i = 0; i < 10; i++)
        printf("%.0f ", v[i]);
    printf("\n");

    free(v);
    return 0;
}