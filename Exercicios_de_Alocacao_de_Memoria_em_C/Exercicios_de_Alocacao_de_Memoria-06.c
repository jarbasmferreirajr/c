/* 

6. Faça um programa que simule a memória de um computador: o usuário ira especificar
o tamanho da memória, ou seja, quantos bytes serão alocados do tipo inteiro. Para tanto,
a memória solicitada deve ser um valor multiplo do tamanho do tipo inteiro. Em seguida, o
usuário tera 2 opções: inserir um valor em uma determinada posição ou consultar o valor
contido em uma determinada posição. A memória deve iniciar com todos os dados
zerados.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int bytes;
    do {
        printf("Tamanho da memoria em bytes (multiplo de %zu): ", sizeof(int));
        scanf("%d", &bytes);
    } while (bytes <= 0 || bytes % sizeof(int) != 0);

    int n = bytes / sizeof(int);
    int *mem = calloc(n, sizeof(int));
    if (mem == NULL) return 1;

    int op;
    do {
        printf("\n1 - Inserir\n2 - Consultar\n0 - Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1) {
            int pos, val;
            printf("Posicao (0 a %d): ", n - 1);
            scanf("%d", &pos);
            printf("Valor: ");
            scanf("%d", &val);
            if (pos >= 0 && pos < n) mem[pos] = val;
            else printf("Posicao invalida.\n");
        } else if (op == 2) {
            int pos;
            printf("Posicao (0 a %d): ", n - 1);
            scanf("%d", &pos);
            if (pos >= 0 && pos < n) printf("Valor: %d\n", mem[pos]);
            else printf("Posicao invalida.\n");
        }
    } while (op != 0);

    free(mem);
    return 0;
}