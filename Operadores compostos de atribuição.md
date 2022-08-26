# Operadores compostos de atribuição

Os operadores compostos de atribuição: `+=`, `-=`, `*=`, `/=`, são muito utilizados em expressões matemáticas como atalhos para as operações aritméticas mais comuns.

Por exemplo: ao invés de escrever: num = num + 5 ; pode-se utilizar a seguinte expressão: num += 5;

De forma geral temos:

***Operando1 += Operando2;***

Também podemos usar `-=`, `*=` ou `/=` respectivamente para subtração, multiplicação ou divisão.

***Exemplo de utilização:***

```c
num -= 1; // equivale a num = num – 1;
num *= 2; // equivale a num = num * 2;
num /= 2;// equivale a num = num / 2;

```

No programa em C abaixo temos um exemplo de utilização desses operadores.

```c
#include<stdio.h>
#include<stdlib.h>

int main(void)  
{ 
  int num;
  
  num = 10; //atribuindo 10 na variável num
  printf("Valor inicial de num = %d \n",num);
  
  num += 5; //equivale a num = num + 5
  printf("Somando 5 ao valor inicial temos num = %d \n",num);
    num -= 1; // equivale a num = num - 1
  printf("Sutraindo 1 temos num = %d \n",num);
  
  num *= 2; // equivale a num = num * 2
  printf("Multiplicando por 2 temos num = %d \n",num);
  
  num /= 2;// equivale a num = num / 2
  printf("Dividindo por 7 temos num = %d \n",num);
  return 0; 
} 
```
