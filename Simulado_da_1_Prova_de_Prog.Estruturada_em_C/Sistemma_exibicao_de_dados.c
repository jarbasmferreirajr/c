#include <stdio.h>

void emitir_relatorio (int criticas, float menor_carga) {
    printf("=== RELATÓRIO DE MANUTENÇÃO ===\n");
    printf("Células criticas encontradas: %d\n", criticas);
    printf("Menor carga encontradas: %.1f%%\n", menor_carga);

    if (criticas > 0) {

        printf("tatus: ALERTA! Necessário balanceamento de células.\n");
    } else {
        printf("Status: Bateria operando em contições seguras.\n");
    }
}

int main() {
    emitir_relatorio(2, 12.0f);
    printf("\n");
    emitir_relatorio(0, 45.2f);

    return 0;
}