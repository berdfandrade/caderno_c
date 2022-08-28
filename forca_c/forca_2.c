
#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

int enforcou() {

	int erros = 0;

	for(int i = 0; i < tentativas; i++) {
		
		int existe = 0;

		for(int j = 0; j < strlen(palavrasecreta); j++) {
			if(chutes[i] == palavrasecreta[j]) {
				existe = 1;
				break;
			}
		}

		if(!existe) erros++;
	}

	return erros >= 5;
}

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[tentativas] = chute;
}

int jachutou(char letra) {
	int achou = 0;
	for(int j = 0; j < tentativas; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

void desenhaforca() {

	printf("Você já deu %d chutes\n", tentativas);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");

}

void escolhepalavra() {
	sprintf(palavrasecreta, "MELANCIA");
}

int main() {

	int acertou = 0;

	abertura();
	escolhepalavra();

	do {

		desenhaforca();
		chuta();
		
		tentativas++;

	} while (!acertou && !enforcou());

}