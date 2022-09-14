

//CONSTANTES 

// |Constante do herói. 
#define HEROI '@'
// | Constante que define o vazio no mapa. 
#define VAZIO '.'
// Constante que define o fantasma. 
#define FANTASMA 'F' 
// | Constante que define a parede vertical no mapa. 
#define PAREDE_VERTICAL '|'
// Constante que define a parede horizontal do mapa. 
#define PAREDE_HORIZONTAL '-'

// Criando o struct mapa.
struct mapa { 
    char** matriz; 
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; 

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);

// Struct que define a posição no mapa. 
struct posicao{
    int x;
    int y; 
    
};

typedef struct posicao POSICAO; 

// Função para encontrar o mapa
int encontramapa(MAPA* m, POSICAO* p, char c);

// Função para validar a posição do herói
int ehvalida(MAPA* m, int x, int y); 

// Função para verificar se o mapa é vazio 
int ehvazia(MAPA* m, int x, int y);

//Função que faz o elemento andar pelo mapa. 
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);

// Funçãoq que copia o mapa, e replica ele. 
void copiamapa(MAPA* destino, MAPA* origem);

// Função que verifica se o elemento pode andar. 
int podeandar(MAPA* m, char personagem, int x, int y);

// Função que verifica se o caráctere é um personagem 
int ehpersonagem(MAPA* m, char personagem, int x, int y); 

// Função que verifica se é uma parede. 
int ehparede(MAPA* m, int x, int y); 


