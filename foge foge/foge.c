
#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.c" 

// Struct 
MAPA m;
POSICAO heroi // Aqui, é como se eu tivesse colocando um nome de uma outra variavél nesse struct... Sendo posicao, o tipo dessa variavel. Ou seja uma variavel que contem variaveis x e y dentro dela.

int acabou(){
    return 0;
}

// Move o @ pelo mapa. 
void move(char direcao){
    int x;
    int y;

    encontramapa(MAPA* m, POSICAO* p, char c);

    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'w': 
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
        
    }

    m.matriz[x][y] = '.';
}


// Nossa função principal... 
int main(){

    lemapa(&m);

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());  
    
    liberamapa(&m);
}

