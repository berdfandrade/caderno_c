

#include <stdio.h>

// Quando o programa está compilado em C, ele vira um arquivo binário que eu não consigo ler..

// Imprime o cabeçalho do nosso jogo! 
// Toda linha em C termina com ponto e vírgula! 

int main() { // Todo programa em C, tem a função main()
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numerosecreto = 42;

    int chute;


    for(int i = 1; i <= 6; i++) { // Isso quer dizer que o código vai repetir 3 vezes. Toda vez que o seguinte código fizer um loop, vamos acrescentar 1 na variável i. Geralmente chamamos essa variável de contador. 

        printf("Qual é o seu chute?\n");
        printf("Tentatiava %d de 6\n", i); // o i é o contador, ou seja o valor dele é a tentativa que estou no momento.
        scanf("%d", &chute); 
        printf("Seu chute foi %d\n", chute);
        
        // Entendemos aqui que o usuário vai digitar um número inteiro. >> depois digitamos a variável. O (&) é usado só no scanf. É o equivalente a um input do python

        // A Linguagem C não tem true ou false; o true ou false em C, é representado pelo 0 e pelo 1; Sendo 0 falso, e 1 verdadeiro.  

        // A variável para funcionar precisa ter sido declarada anteriormente dentro do bloco de código. Lemnbrando que o int main() é um bloco de código. Ou seja, sempre que vocÊ for declarar uma variável, você precisa pensar no escopo em que essa variável existe. E só lembrar que o escopo são as chaves. 

        if(chute == numerosecreto){
            printf("Você acertou!\n");
            break; // Para o código. 

        } else { // igual do javascript

            printf("Você errou!\n");
            if(chute > numerosecreto){
                printf("Seu chute foi maior que o número secreto.\n");
            }

            if(chute < numerosecreto){
                printf("Seu chute foi menor que o número secreto.\n");

            }
            
        }
    }

    printf("Fim de jogo!");
}