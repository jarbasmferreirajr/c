/* 

Exercício Ponteiro Struct data livre struct Data { int dia; int mes; int ano; int livre; }; »Criar um Vetor da estrutura “Data” para os 30 dias do mês; » Pedir na tela para informar algum mês do ano; »Usar o mês informado na tela para preencher os 30 dias deste mês no vetor, a partir do 1º dia deste mês; »Uma função recebe o ponteiro do vetor e faz o preenchimento de todas as datas do vetor (sequencialmente); »Enquanto não for solicitado encerrar o programa; solicitar na tela um dia do mês e, em uma função separada, procurar se este dia está “livre” ou não; • Caso esteja livre, marcar como ocupado e informar na tela que esta data foi ocupada; • Caso não esteja livre, procurar pelo próximo dia livre, marcar como ocupado e informar uma mensagem na tela; » Quando solicitado para encerrar o programa, uma função deve receber o ponteiro do vetor e realizar a impressão na tela, mostrando os dias Livres e os Ocupados

*/

/* =============================================================
 *  Exercicio — Ponteiro + Struct Data + Vetor de 30 dias
 *  -------------------------------------------------------------
 *  - struct Data { int dia, mes, ano, livre; }
 *  - vetor de 30 "Data" (dias 1..30 do mes informado)
 *  - preenche sequencialmente via funcao com ponteiro
 *  - loop: pede dia, procura/ocupa (funcao separada)
 *  - ao encerrar: funcao com ponteiro imprime agenda final
 * ============================================================= */

#include <stdio.h>

#define NUM_DIAS 30

struct Data {
    int dia;
    int mes;
    int ano;
    int livre;   /* 1 = livre, 0 = ocupado */
};

/* -------------------------------------------------------------
 * Preenche o vetor sequencialmente (dia 1..30) no mes/ano dados.
 * Todas as datas comecam como LIVRES (livre = 1).
 * Usa apenas aritmetica de ponteiros + operador -> para acessar campos.
 * ------------------------------------------------------------- */
void preencher(struct Data *v, int mes, int ano) {
    struct Data *p;
    int d = 1;
    for (p = v; p < v + NUM_DIAS; p++) {
        p->dia   = d++;
        p->mes   = mes;
        p->ano   = ano;
        p->livre = 1;
    }
}

/* -------------------------------------------------------------
 * Procura/ocupa o dia pedido.
 *   1) Se o dia exato estiver livre -> ocupa.
 *   2) Senao, procura o proximo dia livre (para frente).
 *   3) Se nao achar, da a volta e procura do inicio.
 *   4) Se tudo ocupado -> retorna NULL.
 * Retorna ponteiro para o "struct Data" ocupado.
 * ------------------------------------------------------------- */
struct Data *reservar(struct Data *v, int dia_pedido) {
    /* 1) tenta o dia exato */
    if (dia_pedido >= 1 && dia_pedido <= NUM_DIAS && (v + dia_pedido - 1)->livre) {
        (v + dia_pedido - 1)->livre = 0;
        printf("Data %02d/%02d/%04d RESERVADA.\n",
               (v + dia_pedido - 1)->dia,
               (v + dia_pedido - 1)->mes,
               (v + dia_pedido - 1)->ano);
        return v + dia_pedido - 1;
    }

    /* 2) procura para frente */
    for (struct Data *p = v + dia_pedido; p < v + NUM_DIAS; p++) {
        if (p->livre) {
            p->livre = 0;
            printf("Dia %d indisponivel. Proximo livre: %02d/%02d/%04d RESERVADO.\n",
                   dia_pedido, p->dia, p->mes, p->ano);
            return p;
        }
    }

    /* 3) da a volta: do inicio ate antes do dia pedido */
    for (struct Data *p = v; p < v + dia_pedido - 1 && p < v + NUM_DIAS; p++) {
        if (p->livre) {
            p->livre = 0;
            printf("Dia %d indisponivel. Proximo livre: %02d/%02d/%04d RESERVADO.\n",
                   dia_pedido, p->dia, p->mes, p->ano);
            return p;
        }
    }

    /* 4) agenda cheia */
    return NULL;
}

/* -------------------------------------------------------------
 * Imprime o estado final da agenda (todos os 30 dias).
 * ------------------------------------------------------------- */
void imprimir(const struct Data *v) {
    printf("\n===== AGENDA FINAL =====\n");
    printf("Data          Estado\n");
    printf("----------    --------\n");
    for (const struct Data *p = v; p < v + NUM_DIAS; p++) {
        printf("%02d/%02d/%04d    %s\n",
               p->dia, p->mes, p->ano,
               p->livre ? "LIVRE" : "OCUPADO");
    }
    printf("========================\n");
}

/* -------------------------------------------------------------
 * main
 * ------------------------------------------------------------- */
int main(void) {
    struct Data agenda[NUM_DIAS];
    int mes, ano;

    printf("Informe o mes (1-12): ");
    if (scanf("%d", &mes) != 1 || mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        return 1;
    }

    printf("Informe o ano: ");
    if (scanf("%d", &ano) != 1) {
        printf("Ano invalido.\n");
        return 1;
    }

    preencher(agenda, mes, ano);
    printf("\nAgenda preenchida para %02d/%04d. Todos os dias comecam LIVRES.\n", mes, ano);

    while (1) {
        int dia;
        printf("\nInforme o dia que deseja reservar (1-%d), ou -1 para encerrar: ", NUM_DIAS);

        if (scanf("%d", &dia) != 1) {
            printf("Entrada invalida.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }

        if (dia < 0) break;                 /* encerra */

        if (dia < 1 || dia > NUM_DIAS) {
            printf("Dia fora do intervalo (1-%d).\n", NUM_DIAS);
            continue;
        }

        struct Data *r = reservar(agenda, dia);
        if (r == NULL) {
            printf("Nao ha mais datas livres nesta agenda.\n");
        }
    }

    imprimir(agenda);
    return 0;
}