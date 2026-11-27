/*

4. Faça um programa que receba do usuário o tamanho de uma string e chame uma
função para alocar dinamicamente essa string. Em seguida, o usuário devera informar o
conteudo dessa string. O programa imprime a string sem suas vogais.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *alocaString(int n) {
    return malloc((n + 1) * sizeof(char));
}

int main(void) {
    int n;
    printf("Tamanho da string: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    char *s = alocaString(n);
    if (s == NULL) return 1;

    printf("Digite a string: ");
    fgets(s, n + 1, stdin);
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower((unsigned char)s[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            putchar(s[i]);
    }
    printf("\n");

    free(s);
    return 0;
}