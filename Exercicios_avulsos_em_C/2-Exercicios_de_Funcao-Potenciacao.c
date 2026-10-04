#include <stdio.h>

/* -----------------------------------------------------------
   Função: Potencia
   Recebe base e expoente (inteiros) e retorna base^expoente.
   Trata expoente 0 e expoente negativo.
   ----------------------------------------------------------- */
double Potencia(int base, int expoente)
{
    int i;
    double resultado = 1.0;
    int expNegativo = 0;

    /* Se o expoente for negativo, trabalhamos com o valor absoluto
       e invertemos o resultado no final. */
    if (expoente < 0)
    {
        expNegativo = 1;
        expoente = -expoente;
    }

    /* Multiplica a base por ela mesma 'expoente' vezes */
    for (i = 0; i < expoente; i++)
    {
        resultado *= base;
    }

    /* Inverte se o expoente era negativo: base^(-n) = 1 / base^n */
    if (expNegativo)
    {
        resultado = 1.0 / resultado;
    }

    return resultado;
}

/* -----------------------------------------------------------
   Programa principal
   ----------------------------------------------------------- */
int main(void)
{
    int base, expoente;
    double resultado;

    /* (b) Solicita base e expoente */
    printf("Informe a base (inteiro): ");
    scanf("%d", &base);

    printf("Informe o expoente (inteiro): ");
    scanf("%d", &expoente);

    /* (c) Chama a função de potenciação */
    resultado = Potencia(base, expoente);

    /* (d) Imprime o resultado na main */
    printf("\n%d elevado a %d = %.2f\n", base, expoente, resultado);

    return 0;
}