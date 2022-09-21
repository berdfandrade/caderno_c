
// DIRETIVAS DE COMPILAÇÃO 

#ifndef _MAPA_H_
#define _MAPA_H_

// CONSTANTES

#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'

// Definindo o que é uma mapa, através de um struct
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

// STRUCT MAPA;
typedef struct mapa MAPA;

// Função que aloca o mapa na memória.
void alocamapa(MAPA* m);

// Função que lê o mapa da memória.
void lemapa(MAPA* m);

// Função que libera o mapa da memória.
void liberamapa(MAPA* m);

// Função que imprime o mapa no terminal.
void imprimemapa(MAPA* m);

// Struct que define o que é uma posição.
struct posicao {
	int x;
	int y;
};

// STRUCT POSICAO	
typedef struct posicao POSICAO;

// Função que encontra o char no mapa.
int encontramapa(MAPA* m, POSICAO* p, char c);

// Função que verifica se a posição no mapa é valida.
int ehvalida(MAPA* m, int x, int y);

// Função que verifica se o ponto no mapa é uma parede.
int ehparede(MAPA* m, int x, int y);

// Função que verifica se é o ponto no mapa é um personagem.
int ehpersonagem(MAPA* m, char personagem, int x, int y);

// Função que define como andar no mapa.
void andanomapa(MAPA* m, int xorigem, int yorigem, 
	int xdestino, int ydestino);

// Função que copia o mapa para o FANTASMA se mover.
void copiamapa(MAPA* destino, MAPA* origem);

// Função que verifica se o personagem pode andar naquele ponto do mapa. 
int podeandar(MAPA* m, char personagem, int x, int y);

#endif