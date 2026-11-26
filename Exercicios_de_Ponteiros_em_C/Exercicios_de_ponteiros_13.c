/* 13. Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres das
strings. */

#include <stdio.h>
#include <string.h>

int ocorre(const char *s1, const char *s2) {
    if (*s2 == '\0') return 1;

    for (const char *p = s1; *p != '\0'; p++) {
        const char *a = p;
        const char *b = s2;

        while (*a != '\0' && *b != '\0' && *a == *b) {
            a++;
            b++;
        }

        if (*b == '\0') return 1;
    }
    return 0;
}

int main(void) {
    char s1[100], s2[100];

    printf("Digite a primeira string: ");
    if (!fgets(s1, sizeof s1, stdin)) return 1;
    s1[strcspn(s1, "\n")] = '\0';   /* remove o '\n' */

    printf("Digite a segunda string: ");
    if (!fgets(s2, sizeof s2, stdin)) return 1;
    s2[strcspn(s2, "\n")] = '\0';

    if (ocorre(s1, s2))
        printf("A segunda string ocorre dentro da primeira.\n");
    else
        printf("A segunda string NAO ocorre dentro da primeira.\n");

    return 0;
}