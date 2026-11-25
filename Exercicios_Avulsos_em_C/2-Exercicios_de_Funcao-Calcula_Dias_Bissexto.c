#include <stdio.h>
#include <string.h>

/* -----------------------------------------------------------
   Função: verifica se um ano é bissexto
   Retorna 1 se for bissexto, 0 caso contrário.
   Caso 1: divisível por 4 e NÃO por 100
   Caso 2: divisível por 4, por 100 e por 400
   ----------------------------------------------------------- */
int EhBissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    else
        return 0;
}

/* -----------------------------------------------------------
   Função: retorna quantos dias tem um determinado ano
   ----------------------------------------------------------- */
int DiasDoAno(int ano)
{
    if (EhBissexto(ano))
        return 366;
    else
        return 365;
}

/* -----------------------------------------------------------
   Programa principal
   ----------------------------------------------------------- */
int main(void)
{
    char nome[100];
    int anoNascimento, anoAtual;
    int ano;
    long totalDias = 0;

    /* a) Nome */
    printf("Informe o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';   /* remove o '\n' do final */

    /* b) Ano de nascimento */
    printf("Informe o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    /* c) Ano atual */
    printf("Informe o ano atual: ");
    scanf("%d", &anoAtual);

    /* Validação simples */
    if (anoAtual < anoNascimento)
    {
        printf("Ano atual nao pode ser menor que o ano de nascimento.\n");
        return 1;
    }

    /* d) Percorre cada ano completo entre o nascimento e o ano atual */
    for (ano = anoNascimento; ano < anoAtual; ano++)
    {
        totalDias += DiasDoAno(ano);
    }

    /* Exibição */
    printf("\n%s, voce viveu aproximadamente %ld dias.\n", nome, totalDias);

    return 0;
}