#include <stdio.h>

/* Função 1: calcula o consumo em Km/l */
float CalculaConsumo(float km, float litros)
{
    return km / litros;
}

/* Função 2: exibe a mensagem conforme o consumo */
void MostraMensagem(float consumo)
{
    if (consumo < 8.0)
    {
        printf("Venda o carro!\n");
    }
    else if (consumo <= 12.0)
    {
        printf("Econômico!\n");
    }
    else
    {
        printf("Super econômico!\n");
    }
}

int main(void)
{
    float distancia, litros, consumo;

    printf("Distancia percorrida (Km): ");
    scanf("%f", &distancia);

    printf("Litros de gasolina consumidos: ");
    scanf("%f", &litros);

    /* Validação simples para evitar divisão por zero */
    if (litros <= 0)
    {
        printf("Quantidade de litros invalida.\n");
        return 1;
    }

    consumo = CalculaConsumo(distancia, litros);

    printf("Consumo: %.2f Km/l\n", consumo);
    MostraMensagem(consumo);

    return 0;
}