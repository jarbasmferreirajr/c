#include <stdio.h>
#define PI 3.14159

/* -----------------------------------------------------------
   Função 1: lê uma medida da figura.
   Recebe o texto a ser exibido e retorna o valor lido.
   ----------------------------------------------------------- */
float LeMedida(const char *texto)
{
    float valor;

    printf("%s ", texto);
    scanf("%f", &valor);

    return valor;
}

/* -----------------------------------------------------------
   Função 2: calcula a área conforme a figura.
   opcao -> 1 = retângulo, 2 = triângulo, 3 = círculo
   ----------------------------------------------------------- */
float CalculaArea(int opcao, float m1, float m2)
{
    switch (opcao)
    {
        case 1: /* Retângulo: base x altura */
            return m1 * m2;

        case 2: /* Triângulo: (base x altura) / 2 */
            return (m1 * m2) / 2.0;

        case 3: /* Círculo: PI x raio² */
            return PI * m1 * m1;

        default:
            return 0.0;
    }
}

/* -----------------------------------------------------------
   Função 3: exibe na tela o texto e a área calculada.
   ----------------------------------------------------------- */
void MostraResultado(const char *texto, float area)
{
    printf("%s %.2f\n", texto, area);
}

/* -----------------------------------------------------------
   Programa principal
   ----------------------------------------------------------- */
int main(void)
{
    int opcao;
    float medida1, medida2, area;

    while (1)
    {
        printf("\n===== CALCULO DE AREAS =====\n");
        printf("1 - Retangulo\n");
        printf("2 - Triangulo\n");
        printf("3 - Circulo\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        /* Condição de parada */
        if (opcao == 0)
        {
            printf("Programa encerrado.\n");
            break;
        }

        switch (opcao)
        {
            case 1: /* Retângulo */
                medida1 = LeMedida("Informe a base do retangulo:");
                medida2 = LeMedida("Informe a altura do retangulo:");
                area = CalculaArea(opcao, medida1, medida2);
                MostraResultado("A area do retangulo eh:", area);
                break;

            case 2: /* Triângulo */
                medida1 = LeMedida("Informe a base do triangulo:");
                medida2 = LeMedida("Informe a altura do triangulo:");
                area = CalculaArea(opcao, medida1, medida2);
                MostraResultado("A area do triangulo eh:", area);
                break;

            case 3: /* Círculo */
                medida1 = LeMedida("Informe o raio do circulo:");
                area = CalculaArea(opcao, medida1, 0);
                MostraResultado("A area do circulo eh:", area);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}