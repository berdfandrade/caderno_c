#include <stdio.h>
#include <string.h>


int main(void){

}



void desenhaMatriz(int x, int y){
    char matriz[20][20]; 
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%d""%d", matriz)
        }
    }

}

void lematriz(){
    FILE* f;
	f = fopen("matriz.txt", "r");

    // SE O ARQUIVO f FALSE, ERRO NA LEITURA DO MAPA. SE O F NÃO ESTIVER LÁ. 
    if(f == 0) {
	printf("Erro na leitura do mapa");
	exit(1);
	}

}

void alocamatriz(*f){

}
void imprimemapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		printf("%s\n", m->matriz[i]);
	}
}