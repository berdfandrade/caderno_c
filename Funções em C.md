# Funções em C

Você reparou que nosso jogo ainda não tem uma mensagem de bem vindo ao usuário? Vamos colocá-la então:

```c
int main() {

    // imprime cabecalho
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");

    // codigo continua aqui
}
```

Nosso jogo, em termos de funcionalidades, está andando bem. Mas vamos dar uma pausa nelas, para atacar outro detalhe importantíssimo na hora de fazermos um software. Você lembra do código do jogo de adivinhação? Ele ficou muito legal, mas ao final da implementação, tínhamos uma função `main()` com mais de 100 linhas de código. São muitas linhas, e isso dificulta muito o entendimento do código por outras pessoas. Você mesmo, faça o teste. Daqui algumas semanas, volte e olhe o mesmo código: você lembrará muito menos dele.

Precisamos aprender a dividir nosso programa em partes menores, que sejam mais fáceis de serem lidas. Precisamos fazer igual as bibliotecas do C fazem. Por exemplo, quando você quer imprimir algo na tela, você chama a função `printf()`. Você não sabe como ela funciona por dentro, apenas sabe que ela imprime. A mesma coisa com o `scanf()´: você não sabe como ela faz, apenas o quê ela faz.

## Escrevendo funções

Imagine se conseguíssemos trocar então as 3 linhas responsáveis pela abertura do jogo, e trocar por uma única linha? Ao parecido com o comentário, mas em formato de código, sem espaços, usando os parênteses, e terminando a linha com ponto-e-vírgula:

```c
abertura();
```

O que queremos aqui é criar o que chamamos de **funções**. Funções são blocos de código encapsulados e que podem ser reutilizados ao longo do nosso programa. Por exemplo, se criarmos uma função que se chama `abertura()`, contendo aquelas 3 linhas de impressão, sempre que a invocarmos, nosso programa fará isso. É igual ao `printf()` ou `scanf()`: ambos são funções, que utilizamos ao longo do nosso programa.

Vamos criar essa função e usá-la em nosso programa. Escreveremos esse código fora da função `main` (afinal, ela própria é uma função, e não podemos ter funções dentro de funções). Para declarar uma função, precisamos no mínimo de um nome. Pode ser qualquer palavra, como por exemplo, o nome que escolhemos. Então, faremos `void abertura()`. Você não precisa entender o `void` por enquanto, e nem o abre e fecha parênteses. Em seguida, abriremos chaves e colocaremos o conteúdo dela dentro desse bloco de código:

```c
void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}
```

Agora vamos fazer uso dessa função. E o faremos dentro do método `main()`. Vamos remover aquelas 3 linhas, que agora estão já na função certa, e apenas invocá-la. Para invocar é fácil, usamos seu nome e parênteses:

```c
int main() {

    abertura();

    // codigo continua aqui

}
```

Se rodarmos nosso código agora, o comportamento ainda é o mesmo. A diferença é que agora nosso método `main` é um pouco mais fácil de ser lido. Quando o programador lê `abertura()`, ele sabe que é ali que é feita a abertura, mas não sabe os detalhes. Se ele quiser saber os detalhes, ele vai ler então o corpo da função `abertura()`. Diminuímos a quantidade de código que o programador precisou ler para entender o método `main()`.

Vamos entender o que acontece com a máquina ao executar esse código. Quando o programa começa, ele automaticamente executa a função `main()`. Ele vai executando linha a linha do código. Até aí, sem novidades. Mas, quando ele encontra uma chamada para outra função, por exemplo, a função `abertura()`, ele então "suspende" a execução do método `main()`, e vai para o outro método. Lá, o procedimento é o mesmo. Ele executa linha a linha. Quando o método `abertura()` acaba, ele volta então para o método `main` e continua a execução a partir dali.

Se tivéssemos uma outra chamada de função dentro do `abertura()`, o comportamento seria o mesmo. A máquina suspenderia a execução desse método, executaria o outro, e quando ele acabasse, voltaria para ele, que, por sua vez, quando acabasse, voltaria para o `main`.

## Passando parâmetros para as funções

Variáveis vivem, e são visíveis, apenas no escopo em que foram declaradas. Por exemplo, se declaramos uma variável dentro do método `main()`, essa variável estará visível somente dentro desse método e dos escopos declarados dentro desse método (por exemplo, se você tiver um `for` dentro desse método, ele conseguirá ver essa variável).

No código abaixo, a variável `multiplicador`, declarada dentro do método `main()` é visível em todo lugar dentro dessa função. Já a variável `resultado`, declarada dentro do `for` é visível somente dentro desse `for` (ou em outros escopos que fossem declarados dentro dele). Entretanto, ambas não são visíveis dentro da função `abertura()`:

```c
void abertura() {
    // aqui nao enxergamos a variável multiplicador
    printf("Tabuada do ");
    printf("Quero imprimir o multiplicador aqui, mas nao consigo...");
}

