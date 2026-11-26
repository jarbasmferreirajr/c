/* 

1 - Exercício vetor Maior Número Arquivo:

✔ Criar um programa que possui um vetor de inteiros, e uma variável tipo
int, chamada “maior” declarado na função main;
✔ Uma Função deve solicitar na tela que o usuário digite os números para
preencher o vetor (apenas utilizando o conceito de ponteiros, sem o
comando return);
✔ Uma Função deve receber o ponteiro do vetor, preenchido, e realizar a
impressão de todos os valores do vetor;
✔ Uma Função deve receber o ponteiro do vetor, preenchido, procurar pelo
maior número no vetor, e atualizar esse valor na variável “maior” que foi
declarada na função main;
✔ Ao final, exibir para o usuário qual é o maior valor do vetor.

*/

/* =============================================================
 *  Exercicio — Vetor Maior Numero
 *  -------------------------------------------------------------
 *  Requisitos:
 *    - vetor de inteiros + variavel "maior" declarados no main
 *    - funcao que preenche o vetor SO com ponteiros (sem return)
 *    - funcao que imprime o vetor via ponteiro
 *    - funcao que acha o maior e atualiza "maior" do main via ponteiro
 *    - exibir o maior valor ao final
 * ============================================================= */

#include <stdio.h>

#define TAM 5   /* tamanho do vetor — mude se quiser */

/* -------------------------------------------------------------
 * Preenche o vetor usando apenas aritmetica de ponteiros.
 * Sem return — o preenchimento e feito por efeito colateral.
 * ------------------------------------------------------------- */
void preencher(int *v, int n) {
    int i;
    printf("Digite %d numeros inteiros:\n", n);
    for (i = 0; i < n; i++) {
        printf("  posicao %d = ", i);
        scanf("%d", v + i);          /* v + i JA e ponteiro: nao usa & nem [ ] */
    }
}

/* -------------------------------------------------------------
 * Imprime todos os valores do vetor percorrendo por ponteiro.
 * ------------------------------------------------------------- */
void imprimir(const int *v, int n) {
    const int *p;
    printf("\nVetor preenchido: [ ");
    for (p = v; p < v + n; p++) {
        printf("%d ", *p);           /* desreferencia o ponteiro */
    }
    printf("]\n");
}

/* -------------------------------------------------------------
 * Procura o maior valor e escreve na variavel "maior" do main.
 * Recebe o ENDERECO de "maior" (int *) para poder atualiza-la.
 * Sem return — a atualizacao e via *maior = ...
 * ------------------------------------------------------------- */
void encontrar_maior(const int *v, int n, int *maior) {
    const int *p;
    *maior = *v;                     /* assume o 1o elemento como maior */
    for (p = v + 1; p < v + n; p++) {
        if (*p > *maior) {
            *maior = *p;             /* atualiza a variavel do main */
        }
    }
}

/* -------------------------------------------------------------
 * main — declara vetor e "maior", chama as 3 funcoes, mostra o resultado
 * ------------------------------------------------------------- */
int main(void) {
    int vetor[TAM];
    int maior = 0;

    preencher(vetor, TAM);
    imprimir(vetor, TAM);
    encontrar_maior(vetor, TAM, &maior);   /* &maior: passa o endereco */

    printf("\nMaior valor do vetor: %d\n", maior);

    return 0;
}