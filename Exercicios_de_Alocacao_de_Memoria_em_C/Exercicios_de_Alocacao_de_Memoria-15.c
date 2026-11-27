/* 

15. Faça um programa que leia números do teclado e os armazene em um vetor alocado
dinamicamente. O usuário ira digitar uma sequência de números, sem limite de
quantidade.
Os números serão digitados um a um e, sendo que caso ele deseje encerrar a entrada de
dados, ele ira digitar o número ZERO. Os dados devem ser armazenados na memória
deste modo• Inicie com um vetor de tamanho 10 alocado dinamicamente;
• Após, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do
vetor anterior adicionado espaço para mais 10 valores (tamanho N+10, onde N
inicia com 10);
• Copie os valores ja digitados da área inicial para esta área maior e libere a
memória da area inicial;
• Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor
alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser ’expandido’ de
10 em 10 valores.
Ao final, exiba o vetor lido. Não use a função REALLOC.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cap = 10, n = 0;
    int *v = malloc(cap * sizeof(int));
    if (v == NULL) return 1;

    int x;
    while (1) {
        printf("Digite um numero (0 para parar): ");
        scanf("%d", &x);
        if (x == 0) break;

        if (n == cap) {
            int *novo = malloc((cap + 10) * sizeof(int));
            if (novo == NULL) {
                free(v);
                return 1;
            }
            for (int i = 0; i < n; i++)
                novo[i] = v[i];
            free(v);
            v = novo;
            cap += 10;
        }

        v[n++] = x;
    }

    printf("Vetor lido: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}