int main() {
    int multiplicador = 2;

    abertura();

    for(int i = 0; i < 10; i++) {
        int resultado = multiplicador * i;
        printf("%d x %d = %d", i, multiplicador,             resultado);
    }
}
```

Para resolver esse problema, temos duas soluções. A primeira delas é passando as variáveis que queremos para as outras funções. E podemos fazer isso. Basta, no momento da declaração da variável, dizermos quais serão os parâmetros que ela receberá. E, na hora de invocarmos, passamos os parâmetros pra ela. Fazemos isso nos "parênteses" no momento da declaração. Basta dizermos o nome do parâmetro e seu tipo.

Veja, por exemplo, a função `abertura()` recebendo como parâmetro um inteiro `multiplicador`. Esse parâmetro é como se fosse uma variável para aquela função. Ela existe naquele escopo e pode ser manipulada como qualquer outra variável:

```c
void abertura(int multiplicador) {
    // aqui temos uma variável chamada multiplicador
    // e seu valor será definido por quem chamar essa função
    printf("Tabuada do %d", multiplicador);
}
```

Isso significa que não podemos mais invocar a função `abertura()` sem passar os seus parâmetros. Sempre precisamos passar os parâmetros que as funções requerem. Nesse caso em particular, precisamos sempre passar um inteiro pra ela. Veja:

```c
// passando um inteiro diretamente
abertura(2);
```

E, já que ela recebe um inteiro, porque não passar também um inteiro que está em uma variável? Veja:

```c
int main() {
    // passando uma variável
    int numero = 10;
    abertura(numero);
}
```

Repare que estamos passando a variável `numero` como parâmetro para a função `abertura()`. Ela contém o número 10. Isso quer dizer que, quando a função `abertura` for executada, o parâmetro `multiplicador` valerá 10 também. É como se a máquina "copiasse" o valor da variável `numero` e colasse na variável `multiplicador`.

Para que esse nosso pequeno código de tabuada funcione, basta então invocarmos o método `abertura()`, passando a variável `multiplicador`. Repare que, apesar de ambos os nomes serem iguais (o da variável e o do parâmetro), não é o nome que fez tudo acontecer. Ou seja, o parâmetro `multiplicador` é diferente da variável `multiplicador` que está na `main()`; apenas os conteúdos é que são iguais. Lembre-se que, quando você chama uma função, por exemplo, `abertura(10)`, a máquina pega o número 10 e coloca dentro do parâmetro que foi declarado na função (que pode ter qualquer nome).

```c
void abertura(int multiplicador) {
    printf("Tabuada do %d\n", multiplicador);
}

int main() {
    int multiplicador = 2;

    abertura(multiplicador);

    for(int i = 0; i < 10; i++) {
        int resultado = multiplicador * i;
        printf("%d x %d = %d\n", i, multiplicador,             resultado);
    }
}
```
