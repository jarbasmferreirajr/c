#include <stdio.h>

/* Função que desenha uma linha de '=' na tela.
   Parâmetro: quantidade -> número de sinais de igual a exibir */
void DesenhaLinha(int quantidade)
{
    int i;

    for (i = 0; i < quantidade; i++)
    {
        printf("=");
    }
    printf("\n"); /* quebra de linha ao final */
}

int main(void)
{
    int n;

    printf("Quantos sinais de igual deseja exibir? ");
    scanf("%d", &n);

    DesenhaLinha(n);

    return 0;
}