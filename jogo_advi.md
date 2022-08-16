# Jogo de adivinhação em C

#### Essas são minhas anotações sobre o programa. As anotações não possuem uma ordem específica.

A primeira coisa que fazemos é incluir a a diretiva de C, standard input header. `#include <stdio.h>` e fazemos a declaração da variável. Esse código imprime o cabeçalho do nosso jogo. Toda linha em C termina com ponto e vírgula.

```c
#include <stdio.h> 

int main() { 
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
```

Depois para criar uma variável aleatória, incluímos a diretiva `<time>`, `#include <time.h>`

E como vamos, posteriormente usar uma variável `double`, vamos ter que incluir a diretiva `#include <stdlib.h>`, e nosso cabeçalho vai ficar assim.

Quando o programa está compilado em C, ele vira um arquivo binário que eu não consigo ler..

```c
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
```

Em C, não existe uma biblioteca de números aleatórios. Por isso temos que pegar uma biblioteca que é a quantidades de segundos que se passaram desde janeiro de 1970 até o último segundo passado. 

Todo programa em C, tem a função `int main()`. 

A variável para funcionar precisa ter sido declarada anteriormente dentro do bloco de código. Lembrando que o `int main()` é um bloco de código. Ou seja, sempre que você for declarar uma variável, você precisa pensar no escopo em que essa variável existe. E só lembrar que o escopo são as chaves.

```c
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

```

Depois declaramos diferentes variáveis. 

```c
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

```

Inicializamos a pontuação agora com a variável `double pontos`, 

```c
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



```

Na variável `int nivel` definimos o nível de dificuldade e o número de tentativas para cada nível. 

Agora começamos um `for loop`.

```c
    for(int i = 1; i <= numerodetentativas; i++) {

        printf("Qual é o seu chute?\n\n");
        printf("Tentativa %d\n", tentativas);
        scanf("%d", &chute);
        printf("\nSeu chute foi %d\n\n", chute);
    
        if(chute < 0) {
        printf("Digite um número positivo\n");
        continue; 
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;


```

Agora criamos um outro `if statement`

```c
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

```

 O compilador, lê o seu código da esquerda para a direita. Então primeiro ele vai ler `(chute - numerosecreto) / 2;)` > Depois ele vai ler `double pontosperdidos`.

E por último, definimos o `output`, quando o jogador acerta o número. Também usamos esse código para calcular os pontos. 

```c
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
```

/ A máscara do `double` é `%f`  o .`1` é a quantidade de casas decimais que você quer que apareça.

Então nosso código inteiro fica assim. 

```c
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

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

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

```
