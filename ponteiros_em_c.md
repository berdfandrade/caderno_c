Para provar que quando usamos parâmetros em funções e passamos uma variável como parâmetro, mesmo que os nomes sejam iguais, elas são diferentes, veja o progama abaixo. O método `main` contém uma variável `tentativas`, e ele faz operações de incremento com essa variável e imprime. Em seguida, ele passa a variável para a função `joga()`, que faz um incremento, e imprime. Ao final, o método `main` imprime novamente o valor da variável.

```c
#include <stdio.h>

void joga(int tentativas) {
    printf("joga %d\n", tentativas);
    tentativas++;
    printf("joga %d\n", tentativas);
}

int main() {

    int tentativas = 0;
    printf("main %d\n", tentativas);

    tentativas++;
    printf("main %d\n", tentativas);

    tentativas++;
    printf("main %d\n", tentativas);

    joga(tentativas);

    printf("main %d\n", tentativas);

}
```

O interessante é a saída desse programa. Veja que a variável no método `main()` vale 2, quando chamamos a função `joga()`. Em seguida, a função `joga()` incrementa 1, e podemos ver que ela imprime o número 3. Mas, quando voltamos para a função `main`, ele imprime novamente 2:

```c
main 0
main 1
main 2
joga 2
joga 3
main 2
```

Isso nos prova que ambas as variáveis apesar de terem o mesmo nome, são diferentes. Quando invocamos a função `joga()`, passando a variável `tentativas`, declarada no método `main`, a máquina copia o conteúdo dela, cria uma nova variável chamada `tentativas`, que será visível só na função `joga()`. Quando a função `joga()` termina, e o programa volta pro método `main`, a variável `tentativas` continua valendo 2. Afinal, ela não foi modificada depois disso.

Esse isolamento entre as funções é uma coisa boa. Imagine se você passasse uma variável como parâmetro para uma função, e essa função tivesse a liberdade de mudá-la? Seu programa seria mais complicado de ser entendido, afinal, você não saberia bem quem mudou a variável e quando. É por isso que chamamos isso de **passagem por cópia**. Ou seja, sempre que passamos uma variável para uma função, a máquina copia a variável e cria uma nova, para que a original fique intacta.

Muitas vezes a passagem por cópia é suficiente. Mas, às vezes não. Volte ao nosso jogo, e veja a variável `tentativas`. Ela deveria contar a quantidade de chutes já dados pelo jogador. O método `chuta` é o responsável por incrementar essa variável, mas é a variável `tentativas` do método `main` também fosse incrementada. Nesse momento, o parâmetro `tentativas` é o que é incrementado, e sabemos que eles são variáveis diferentes. Ou seja, gostaríamos, nesse caso, que a variável `tentativas` da função `chuta` fosse a mesma da função `main`.

```c
void chuta(char chutes[26], int tentativas) {
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}

int main() {
    // ...

    chuta(chutes, tentativas);

    // a soma precisa acontecer na variável
    // 'tentativas', que existe no escopo
    // da função 'main'
    tentativas++;

    // ...
}
```

## Passagem por referência

Podemos dizer ao nosso programa que não queremos que ele passe o parâmetro por cópia, mas sim, pelo que chamamos de **referência**. A passagem por referência é algo bastante avançado. Como que a máquina faz para passar uma variável por referência? Simples, ela passa a posição da memória que essa variável está. Imagine a memória do computador como uma fita imensa e numerada. Todas as variáveis de nossos programas ficam nessa fita, em algum lugar.

Pense novamente na passagem por cópia. Imagine que a variável `tentativas` do método `main` está na posição 10 da memória. Quando passamos por cópia, a máquina aloca um novo espaço na memória para a nova variável `tentativas`. Imagine que ela ficou na posição 200. Ou seja, uma variável aponta para a posição 10, enquanto a outra aponta para a posição 200.

Você precisa pensar agora em variáveis como se elas fossem setas, ou melhor, **ponteiros** para endereços de memória, pois é exatamente isso que elas são.

![](https://s3.amazonaws.com/caelum-online-public/introducao-a-c/parte2/variaveis.png)

E, se no fundo, variáveis são apenas ponteiros para endereços de memória, por quê não ter duas variáveis que apontam para o mesmo endereço? Podemos fazer isso. Por exemplo, se quisermos ver o endereço de memória que uma variável aponta, usamos o caractere **&**. O programa abaixo imprime o endereço de memória da variável `c`. Repare que sempre que o rodarmos, o número será diferente, afinal, cada hora a máquina decide pegar um endereço de memória diferente (e que está livre naquele momento, claro):

```c
#include <stdio.h>

int main() {

    int c = 10;
    printf("%d\n", &c);

}
```

Isso quer dizer que se passarmos como parâmetro para uma função, um `&c`, por exemplo, estaremos passando o endereço de memória que essa variável está. Isso quer dizer que se modificarmos o conteúdo que está dentro desse endereço, então ele será modificado para todo mundo que tenha uma variável apontada pra lá.

Se você declara uma variável do jeito que está acostumado, então a máquina esconde de você a ideia de que ela é na verdade um ponteiro. E é por isso que você consegue fazer coisas como atribuições, por exemplo, `c = 10`, e a máquina faz o processo de pegar o endereço de memória que está escondido em `c` e colocar o valor 10.

Mas, você também tem a opção de manipular diretamente um endereço de variável. Ou seja, declarar um ponteiro. Um ponteiro simplesmente contém um endereço de memória. Declarar um ponteiro é parecido com declarar uma variável: precisamos de um nome e de um tipo. Mas, completamos o tipo com estrela (`*`).

Veja o exemplo abaixo, onde declaramos um ponteiro para um inteiro. Se ele é um ponteiro, quer dizer que podemos guardar o endereço da variável `c` lá dentro. Para pegar o endereço dela, basta usarmos o `&`.

```c
int c = 10;

int* ponteiro;
ponteiro = &c;
```

Nesse momento, a variável `ponteiro` aponta para o mesmo lugar que `c` aponta. Se imprimirmos então `&c` e `ponteiro`, o resultado é o mesmo:

```c
printf("%d %d", ponteiro, &c);
```

Agora, se quisermos acessar o que está dentro do endereço para qual `ponteiro` aponta, usamos o `*` na frente da variável. Por exemplo, se imprimirmos a variável `c` e `*ponteiro`, o resultado é o mesmo (10):

```c
printf("%d %d", *ponteiro, c);
```

Ou seja, se a variável é um ponteiro, e queremos acessar o conteúdo que está dentro do endereço que ela aponta, usamos estrela. Veja novamente o código inteiro, e perceba como manipulamos uma variável normal e uma variável ponteiro.

```c
int c = 10;
int* ponteiro;

// ponteiro apontando para o mesmo endereco de c
ponteiro = &c;

// imprime o endereco da variavel c
printf("%d %d\n", ponteiro, &c);

// imprime o conteúdo da variavel c
printf("%d %d\n", *ponteiro, c);
```
