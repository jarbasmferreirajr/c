#include <stdio.h>

/* ---------- Função da letra a) ---------- */
void DesenhaLinha(int quantidade)
{
    int i;

    for (i = 0; i < quantidade; i++)
    {
        printf("=");
    }
    printf("\n");
}

/* ---------- Função da letra b) ---------- */
int Intervalo(int a, int b)
{
    int i, soma = 0;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    for (i = a; i <= b; i++)
    {
        soma += i;
    }

    return soma;
}

/* ---------- Programa principal ---------- */
int main(void)
{
    int a, b;

    while (1)
    {
        printf("Digite 0 para encerrar, ou o primeiro numero: ");
        scanf("%d", &a);

        /* Condição de parada */
        if (a == 0)
        {
            DesenhaLinha(40);
            printf("Programa encerrado.\n");
            break;
        }

        printf("Digite o segundo numero: ");
        scanf("%d", &b);

        /* Desenha a linha antes de mostrar o resultado */
        DesenhaLinha(40);

        printf("Soma do intervalo [%d, %d] = %d\n", a, b, Intervalo(a, b));

        DesenhaLinha(40);
        printf("\n");
    }

    return 0;
}