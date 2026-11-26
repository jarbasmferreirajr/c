# Exercícios de Ponteiros em C

Exercícios de ponteiros da disciplina de Programação Estruturada: passagem de parâmetros por referência, aritmética de ponteiros, vetores, matrizes, strings e structs.

## Lista de exercícios

| Arquivo | O que faz |
|---|---|
| `Exercicios_de_ponteiros_01.c` | Altera um `int`, um `float` e um `char` por meio de ponteiros |
| `Exercicios_de_ponteiros_02.c` | Compara os endereços de duas variáveis e mostra o maior |
| `Exercicios_de_ponteiros_03.c` | Mostra o conteúdo guardado no maior dos dois endereços |
| `Exercicios_de_ponteiros_04.c` | Troca o valor de duas variáveis numa função |
| `Exercicios_de_ponteiros_05.c` | Devolve o maior valor na primeira variável e o menor na segunda |
| `Exercicios_de_ponteiros_06.c` | Soma os dobros e guarda o dobro de cada número na própria variável |
| `Exercicios_de_ponteiros_07.c` | Soma A e B e guarda o resultado em A, sem retorno |
| `Exercicios_de_ponteiros_08.c` | Imprime o endereço de cada posição de um vetor de `float` |
| `Exercicios_de_ponteiros_09.c` | Imprime o endereço de cada posição de uma matriz 3x3 |
| `Exercicios_de_ponteiros_10.c` | Lê um vetor e imprime o dobro de cada valor só com aritmética de ponteiros |
| `Exercicios_de_ponteiros_11.c` | Imprime o endereço das posições do vetor com valores pares |
| `Exercicios_de_ponteiros_12.c` | Ordena três valores e informa se são todos iguais |
| `Exercicios_de_ponteiros_13.c` | Verifica se uma string ocorre dentro de outra |
| `Exercicios_de_ponteiros_14.c` | Preenche um vetor com um valor, sem usar índices |
| `Exercicios_de_ponteiros_15.c` | Encontra o maior elemento do vetor e quantas vezes ele aparece |
| `Exercicios_de_ponteiros_16.c` | Soma 1 a cada posição do vetor por meio do ponteiro |
| `Exercicios_de_ponteiros_17.c` | Soma dois vetores num terceiro e valida se têm o mesmo tamanho |
| `Exercicios_de_ponteiros_18.c` | Imprime o vetor com k elementos por linha e acha o maior valor |
| `Exercicios_de_ponteiros_19.c` | Encontra o mínimo e o máximo do vetor e devolve por parâmetro |
| `Exercicios_de_ponteiros_20.c` | Lê duas notas e devolve a média simples e a ponderada por parâmetro |
| `1-Exercicio_vetor_maior_numero.c` | Preenche um vetor, imprime e atualiza a variável `maior` do `main` sem usar `return` |
| `2-Exercicio_ponteiro_Struct_data_livre.c` | Agenda de 30 dias com `struct Data`: ocupa o dia pedido ou o próximo livre |
| `3-Exercicio_ponteiro_viagem.c` | Trechos de viagem com `struct caminho`: distância total e paradas na ordem certa |

## Como compilar e executar

Os exercícios foram compilados com o GCC do MSYS2 (ambiente UCRT64), no Windows. No PowerShell, dentro desta pasta:

```powershell
gcc -Wall -Wextra -fexec-charset=CP850 Exercicios_de_ponteiros_01.c -o Exercicios_de_ponteiros_01.exe
.\Exercicios_de_ponteiros_01.exe
```

A opção `-fexec-charset=CP850` faz os acentos aparecerem corretamente no console do Windows. Em Linux ou macOS, ela pode ser retirada.

Os executáveis `.exe` não são versionados.
