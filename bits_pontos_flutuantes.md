# Bits e números com ponto flutuante

Agora temos a questão dos números com ponto flutuante. Como representar tais números, se o computador só conhece zeros e uns? Do mesmo jeito que fizemos com as letras, precisamos de algum padrão. Para entender melhor, vamos criar o nosso próprio padrão, mais simples do que um usado hoje em dia.

Imagine o número treze e meio, também conhecido como 13,5. Quantos dígitos ele possui antes da casa decimal? Dois (em binário, `0010`). Quaia são esses dígitos? `1` (`0001`) e `3` (`0011`). Por fim, o valor da casa decimal é `5` (`0101`). Portanto, para representar o número `13,5`, utilizaremos a notação que indica o número de casas antes da vírgula (`2`), o valor dela, dígito a dígito (`1` e `3`) e o valor decimal (`5`):

```
0010 0001 0011 0101
```

Pronto. O computador é capaz de entender números como `13,5`. Com isso, somos capazes de representar qualquer número com casas decimais, cuja quantidade de dígitos é finita, mesmo que essa técnica esteja longe de ser ótima ou perfeita.

Mas ainda temos uma limitação: neste tipo de abordagem, como representar o valor `1 / 3`, isto é, um terço? Esse número tem uma quantidade infinita de dígitos.

Uma primeira opção seria arredondarmos o número `0,3`, perdendo precisão:

```
0001 0000 0011
```

Já que o arredondamento foi ruim, podemos tentar melhorá-lo `0,33`:

```
0001 0000 0011 0011
```

Ou mais ainda, `0,333`:

```
0001 0000 0011 0011 0011
```

Como o computador costuma seguir padrões de tamanho fixo, é comum que o número de ponto flutuante, assim como um número inteiro, utilize 64 bits. Isso limita a nossa aproximação. Para nosso um terço, usando essa ideia apresentada (não ideal), temos a melhor aproximação de `0,333.3` com `62` casas após a vírgula.

```
0001 0000 0011 0011 0011 ... 0011
```

Nossa abordagem de representação é bastante limitada, mas a representação escolhida por um processador é bem mais inteligente que essa e permite aproximações muito boas.
