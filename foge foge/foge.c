
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "fogefoge.h"

// Struct 
MAPA m;
POSICAO heroi; // Aqui, é como se eu tivesse colocando um nome de uma outra variavél nesse struct... Sendo posicao, o tipo dessa variavel. Ou seja uma variavel que contem variaveis x e y dentro dela.
// E aqui temo o x e o y que o herói está...

int acabou(){
    return 0;
}

// Move o @ pelo mapa. 
void move(char direcao){

    m.matriz[heroi.x][heroi.y] = '.';

    switch(direcao){
        case 'a':
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        case 'w': 
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;
        case 's':
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        case 'd':
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
        
    }

    
}


// Nossa função principal... 
int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, '@');

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());  
    
    liberamapa(&m);
}

