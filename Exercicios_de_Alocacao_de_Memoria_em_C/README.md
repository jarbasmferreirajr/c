# Exercícios de Alocação Dinâmica de Memória em C

Exercícios com `malloc`, `calloc`, `realloc` e `free`: vetores, strings, matrizes e registros alocados em tempo de execução.

## Lista de exercícios

| Arquivo | O que faz |
|---|---|
| `Exercicios_de_Alocacao_de_Memoria-01.c` | Aloca um vetor de 5 inteiros, lê, mostra e libera a memória |
| `Exercicios_de_Alocacao_de_Memoria-02.c` | Aloca um vetor do tamanho informado pelo usuário, lê e imprime |
| `Exercicios_de_Alocacao_de_Memoria-03.c` | Lê o vetor numa função separada e conta quantos valores são pares e ímpares |
| `Exercicios_de_Alocacao_de_Memoria-04.c` | Aloca uma string do tamanho informado e a imprime sem as vogais |
| `Exercicios_de_Alocacao_de_Memoria-05.c` | Cria um vetor de N posições e conta os múltiplos de um número X |
| `Exercicios_de_Alocacao_de_Memoria-06.c` | Simula a memória de um computador, com inserção e consulta por posição |
| `Exercicios_de_Alocacao_de_Memoria-07.c` | Confere um bilhete de loteria e guarda os acertos num vetor do tamanho exato |
| `Exercicios_de_Alocacao_de_Memoria-08.c` | Aloca 1500 inteiros com `calloc` e confere se todos começam em zero |
| `Exercicios_de_Alocacao_de_Memoria-09.c` | Lê números até um valor negativo, aumentando o vetor com `realloc` |
| `Exercicios_de_Alocacao_de_Memoria-10.c` | Aloca com `malloc` um vetor de `double` de pelo menos 10 posições e o usa como vetor comum |
| `Exercicios_de_Alocacao_de_Memoria-11.c` | Cadastro de alunos com `struct`, para a quantidade informada no início |
| `Exercicios_de_Alocacao_de_Memoria-12.c` | Cadastro de produtos de um estoque |
| `Exercicios_de_Alocacao_de_Memoria-13.c` | Aloca uma matriz de inteiros e procura um valor nela |
| `Exercicios_de_Alocacao_de_Memoria-14.c` | Aloca uma matriz de números reais, lê e imprime formatada |
| `Exercicios_de_Alocacao_de_Memoria-15.c` | Lê números sem limite de quantidade até o usuário digitar 0 |
| `Exercicios_de_Alocacao_de_Memoria-16.c` | Aloca blocos variados: 1 KB, matriz 10x10, 50 registros de produto e texto de 100 linhas |
| `Exercicios_de_Alocacao_de_Memoria-17.c` | Cadastra cidades com coordenadas e calcula as distâncias entre elas |
| `Exercicios_de_Alocacao_de_Memoria-18.c` | Calcula o produto de duas matrizes alocadas dinamicamente |
| `Exercicios_de_Alocacao_de_Memoria-Outros-01.c` | Preenche um vetor somando 2 a partir do primeiro número informado |
| `Exercicios_de_Alocacao_de_Memoria-Outros-2.c` | Simula uma aplicação financeira com juros mensais |
| `Exercicios_de_Alocacao_de_Memoria-Outros-3.c` | Lista dinâmica com menu para incluir e listar itens |

## Como compilar e executar

No PowerShell, dentro desta pasta, com o GCC do MSYS2 (UCRT64):

```powershell
gcc -Wall -Wextra -fexec-charset=CP850 Exercicios_de_Alocacao_de_Memoria-01.c -o Exercicios_de_Alocacao_de_Memoria-01.exe
.\Exercicios_de_Alocacao_de_Memoria-01.exe
```

O exercício 17 usa `sqrt()`, então precisa de `-lm` no final do comando.
