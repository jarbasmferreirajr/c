#include <stdio.h>

// 5. Escreva um algoritmo que leia 2 valores inteiros, "a" e "b", e escreve-os juntamente com a mensagem ‘Estes números são PARES’ ou ‘Estes números são IMPARES’, conforme o caso. //

int main(void) {

  int n1, n2, resto1, resto2;
  
  printf("Digite os dois valores: \n");
  scanf("%d%d", &n1, &n2);  
  resto1 = (n1 %2);
  resto2 = (n2 %2);
 
    if(resto1==0 && resto2==0){
    printf("Estes números são PARES.\n");
    } 
    else if(resto1!=0 || resto2!=0){
    printf("Um desses números é IMPAR.\n");
    }
 
  return 0;
}
