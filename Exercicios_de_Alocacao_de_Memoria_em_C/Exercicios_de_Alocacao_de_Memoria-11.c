/* 

11. Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um) e ano
de nascimento.
(b) Ao início do programa, o usuário devera informar o número de alunos que serão
armazenados
(c) O programa devera alocar dinamicamente a quantidade necessária de memória para
armazenar os registros dos alunos.
(d) O programa devera pedir ao usuário que entre com as informações dos alunos.
(e) Ao final, mostrar os dados armazenados e liberar a memória alocada.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char sobrenome[50];
    int anoNascimento;
} Aluno;

int main(void) {
    int n;
    printf("Numero de alunos: ");
    scanf("%d", &n);

    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) return 1;

    for (int i = 0; i < n; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Sobrenome: ");
        scanf("%49s", alunos[i].sobrenome);
        printf("Ano de nascimento: ");
        scanf("%d", &alunos[i].anoNascimento);
    }

    printf("\nDados cadastrados:\n");
    for (int i = 0; i < n; i++)
        printf("%d - %s - %d\n", alunos[i].matricula,
               alunos[i].sobrenome, alunos[i].anoNascimento);

    free(alunos);
    return 0;
}