
struct mapa { 
    char** matriz; 
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; 

struct posicao{
    int x;
    int y; 

};

typedef struct posicao POSICAO; 

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimepa(MAPA* m);


void move(char direcao);
int acabou(); 
