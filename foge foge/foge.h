
struct mapa { 
    char** matriz; 
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; 

void liberamapa();
void lemapa();
void alocamapa();
void imprimepa();


void move(char direcao);
int acabou(); 
