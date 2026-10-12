#include <stdio.h>

struct Celula {
    int id;
    float carga;
};

/* QUESTÃO 1 */
int verificar_bateria_baixa(struct Celula vetor[], int tamanho) {
    int criticas = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].carga < 20.0f) {
            criticas++;
        }
    }

    return criticas;
}

/* QUESTÃO 2 */
void emitir_relatorio(int criticas, float menor_carga) {
    printf("=== RELATÓRIO DE MANUTENÇÃO ===\n");
    printf("Células críticas encontradas: %d\n", criticas);
    printf("Menor carga encontrada: %.1f%%\n", menor_carga);

    if (criticas > 0) {
        printf("Status: ALERTA! Necessário balanceamento de células.\n");
    } else {
        printf("Status: Bateria operando em condições seguras.\n");
    }
}

/* QUESTÃO 3 */
int main() {
    /* 1 e 2: declaração e inicialização do vetor */
    struct Celula frota[5] = {
        {1, 85.5f},
        {2, 12.0f},
        {3, 45.2f},
        {4, 18.5f},
        {5, 90.0f}
    };

    /* 3: variáveis */
    int celulas_criticas;
    float menor_carga;

    /* 4: menor carga */
    menor_carga = frota[0].carga;
    for (int i = 1; i < 5; i++) {
        if (frota[i].carga < menor_carga) {
            menor_carga = frota[i].carga;
        }
    }

    /* 5: chamada da Questão 1 */
    celulas_criticas = verificar_bateria_baixa(frota, 5);

    /* 6: chamada da Questão 2 */
    emitir_relatorio(celulas_criticas, menor_carga);

    return 0;
}