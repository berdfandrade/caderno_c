
#include <stdio.h>

void potencia(int* resultado, int a, int b){
    *resultado = 1;

    for(int i = 0; i < b; i++){
        *resultado = *resultado * a;
    }

}

int main(){
    int resultado;
    potencia(&resultado, 10, 5);
    printf("---------------\n");
    printf("O resultado é %d\n", resultado);
    printf("---------------\n");
}

// Para > enquanto 0 for menor que B, faça o loop. Pegamos o resultado como parâmetro da função Main; Na verdade a função main que definiou o parâmetro do da função potência. O B, é a potencia, porque o B é a quantidade de vezes que vamos multiplicar o número a pelo número a. 
