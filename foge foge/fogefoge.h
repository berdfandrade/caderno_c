

// DIRETIVAS DE COMPILAÇÃO
#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

// CONSTANTES
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

// Função que acaba com o jogo.
int acabou();

// Função que move o char
void move(char direcao);
 
// Função é direção.
int ehdirecao(char direcao);

// Função fantasmas.
void fantasmas();

// Função explode pílula que chama a função explodepilula2().
void explodepilula();

// Função explode pílula que vai para as quatro diferentes direções. 
void explodepilula2(int x, int y, int somax, int somay, int qtd);


#endif