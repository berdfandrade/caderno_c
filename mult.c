#include <stdio.h>

int main() {

  int numero_1;
  printf("Qual número você quer multiplicar por 10?\n");
  scanf("%d", &numero_1);

  for(int i = 0; i <= 10; i++) {
    int multiplicacao = numero_1 * i;
    printf("%d x %d = %d\n", numero_1, i, multiplicacao);
  }
}