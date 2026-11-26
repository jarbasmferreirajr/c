# C
[PT-BR] - Esses são meus projetos referentes a estudos, exercícios de cursos, projetos pessoais e comerciais com as tecnologias da "Linguagem C".  

[ENG] - These are my projects relating to studies, course exercises, personal and commercial projects with "C Language" technologies.

## Conteúdo

| Pasta | Assunto |
|---|---|
| [Exercicios_Avulsos_em_C](Exercicios_Avulsos_em_C) | Funções, condicionais e primeiros cadastros com `struct` |
| [Simulado_da_1_Prova_de_Prog.Estruturada_em_C](Simulado_da_1_Prova_de_Prog.Estruturada_em_C) | Simulado da 1ª prova de Programação Estruturada |
| [Exercicios_de_Ponteiros_em_C](Exercicios_de_Ponteiros_em_C) | Ponteiros, passagem por referência e aritmética de ponteiros |

Cada pasta tem um README com a lista dos exercícios.

> **Observação:** na raiz fica o [`Hello_World.c`](Hello_World.c), o primeiro programa do repositório, o clássico "Olá mundo!". Ele é o exemplo usado em "Como compilar".

## Como compilar

Os exercícios foram feitos no Windows, com o GCC do MSYS2 (ambiente UCRT64). Por exemplo, para compilar e executar o `Hello_World.c` no PowerShell, na raiz do repositório:

```powershell
gcc -Wall -Wextra -fexec-charset=CP850 Hello_World.c -o Hello_World.exe
.\Hello_World.exe
```

Para os outros exercícios, o comando é o mesmo, trocando o nome do arquivo e rodando dentro da pasta dele.

A opção `-fexec-charset=CP850` faz os acentos aparecerem corretamente no console do Windows. Em Linux ou macOS, ela pode ser retirada.
