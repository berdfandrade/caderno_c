#include <stdio.h>
int main()
{
   int primeiro, segundo, *p, *q, soma;

   printf("Coloque dois inteiros\n");
   scanf("%d %d", &primeiro, &segundo); // Aqui ele vai pegar os inteiros e apontar para o endereço de memória.

   p = &primeiro; // Transformando a variável "Primeiro" em "p", para facilitar.
   q = &segundo;

   soma = *p + *q;

   printf("A soma dos números = %d\n", soma);

   return 0;
}