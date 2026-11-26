/* 20. Faça um programa que possua uma função para ler 2 notas e retorná-las por parâmetro
(chamar uma função dedicada a ler 2 notas válidas e que devolve os 2 números lidos);
Calcular a média simples e a média ponderada e retorná-las por parâmetro, onde a segunda
nota tem peso 2; Media ponderada = (n1 + (n2 * 2)) / 3; */

#include <stdio.h>

void ler_notas(float *n1, float *n2) {
    do {
        printf("Digite a primeira nota (0 a 10): ");
        scanf("%f", n1);
    } while (*n1 < 0.0f || *n1 > 10.0f);

    do {
        printf("Digite a segunda nota (0 a 10): ");
        scanf("%f", n2);
    } while (*n2 < 0.0f || *n2 > 10.0f);
}

void calcular_medias(float n1, float n2, float *simples, float *ponderada) {
    *simples = (n1 + n2) / 2.0f;
    *ponderada = (n1 + (n2 * 2.0f)) / 3.0f;
}

int main(void) {
    float n1, n2;
    float simples, ponderada;

    ler_notas(&n1, &n2);
    calcular_medias(n1, n2, &simples, &ponderada);

    printf("Media simples: %.2f\n", simples);
    printf("Media ponderada: %.2f\n", ponderada);

    return 0;
}