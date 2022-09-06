
struct mapa { 
    char** matriz; 
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; 

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimepa(MAPA* m);


void move(char direcao);
int acabou(); 
