#include <stdio.h>
#include <stdlib.h>

/* -----------------------------------------------------------
   Funcao auxiliar: le um double aceitando virgula OU ponto
   Ex: "1.5" e "1,5" sao ambos aceitos
   ----------------------------------------------------------- */
double LeDouble(const char *texto)
{
    char buffer[50];
    int i;

    printf("%s ", texto);

    if (scanf("%49s", buffer) != 1)
    {
        /* Se a leitura falhar, descarta o resto da linha e retorna 0 */
        while (getchar() != '\n')
            ;
        return 0.0;
    }

    /* Troca virgula por ponto, se houver */
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == ',')
            buffer[i] = '.';
    }

    return atof(buffer);
}

/* -----------------------------------------------------------
   Funcao auxiliar: le um inteiro com validacao
   ----------------------------------------------------------- */
int LeInteiro(const char *texto)
{
    int valor;

    printf("%s ", texto);

    if (scanf("%d", &valor) != 1)
    {
        /* Entrada invalida -> limpa o buffer e retorna 0 */
        while (getchar() != '\n')
            ;
        return 0;
    }

    return valor;
}

/* -----------------------------------------------------------
   (i) Calcula o volume total de um lote de caixas
   ----------------------------------------------------------- */
double Calculo_de_Volume(double comprimento, double largura,
                         double altura, int quantidade)
{
    double volumeUnitario = comprimento * largura * altura;
    return volumeUnitario * quantidade;
}

/* -----------------------------------------------------------
   (ii) Verifica se o volume calculado cabe na van
   Retorno: 0  -> nao cabe
            novo volume atual -> se couber
   ----------------------------------------------------------- */
double Verificar_volume(double volMax, double volAtual, double volCalc)
{
    if (volAtual + volCalc > volMax)
        return 0.0;
    else
        return volAtual + volCalc;
}

/* -----------------------------------------------------------
   Programa principal
   ----------------------------------------------------------- */
int main(void)
{
    double vanComp, vanLarg, vanAlt;
    double volumeMaximo;
    double volumeAtual = 0.0;

    double cxComp, cxLarg, cxAlt;
    int cxQtd;
    double volumeCalculado;
    double novoVolume;
    char continuar;

    /* ---------------------------------------------------------
       1. Medidas da van -> capacidade total (volume maximo)
       --------------------------------------------------------- */
    printf("===== MEDIDAS DA VAN =====\n");
    vanComp = LeDouble("Comprimento da van (m):");
    vanLarg = LeDouble("Largura da van (m):");
    vanAlt = LeDouble("Altura da van (m):");

    volumeMaximo = Calculo_de_Volume(vanComp, vanLarg, vanAlt, 1);

    if (volumeMaximo <= 0.0)
    {
        printf("Medidas invalidas para a van. Encerrando.\n");
        return 1;
    }

    printf("Capacidade total da van: %.2f m3\n\n", volumeMaximo);

    /* ---------------------------------------------------------
       2. Loop de insercao de caixas
       --------------------------------------------------------- */
    do
    {
        printf("===== NOVO LOTE DE CAIXAS =====\n");
        cxComp = LeDouble("Comprimento da caixa (m):");
        cxLarg = LeDouble("Largura da caixa (m):");
        cxAlt = LeDouble("Altura da caixa (m):");
        cxQtd = LeInteiro("Quantidade de caixas:");

        /* Validacao basica */
        if (cxComp <= 0.0 || cxLarg <= 0.0 || cxAlt <= 0.0 || cxQtd <= 0)
        {
            printf(">> Dados invalidos! Lote ignorado.\n\n");
            continue; /* volta ao inicio do laco */
        }

        /* Calcula o volume do lote */
        volumeCalculado = Calculo_de_Volume(cxComp, cxLarg, cxAlt, cxQtd);
        printf("Volume calculado do lote: %.2f m3\n", volumeCalculado);

        /* Verifica se cabe */
        novoVolume = Verificar_volume(volumeMaximo, volumeAtual, volumeCalculado);

        if (novoVolume == 0.0)
        {
            printf(">> ATENCAO: o lote NAO cabe na van! Volume nao adicionado.\n");
        }
        else
        {
            volumeAtual = novoVolume;
            printf(">> Lote adicionado. Volume atual: %.2f m3\n", volumeAtual);
        }

        /* Percentual de ocupacao */
        printf(">> Ocupacao da van: %.2f%%\n",
               (volumeAtual / volumeMaximo) * 100.0);

        /* ---------------------------------------------------------
           6. Perguntar se deseja continuar
           --------------------------------------------------------- */
        printf("\nDeseja continuar? (s/n): ");

        /* Pega o primeiro caractere nao-branco do buffer.
           O espaco antes do %c descarta '\n' e espacos pendentes. */
        if (scanf(" %c", &continuar) != 1)
        {
            while (getchar() != '\n')
                ;
            continuar = 'n';
        }

        /* Descarta o resto da linha (caso o usuario digite algo como "sim") */
        while (getchar() != '\n')
            ;

        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    /* ---------------------------------------------------------
       Encerramento
       --------------------------------------------------------- */
    printf("===== RESUMO FINAL =====\n");
    printf("Capacidade total da van : %.2f m3\n", volumeMaximo);
    printf("Volume ocupado          : %.2f m3\n", volumeAtual);
    printf("Ocupacao final          : %.2f%%\n",
           (volumeAtual / volumeMaximo) * 100.0);

    return 0;
}