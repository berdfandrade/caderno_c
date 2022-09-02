

void libermapa();
void lemapa();
void alocamapa();
void imprimepa();
void move(char direcao);
int acabou(); 

struct mapa { 
    char** matriz; 
    int linhas;
    int colunas;
};