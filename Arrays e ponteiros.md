# Arrays e ponteiros

Você deve estar se perguntando o motivo pela qual tivemos que passar o inteiro como ponteiro, mas não o array. Isso não muda: se quisermos mudar uma variável que está declarada em outro escopo, não tem solução: precisamos mexer direto em seu endereço de memória, e usar ponteiros.

E, acredite ou não, fizemos isso no array. Um array é por padrão um ponteiro. A variável `chutes` é um ponteiro que aponta para o inteiro que está na primeira posição do array. Sabemos que a primeira posição do array é `chutes[0]`. Se fizermos `&chutes[0]`, temos o endereço de memória desse primeiro inteiro. Esse número é igual a `chutes`.

Veja o código:

```c
printf("%d %d", chutes, &chutes[0]);
```

Agora que você está entendendo mais sobre a memória, veja que um array é uma "sequência de variáveis" declaradas. Em particular, essas variáveis estão exatamente uma do lado da outra. Quando declaramos um array de 10 posições, a máquina procura por um lugar onde caibam 10 inteiros, um ao lado do outro.

Quando fazemos `chutes[2]`, por exemplo, a máquina então pega a posição de memória da primeira posição desse array, e vai navegando até a posição que quer. No exemplo, o número 2 quer dizer a terceira posição do array. Ele pula então 3 casas e chega no próximo inteiro.

Mas você lembra que discutimos o tamanho de um inteiro? Um inteiro ocupa 4 bytes. Isso quer dizer que se você declara uma variável inteira, a máquina separa 4 bytes da memória pra ele. Em um array, a mesma coisa, se temos um array de inteiros de 10 posições, precisamos de 40 bytes. Ou seja, se `&chutes[0]` nos retorna 10, `&chutes[1]` nos retornará 14, pois é onde o segundo inteiro começa.

![](https://s3.amazonaws.com/caelum-online-public/introducao-a-c/parte2/arrays.png)

Veja, em código. O programa abaixo declara um array de inteiros de 3 posições. Em seguida, imprimimos a posição de memória que estão guardados cada um desses números. Sabemos que um inteiro tem 4 bytes, e que os ítens de um array são guardados um ao lado do outro. Portanto, os números devem crescer de 4 em 4.

```c
#include <stdio.h>

int main() {
    int numeros[3];

    printf("%d %d %d\n", &numeros[0], &numeros[1], &numeros[2]);
}
```

A saída (que é diferente a cada vez que executarmos o trecho de código, pois o endereço de memória muda) com os endereços, pulando de 4 em 4 bytes, como esperado:

```c
1458119804 1458119808 1458119812
```

Podemos tratar esse `int[]` como um `int*`. Afinal, arrays são ponteiros. Se temos um ponteiro de inteiro, e sabemos que ele aponta para um array, podemos acessar a primeira posição fazendo `*ponteiro`. Se quisermos acessar a segunda posição, basta somarmos 1 a esse ponteiro, `*(ponteiro + 1)`. E assim por diante.

Veja o código abaixo, onde fazemos um loop, e acessamos os valores do array usando o tipo array convencional e usando diretamente o ponteiro:

```c
#include <stdio.h>

int main() {
    int numeros[3];

    // declarando um ponteiro que aponta pro
    // mesmo lugar que o array/ponteiro numeros
    int* ponteiro = numeros;

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    for(int i = 0; i < 3; i++) {
        printf("%d ", numeros[0]);

        // repare na soma que fazemos com o ponteiro
        printf("%d ", *(ponteiro + i));

        printf("\n");
    }
}
```

Sua cabeça a partir de agora deve estar muito diferente. Você consegue ver ponteiros em tudo? Lembre-se que variáveis são ponteiros para endereços de memória. A linguagem de programação geralmente nos esconde isso, e ela que se vira em manipular esse endereço e salvar nossos dados lá. Mas, se precisarmos, a linguagem C nos deixa lidar diretamente com esses endereços de memória.
