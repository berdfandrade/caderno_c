
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mapa.h"
#include "fogefoge.h"

// Struct MAPA, e o HEROI 
MAPA m;
POSICAO heroi;

// Função que define para onde o fanstama vai (randomicamente). 

int praondeofantasmavai(int xatual, int yatual, int* xdestino, int* ydestino){
    
    int opcoes[4][2] = {
		{ xatual   , yatual+1 }, 
		{ xatual+1 , yatual   },  
		{ xatual   , yatual-1 }, 
		{ xatual-1 , yatual   }
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

		if(podeandar(&m, opcoes[posicao][0], opcoes[posicao][1])) {
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];
            return 1;
        }

    }

    return 0; 
}

// Função que imprime o fantasma e faz ele andar.

void fantasmas(){
    MAPA copia;

    copiamapa(&copia, &m);

    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA) {

                int xdestino; 
                int ydestino;

                int encontrou = praondeofantasmavai(i, j, &xdestino, &ydestino);

                if(encontrou){
                    andanomapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
   
    }

liberamapa(&copia);

}

int acabou(){
    return 0;
}

// Move o HEROI pelo mapa. 

void move(char direcao){

    if(direcao != 'a' && direcao != 'w' && direcao != 's' && direcao != 'd')
    return;

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

    // Verifica se a o ponto na matriz é valido.

    if(!ehvalida(&m, proximox, proximoy)) 
        return; 

    // Verifica se o ponto na matriz é está vazio.
    if(!ehvazia(&m, proximox, proximoy)) 
        return; 

    // Função que faz os elementos andarem no mapa. 
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy); 
        heroi.x = proximox;
        heroi.y = proximoy;
    }


// Nossa função principal... (main)
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

