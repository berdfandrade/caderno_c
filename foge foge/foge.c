
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "fogefoge.h"

// Struct 
MAPA m;
POSICAO heroi; // Aqui, é como se eu tivesse colocando um nome de uma outra variavél nesse struct... Sendo posicao, o tipo dessa variavel. Ou seja uma variavel que contem variaveis x e y dentro dela.
// E aqui temo o x e o y que o herói está...

void fantasmas(){
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(m.matriz[i][j] == FANTASMA){
                if(ehvalida(&m, i, j+1)){
                    andanomapa(&m, i, j, i, j+1); 
                }
            }
        }
    }
}
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
        case ESQUERDA:
            proximoy--; 
            break;
        case CIMA: 
            proximox--; 
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
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
    encontramapa(&m, &heroi, HEROI);

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while (!acabou());  
    
    liberamapa(&m);
}

