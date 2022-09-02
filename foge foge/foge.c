

#include <stdio.h>
#include <stdlib.h>
#include "foge.h"

char** mapa; 
int linhas;
int colunas;

// Libera a o mapa da memória.. 
void liberamapa(){
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa); 
}

// Aloca o mapa na memória. 
void alocamapa(){
    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < linhas; i++) {
    mapa[i] = malloc(sizeof(char) * (colunas+1));
    }
}

// Lê o arquivo do mapa. 
void lemapa(){
    
    FILE* f; 
    f = fopen("mapa.txt", "r"); 
    if(f == 0) { 
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    fscanf(f,"%d %d", &linhas, &colunas);

    alocamapa();

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

// Imprime o mapa no arquivo .C
void imprimemapa(){
        for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]); 
    }

} 

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    // Acha a posição do foge foge. 
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++) {
            if(mapa[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a':
            mapa[x][y-1] = '@';
            break;
        case 'w': 
            mapa[x-1][y] = '@';
            break;
        case 's':
            mapa[x+1][y] = '@';
            break;
        case 'd':
            mapa[x][y-1] = '@';
            break;
        
    }

    mapa[x][y] = '.';
}


// Nossa função principal... 
int main(){

    lemapa();

    do {
    
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());  
    
    liberamapa();
}

