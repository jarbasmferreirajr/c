/* 15. Escreva uma função que aceita como parâmetro um array de inteiros com N valores, e
determina o maior elemento do array e o número de vezes que este elemento ocorreu no
array. Utilize mais duas posições no array para essas informações.Por exemplo, para um
array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve informar para o
programa que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3
vezes). A função não tem retorno, deve ser do tipo void. */

#include <stdio.h>

void analisa(int *v, int n) {
    int maior = v[0];
    int cont = 0;

    for (int *p = v; p < v + n; p++) {
        if (*p > maior) {
            maior = *p;
        }
    }

    for (int *p = v; p < v + n; p++) {
        if (*p == maior) {
            cont++;
        }
    }

    v[n] = maior;
    v[n + 1] = cont;
}

int main(void) {
    int v[11] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
    int n = 9;

    analisa(v, n);

    printf("Maior valor: %d\n", v[n]);
    printf("Ocorrencias: %d\n", v[n + 1]);

    return 0;
}