

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() { 
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    


    int segundos = time(0);
    srand(segundos);

    int numeroaleatorio = rand();

    int numerosecreto = numeroaleatorio % 100;
    int chute;
    int ganhou = 0; 
    int tentativas = 1;
    int acertou = 0;
    

    double pontos = 1000; 

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil (4) Muito difícil (5) Impossível!\n\n" );
    printf("Escolha a dificuldade: ");
    scanf("%d", &nivel);


    int numerodetentativas = 2;

    switch (nivel) {
    case 1: 
        numerodetentativas == 25;
        break; 
    case 2:
        numerodetentativas == 20;
        break;
    case 3:
        numerodetentativas == 10;
        break;
    case 4:
        numerodetentativas == 5;
        break;
    default:
        numerodetentativas == 2;
        break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {


        printf("Qual é o seu chute?\n\n");
        printf("Tentativa %d\n", tentativas);
        scanf("%d", &chute); 
        printf("\nSeu chute foi %d\n\n", chute);

        if(chute < 0){
            printf("Digite um número positivo\n");
            continue; 
            
        }

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou){
            break;

        } else if (maior){
            printf("Você errou!\n");
            printf("Seu chute foi maior que o número secreto.\n\n");

        } else {
                printf("Você errou!\n\n"); 
                printf("Seu chute foi menor que o número secreto.\n\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double) 2; 
        pontos = pontos - pontosperdidos;
    }
    
    if(acertou){    
        printf("Você demorou %d tentativa(s) para acertar!\n", tentativas);
        printf("Fim de jogo!\n\n");
        printf("Total de pontos: %.1f\n\n", pontos); 
        printf("---------------------------------\n");

    } else {
        printf("Você perdeu! Tente de novo.\n");
        printf("---------------------------------\n");
    }


}
