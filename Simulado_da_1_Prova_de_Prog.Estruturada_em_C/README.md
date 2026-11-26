# Simulado da 1ª Prova de Programação Estruturada

Simulado de prova com um sistema de monitoramento de bateria: um vetor de `struct Celula` (identificador e carga) é analisado para encontrar células em estado crítico.

## Arquivos

| Arquivo | O que faz |
|---|---|
| `Sistema_implementacao_logica_e_retorno.c` | Função que conta as células com carga abaixo de 20% e devolve o resultado |
| `Sistemas_integracao_e_consumo_na_funcao_main.c` | Integra as funções do simulado e consome os resultados na função `main` |
| `Sistemma_exibicao_de_dados.c` | Emite o relatório de manutenção, com células críticas, menor carga e status da bateria |

## Como compilar e executar

No PowerShell, dentro desta pasta, com o GCC do MSYS2 (UCRT64):

```powershell
gcc -Wall -Wextra -fexec-charset=CP850 Sistemas_integracao_e_consumo_na_funcao_main.c -o Sistemas_integracao_e_consumo_na_funcao_main.exe
.\Sistemas_integracao_e_consumo_na_funcao_main.exe
```
