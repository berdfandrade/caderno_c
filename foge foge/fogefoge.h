#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);

int ehdirecao(char direcao){
    return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}

