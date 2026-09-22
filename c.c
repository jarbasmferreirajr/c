#include <stdio.h>

int eh_ano_bissexto(int ano);
int validar_data(int dia, int mes, int ano);

int main()
{
    int dia, mes, ano;
    const int valor_mes[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    const char *dias_semana[7] = {
        "Domingo", "Segunda-feira", "Terça-feira",
        "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};

    printf("=== Calculador do Dia da Semana de Nascimento ===\n\n");

    printf("Digite o dia do nascimento (1-31): ");
    if (scanf("%d", &dia) != 1)
    {
        printf("Erro na leitura do dia.\n");
        return 1;
    }

    printf("Digite o mês do nascimento (1-12): ");
    if (scanf("%d", &mes) != 1)
    {
        printf("Erro na leitura do mês.\n");
        return 1;
    }

    printf("Digite o ano do nascimento (ex: 1990): ");
    if (scanf("%d", &ano) != 1)
    {
        printf("Erro na leitura do ano.\n");
        return 1;
    }

    if (!validar_data(dia, mes, ano))
    {
        printf("Data inválida. Por favor, verifique os dados e tente novamente.\n");
        return 1;
    }

    int anos_desde_base = ano - 1900; /* 1900 é o ano base */
    int dias_bissextos = anos_desde_base / 4;

    if (mes <= 2 && eh_ano_bissexto(ano))
    {
        dias_bissextos--;
    }

    int resultado = (anos_desde_base + dias_bissextos + dia + valor_mes[mes - 1]) % 7; /* 7 dias na semana */

    printf("\nVocê nasceu em uma %s!\n", dias_semana[resultado]);

    return 0;
}

int eh_ano_bissexto(int ano)
{
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

int validar_data(int dia, int mes, int ano)
{
    /* Verificação básica */
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900)
    {
        return 0;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        return 0;
    }

    if (mes == 2)
    {
        if (eh_ano_bissexto(ano))
        {
            if (dia > 29)
                return 0;
        }
        else
        {
            if (dia > 28)
                return 0;
        }
    }

    return 1;
}