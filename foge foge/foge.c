

#include <stdio.h>
#include <stdlib.h>

char mapa[5][10+1]; 
int linhas;
int colunas;

int main(){

    FILE* f; 
    f = fopen("mapa.txt", "r"); 
    if(f == 0) { 
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    fscanf(f,"%d %d", &linhas, &colunas);
    printf("linhas %d colunas %d\n", linhas, colunas);
    int* v = malloc(sizeof(int) * 50);
    v[0] = 10;
    v[1] = 12;
    v[3] = 80;
    printf("inteiro alocado %d %d %d\n", v[0], v[1], v[3]);
    free(v); // Sempre que eu aloco a memória, eu preciso esvaziar... 

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]); 
    }
     
    fclose(f);

}

