# Jogo da Forca em C

A primeira coisa que eu faço é `#include <stdio.h>`,  que inclui cabeçalho de biblioteca. A próxima coisa que eu faço é criar a nossa `int main()`, que indica o início do programa. 

```c
int main(){
}
```

No nosso caso aqui, vou criar um array para armazenar as palavras do jogo. E em `C`, eu declaro o array, primeiramente colocando a quantidade de inteiros que aquele array vai armazenar. No nosso caso, vai ser um array de inteiros, então declaro com `int`.

```c
// Exemplo

int main(){
    int notas[10];

    notas[0] = 10;
    notas[2] = 9;
    notas[3] = 8;
    notas[9] = 4;

    printf("notas %d %d %d\n", notas[0], notas[2], notas[9]);
}
```

Agora que entendemos o array, podemos então fazer uso do `do-while`, um outro tipo de loop, idêntico ao `while`, com a exceção de que ele executa o bloco de código ao menos uma vez. Repare na condição `while(!acertou && !enforcou)`. Conseguimos lê-la em português: **enquanto não acertou E não enforcou**.

```c
int acertou = 0;
int enforcou = 0;

do {
    // código aqui
} while(!acertou && !enforcou);
```

Então, até agora, escrevemos o programa dessa forma. Trocamos os arrays de exemplo, pelo array que vamos usar no código. 

```c
// jogo da forca 

#include <stdio.h>

int main(){
    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");
    
    int acertou = 0;
    int enforcou = 0;
    
    do {

    } while (!acertou && !enforcou); 
```

Vamos agora capturar uma letra do usuário, e ver se essa letra existe na palavra secreta. Para isso, precisaremos fazer um `for` na palavra (afinal, sabemos o tamanho dela), e comparar se o `char` que está naquela posição bate com o informado pelo usuário. Para capturar o tamanho da palavra dentro de um array de chars, usamos a função `strlen()`. Ela está disponível em `<string.h>`.

Usaremos no `for`, que irá de 0 (primeira posição do array) até `strlen()`, que é a última posição preenchida. Em seguida, compararemos o conteúdo daquela posição com o chute dado, e avisaremos o usuário se ele acertou o chute:

```c
do {
    char chute;

    printf("Qual letra? ");
    scanf("%c", &chute);

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(palavrasecreta[i] == chute) {
            printf("A posição %d tem essa letra\n", i+1);
        }
    }
} while (!acertou && !enforcou);
```
