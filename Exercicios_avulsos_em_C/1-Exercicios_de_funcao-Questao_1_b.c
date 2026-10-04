#include <stdio.h>

/* Função que soma todos os inteiros de a até b (inclusive).
   Se a > b, os valores são invertidos para garantir o intervalo correto. */
int Intervalo(int a, int b)
{
    int i, soma = 0;

    /* Garante que 'a' seja o menor valor */
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    /* Soma todos os números do intervalo [a, b] */
    for (i = a; i <= b; i++)
    {
        soma += i;
    }

    return soma;
}

int main(void)
{
    int x, y;

    printf("Digite dois numeros inteiros positivos: ");
    scanf("%d %d", &x, &y);

    printf("Soma do intervalo [%d, %d] = %d\n", x, y, Intervalo(x, y));

    return 0;
}