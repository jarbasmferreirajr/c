/* 

Exercício - Distância viagem 

struct caminho 
{ 
int distancia;     // em Km, do ponto “início” até o ponto “fim” 
char inicio[50];   // nome da cidade inicial to trecho 
char fim[50];      // nome da cidade final to trecho 
int ordem;         // a ordem em que essa distância ocorre na viagem 
};

Criar um programa em C que possa armazenar um vetor da struct "caminho", com até 6 estruturas, que irão armazenar trechos de uma viagem indicando a cidade inicial e a cidade final. Esse programa DEVE utilizar “ponteiro” para manipular o vetor. 

• Criar, no main, um vetor com 10 ocorrências dessa estrutura. 
Criar uma função para solicitar na tela os dados da estrutura. Enviar essa  estrutura para essa função (usando ponteiros) e carregar os dados de TODAS as ocorrências da estrutura. 

• Criar uma outra função que recebe o ponteiro do vetor de estruturas que  está no main, e vai varrer (passar por) todas as ocorrências do vetor. Calcular  a distância total da viagem e imprimir na tela. Identificar a “ordem” em que as  estruturas foram cadastradas, e imprimir na tela os pontos de parada em cada cidade, na ordem correta da viagem.

*/

/* =============================================================
 *  Exercicio — Distancia Viagem (Struct + Ponteiros)
 *  -------------------------------------------------------------
 *  - Vetor de 10 ocorrencias de "struct caminho" no main.
 *  - Funcao 1: recebe o ponteiro e preenche os dados (ate 6 trechos).
 *  - Funcao 2: recebe o ponteiro, calcula a distancia total e
 *              imprime os pontos de parada na ordem correta.
 * ============================================================= */

#include <stdio.h>
#include <string.h>

#define MAX_VETOR   10   /* Vetor no main tera 10 posicoes */
#define MAX_TRECHOS  6   /* O usuario pode cadastrar ate 6 trechos */

struct caminho {
    int  distancia;     /* em Km, do ponto "inicio" ate o ponto "fim" */
    char inicio[50];    /* nome da cidade inicial do trecho */
    char fim[50];       /* nome da cidade final do trecho */
    int  ordem;         /* a ordem em que essa distancia ocorre na viagem */
};

/* -------------------------------------------------------------
 * Funcao 1: Solicita os dados e preenche o vetor via ponteiro.
 * ------------------------------------------------------------- */
void cadastrar(struct caminho *c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n--- Trecho %d ---\n", i + 1);
        
        printf("Distancia (km): ");
        scanf("%d", &(c + i)->distancia);
        
        /* Limpa o buffer do teclado para o fgets nao ler o Enter sobrando */
        while (getchar() != '\n'); 

        printf("Cidade de inicio: ");
        fgets((c + i)->inicio, 50, stdin);
        (c + i)->inicio[strcspn((c + i)->inicio, "\n")] = '\0'; /* Remove o \n */

        printf("Cidade de fim: ");
        fgets((c + i)->fim, 50, stdin);
        (c + i)->fim[strcspn((c + i)->fim, "\n")] = '\0';

        printf("Ordem da viagem (ex: 1, 2, 3...): ");
        scanf("%d", &(c + i)->ordem);
        
        while (getchar() != '\n'); /* Limpa o buffer de novo */
    }
}

/* -------------------------------------------------------------
 * Funcao 2: Calcula distancia total e imprime roteiro na ordem.
 * ------------------------------------------------------------- */
void processar_viagem(struct caminho *c, int n) {
    int i, j;
    int distancia_total = 0;
    
    /* 1. Calcula a distancia total percorrendo o vetor via ponteiro */
    for (i = 0; i < n; i++) {
        distancia_total += (c + i)->distancia;
    }
    printf("\n==================================\n");
    printf("DISTANCIA TOTAL DA VIAGEM: %d km\n", distancia_total);
    printf("==================================\n");

    /* 2. Para imprimir na ordem correta, criamos um vetor de ponteiros 
     * para as structs e ordenamos esse vetor de ponteiros pelo campo "ordem". */
    struct caminho *roteiro_ordenado[MAX_TRECHOS];
    
    /* Copia os enderecos das structs para o vetor de ponteiros */
    for (i = 0; i < n; i++) {
        roteiro_ordenado[i] = (c + i);
    }

    /* Bubble sort para ordenar os ponteiros com base na "ordem" */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (roteiro_ordenado[j]->ordem > roteiro_ordenado[j + 1]->ordem) {
                struct caminho *temp = roteiro_ordenado[j];
                roteiro_ordenado[j] = roteiro_ordenado[j + 1];
                roteiro_ordenado[j + 1] = temp;
            }
        }
    }

    /* 3. Imprime o roteiro montado */
    printf("\nROTEIRO DA VIAGEM (Ordem cronologica):\n");
    if (n > 0) {
        printf("  %s", roteiro_ordenado[0]->inicio); /* Cidade inicial do 1o trecho */
        for (i = 0; i < n; i++) {
            printf(" -> %s", roteiro_ordenado[i]->fim); /* Destinos de cada trecho */
        }
        printf("\n\n");
    }
    
    /* Imprime os detalhes de cada parada na ordem correta */
    printf("Detalhes dos trechos:\n");
    for (i = 0; i < n; i++) {
        printf("  Ordem %d: %s para %s (%d km)\n", 
               roteiro_ordenado[i]->ordem,
               roteiro_ordenado[i]->inicio,
               roteiro_ordenado[i]->fim,
               roteiro_ordenado[i]->distancia);
    }
}

/* -------------------------------------------------------------
 * main
 * ------------------------------------------------------------- */
int main(void) {
    /* Cria o vetor com 10 ocorrencias (conforme pedido) */
    struct caminho viagem[MAX_VETOR];
    int qtd;

    printf("Quantos trechos deseja cadastrar? (1 a %d): ", MAX_TRECHOS);
    scanf("%d", &qtd);

    if (qtd < 1 || qtd > MAX_TRECHOS) {
        printf("Quantidade invalida. O limite e %d.\n", MAX_TRECHOS);
        return 1;
    }

    /* Passa o vetor (ponteiro) para a funcao de cadastro */
    cadastrar(viagem, qtd);

    /* Passa o vetor (ponteiro) para a funcao de calculo e impressao */
    processar_viagem(viagem, qtd);

    return 0;
}