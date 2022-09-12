

// Deifinindo caracteres para mexer o herói. 
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
void fantasmas(); // void é uma função que não retorna nada.    

// Definindo o que é considerado um caractére de direção. 
int ehdirecao(char direcao){
    return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}

