/* 

16. Escreva um programa para fazer a alocação dinâmica dos blocos de dados conforme
solicitado abaixo:
(a) Vetor de 1024 Bytes (1 Kbyte).
(b) Matriz de inteiros de dimensão 10 x 10.
(c) Vetor para armazenar 50 registros contendo: nome do produto (30 caracteres), código
do produto (inteiro) e preço em reais.
(d) Texto de ate 100 linhas com ate 80 caracteres em cada linha.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[31];
    int codigo;
    float preco;
} Produto;

int main(void) {
    unsigned char *v1024 = malloc(1024);
    if (v1024 == NULL) return 1;

    int **mat = malloc(10 * sizeof(int *));
    if (mat == NULL) return 1;
    for (int i = 0; i < 10; i++)
        mat[i] = malloc(10 * sizeof(int));

    Produto *registros = malloc(50 * sizeof(Produto));
    if (registros == NULL) return 1;

    char **texto = malloc(100 * sizeof(char *));
    if (texto == NULL) return 1;
    for (int i = 0; i < 100; i++)
        texto[i] = malloc(81 * sizeof(char));

    printf("Blocos alocados com sucesso.\n");

    for (int i = 0; i < 10; i++) free(mat[i]);
    free(mat);
    free(v1024);
    free(registros);
    for (int i = 0; i < 100; i++) free(texto[i]);
    free(texto);

    return 0;
}