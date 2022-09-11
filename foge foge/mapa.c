
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


// Verifica se a posição do char no mapa é valida beaseada no tamanho da matriz. 
int ehvalida(MAPA* m, int x, int y){
	if(x >= m->linhas){
		return 0; 	
	}

	if(y >= m->colunas){
		return 0;
	}


	return 1; 	 
}	


// Diz que a posição especificada na função é VAZIA. 
int ehvazia(MAPA* m, int x, int y){
	return m->matriz[x][y] == VAZIO;
}


// Faz um char andar pelo mapa. 
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {
	char personagem = m->matriz[xorigem][yorigem];
	m->matriz[xdestino][ydestino] = personagem;
	m->matriz[xorigem][yorigem] = VAZIO;

}


// Lê o mapa da memória.
void lemapa(MAPA* m) {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);
	
	for(int i = 0; i < m->linhas; i++) {
		fscanf(f, "%s", m->matriz[i]);
	} 

	fclose(f);
}


// Aloca o mapa na memória.
void alocamapa(MAPA* m) {
	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i < m->linhas; i++) {
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}


// Libera o mapa da memória. 
void liberamapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		free(m->matriz[i]);
	}

	free(m->matriz);
}


// Função imprime o mapa no terminal.
void imprimemapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		printf("%s\n", m->matriz[i]);
	}
}


// Função encontra o char no mapa.
void encontramapa(MAPA* m, POSICAO* p, char c){
	for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}