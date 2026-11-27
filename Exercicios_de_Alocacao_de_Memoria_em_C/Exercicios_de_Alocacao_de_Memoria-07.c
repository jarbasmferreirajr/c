/*

7. Escreva um programa que leia primeiro os 6 números gerados pela loteria e depois os
6 números do seu bilhete. O programa então compara quantos números o jogador
acertou. Em seguida, ele aloca espaço para um vetor de tamanho igual a quantidade de
números corretos (os que foram acertados) e guarda os números corretos nesse novo
vetor. Finalmente, uma função que recebe o endereço do vetor alocado, exibe os números
sorteados e os seus números corretos.

*/

#include <stdio.h>
#include <stdlib.h>

void exibe(int *sorteados, int *corretos, int qtd) {
    printf("Sorteados: ");
    for (int i = 0; i < 6; i++) printf("%d ", sorteados[i]);
    printf("\nCorretos: ");
    for (int i = 0; i < qtd; i++) printf("%d ", corretos[i]);
    printf("\n");
}

int main(void) {
    int sorteados[6], bilhete[6];

    printf("Numeros sorteados:\n");
    for (int i = 0; i < 6; i++) scanf("%d", &sorteados[i]);

    printf("Numeros do bilhete:\n");
    for (int i = 0; i < 6; i++) scanf("%d", &bilhete[i]);

    int qtd = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (bilhete[i] == sorteados[j]) {
                qtd++;
                break;
            }

    int *corretos = malloc(qtd * sizeof(int));
    if (qtd > 0 && corretos == NULL) return 1;

    int k = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (bilhete[i] == sorteados[j]) {
                corretos[k++] = bilhete[i];
                break;
            }

    printf("Acertos: %d\n", qtd);
    exibe(sorteados, corretos, qtd);

    free(corretos);
    return 0;
}