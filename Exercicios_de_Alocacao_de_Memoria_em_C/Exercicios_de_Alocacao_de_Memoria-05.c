/* 

5. Faça um programa que leia um número N e, crie funções separadas que:
• Crie dinamicamente e leia um vetor de inteiro de N posições;
• Leia um número inteiro X e conte e mostre os múltiplos desse número que existem
no vetor.

*/

#include <stdio.h>
#include <stdlib.h>

int *criaLeVetor(int n) {
    int *v = malloc(n * sizeof(int));
    if (v == NULL) return NULL;
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    return v;
}

int main(void) {
    int n, x;
    printf("N: ");
    scanf("%d", &n);

    int *v = criaLeVetor(n);
    if (v == NULL) return 1;

    printf("X: ");
    scanf("%d", &x);

    int cont = 0;
    printf("Multiplos: ");
    for (int i = 0; i < n; i++) {
        int ehMultiplo = (x == 0) ? (v[i] == 0) : (v[i] % x == 0);
        if (ehMultiplo) {
            printf("%d ", v[i]);
            cont++;
        }
    }
    printf("\nQuantidade: %d\n", cont);

    free(v);
    return 0;
}