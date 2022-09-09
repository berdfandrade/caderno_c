
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

    if(direcao != 'a' && direcao != 'w' && direcao != 's' && direcao != 'd')
    return; // Aqui esse return simplesmente quebra "quebra o código... A função para."

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
        case 'a':
            proximoy--; 
            break;
        case 'w': 
            proximox--; 
            break;
        case 's':
            proximox++;
            break;
        case 'd':
            proximoy++; 
            break;
        
    }

    if(!ehvalida(&m, proximox, proximoy)) 
        return; 

    if(!ehvazia(&m, proximox, proximoy)) 
        return; 

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy); 
        heroi.x = proximox;
        heroi.y = proximoy;
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

