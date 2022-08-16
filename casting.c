
#include <stdio.h>

int main() {

    int a = 3;
    int b = 2;

    // Eu posso converter as int em doubles, usando o casting, que é colocar entre () parênteses double > (double).

    double numeros = (double)a / (double)b;
    printf("%f\n", numeros);

    // Posso fazer a mesma coisa com int. 
    double pi = 3.1415;
    int piconvertido = (int)pi;
    printf("PI convertido = %d\n", piconvertido);
    printf("PI = %f\n", pi);


}