#include <stdio.h>

struct Celula {
    int id;
    float carga;
};

int verificar_bateria_baixa(struct Celula vetor[], int tamanho) {
    int criticas = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].carga < 20.0f) {
        criticas++;
    }
}

return criticas; 

}

int main () {
    struct Celula frota[5] = {
        {1, 85.5f},
        {2, 12.0f},
        {4, 18.5f},
        {5, 90.0f}
    };
    
    int criticas = verificar_bateria_baixa(frota, 5);
    printf("Celulas criticas: %d\n", criticas);

return 0;

}