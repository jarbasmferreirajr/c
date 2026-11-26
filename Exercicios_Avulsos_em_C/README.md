# Exercícios Avulsos em C

Exercícios avulsos de funções, condicionais e primeiros cadastros com `struct`.

## Lista de exercícios

| Arquivo | O que faz |
|---|---|
| `1-Exercicios_de_funcao-Questao_1_a.c` | Função que desenha uma linha de `=` com o tamanho pedido |
| `1-Exercicios_de_funcao-Questao_1_b.c` | Função que soma todos os inteiros de um intervalo, invertendo os limites se necessário |
| `1-Exercicios_de_funcao-Questao_1_c.c` | Junta as duas funções anteriores num programa em laço, que encerra ao digitar 0 |
| `1-Exercicios_de_funcao-Questao_2.c` | Calcula o consumo de combustível em km/l e mostra uma mensagem conforme o resultado |
| `1-Exercicios_de_funcao-Questao_3.c` | Calcula a área de retângulo, triângulo ou círculo com funções para ler, calcular e exibir |
| `2-Exercicios_de_Funcao-Calcula_Dias_Bissexto.c` | Calcula os dias entre o ano de nascimento e o ano atual, considerando os anos bissextos |
| `2-Exercicios_de_Funcao-Potenciacao.c` | Função de potência que trata expoente zero e negativo |
| `3-Revisao-Exercicio_de_Funcao-Calculo_de_Volume.c` | Calcula o volume de um lote de caixas e verifica se cabe na van, aceitando vírgula ou ponto |
| `Exercicio_Dois_Numeros_Pares_ou_Algum_Numero_Impar.c` | Informa se dois números são pares ou se algum deles é ímpar |
| `Exercicio_Qual_dia_da_semana_que_voce_nasceu.c` | Descobre o dia da semana de uma data de nascimento, com validação da data |
| `Exercicio_de_Struct-Cadastro_de_Livros_com_Menu.c` | Cadastro de livros com `struct` e menu de opções |
| `Exercicio_de_struct-Cadastro_de_produtos.c` | Cadastro de produtos com `struct` |

## Como compilar e executar

No PowerShell, dentro desta pasta, com o GCC do MSYS2 (UCRT64):

```powershell
gcc -Wall -Wextra -fexec-charset=CP850 Exercicio_Qual_dia_da_semana_que_voce_nasceu.c -o Exercicio_Qual_dia_da_semana_que_voce_nasceu.exe
.\Exercicio_Qual_dia_da_semana_que_voce_nasceu.exe
```

A opção `-fexec-charset=CP850` faz os acentos aparecerem corretamente no console do Windows. Em Linux ou macOS, ela pode ser retirada.
