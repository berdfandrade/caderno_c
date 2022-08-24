# Funções com retorno

A próxima função que vamos extrair de nosso código é a função que será responsável por nos dizer se o jogador já chutou determinada letra. Veja que é isso que o `for` de dentro faz. Ele varre a palavra secreta e a lista de chutes, e guarda na variável `achou` se o usuário já chutou ou não aquela letra.

É fácil ver que esse `for` usa o array de chutes, afinal, ele precisa passear por todo ele, e precisa também da letra que será procurada. Vamos escrever a função `void jachutou()`, que receberá um `char letra`, um `char* chutes` (lembre-se que um array é um ponteiro, então podemos receber como um ponteiro), e a quantidade de tentativas.

Vamos também relembrar a lógica dessa função. Ela varria o array, procurando por um chute que seja igual a letra que ele quer comparar. Se ele achar a letra no array, então ele marcava a variável `achou` como 1. O 1, para nós, significa "verdadeiro". Caso contrário, `achou` era falso. Essa variável então era usada mais pra baixo, para exibir ou não a letra, mas isso não vem ao caso, já que não faz parte de dizer se uma letra já foi ou não chutada.

```c
void jachutou(char letra, char* chutes, int tentativas) {
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
}
```

Com a função escrita, vamos fazer uso dela e invocá-la no lugar onde o código antigo existia. O código ficou simples. Declaramos a variável `achou`, a inicializamos com 0, e invocamos nossa função `jachutou`. Em seguida, o `if` que imprime ou não a letra usa essa variável:

```c
for(int i = 0; i < strlen(palavrasecreta); i++) {
    int achou = 0;

    jachutou(palavrasecreta[i], chutes, tentativas);

    if(achou) {
        printf("%c ", palavrasecreta[i]);
    } else {
        printf("_ ");
    }
}
```

Mas esse código ainda não funciona. Afinal, já sabemos que a variável `achou`, declarada dentro da função `main()` não é a mesma da declarada dentro da `jachutou`. Se quisermos "compartilhar" a variável, precisaremos passar o ponteiro dela. Sabemos que isso não é difícil, pois bastaria passarmos o endereço de `achou`, usando `&achou`, e receber o ponteiro do outro lado, como parâmetro, um `int* achou`.

Apesar da alternativa ser válida, geralmente temos uma solução mais elegante pra isso. Veja que a variável `achou` é o "resultado" da nossa função `jaachou`. Ou seja, ela processa, faz um monte de coisa, mas ao final, precisa apenas "contar para quem chamou ela" o resultado dessa variável. Quando uma função precisa devolver apenas um dado (um número, ou char, ou double, ou qualquer outra coisa) para quem a chamou, damos um tipo de retorno para ela.

Até agora, sempre que declaramos uma função, usamos a palavra `void` ao começo. Usamos `void` quando a função não precisa retornar nada a quem chamou. Mas, se ela precisar retornar, podemos trocar essa palavra pelo tipo de retorno. Por exemplo, queremos devolver um inteiro, então trocamos a palavra `void` por `int`:

```c
int jachutou(char letra, char* chutes, int tentativas) {
    // ...
}
```

Agora, precisamos indicar qual o valor que deve ser retornado por essa função. Para fazer isso, basta usarmos a palavra `return`. Quando essa palavra aparece dentro de uma função, geralmente acompanhada por um valor (por exemplo, `return 10;` para retornar o valor 10), a função para ali e quem chamou essa função recebe esse valor.

Aqui, queremos retornar o conteúdo da variável `achou` ao final da função. Então colocaremos como última linha, esse retorno. Além disso, precisamos declarar a variável `achou` no começo dessa função e inicializá-la com 0, pois ela não existia ali até então:

```c
int jachutou(char letra, char* chutes, int tentativas) {
    int achou = 0;

    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}
```

Agora, nossa função `jachutou` está pronta. Ela nos devolve um inteiro sempre que invocarmos ela. Esse inteiro vale 1 quando ele achar a letra, e 0 quando não achar. Veja que isso parece uma função da matemática. Dado um conjunto de valores de entrada, ela nos devolve um resultado como saída. É por isso que chamamos de função.

Como matemática nos dá bons exemplos de funções, poderíamos ter uma função que nos devolva o quadrado de um número. Ela receberia um número como parâmetro e devolveria a multiplicação dele por ele mesmo. Veja, em código:

```c
int quadrado(int n) {
    return n * n;
}
```

Usar essa função é igual igual usar funções que devolvem `void`. A diferença, claro, é que elas nos retornam algo. Para capturarmos o valor retorno delas, precisamos guardá-la em uma variável. Veja, por exemplo, alguns exemplos de uso da função `quadrado()`, algumas delas guardando em variáveis, outras usando-as diretamente:

```c
// guardando em uma variável
int resultado = quadrado(2);
printf("%d", resultado);

// usando diretamente em um if
if(quadrado(3) < 10) {
    printf("Já sabia, o quadrado de 3 é 9");
}

// usando direto em um printf
printf("%d", quadrado(5));
```

Voltando ao jogo, vamos agora fazer uso direito da função `jachutou`. Como vimos que podemos usá-la diretamente dentro do `if`, sem a necessidade de uma variável auxiliar, vamos usá-la diretamente no condicional que decide mostrar ou não a letra. Veja como nosso código está cada vez mais simples:

```c
for(int i = 0; i < strlen(palavrasecreta); i++) {

    if(jachutou(palavrasecreta[i], chutes, tentativas)) {
        printf("%c ", palavrasecreta[i]);
    } else {
        printf("_ ");
    }

}
```
