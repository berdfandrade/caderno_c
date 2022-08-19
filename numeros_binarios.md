# Números binários

Acredite ou não, uma memória de computador consegue apenas diferenciar duas coisas: se algo está imantado para um lado ou para o outro. A um dos lados atribuímos o valor 1, e ao outro, o valor 0. Ou seja, a memória de um computador não consegue guardar um número como "42", pois ela não consegue guardar nem "4" nem "2". Ela consegue guardar apenas "1"s e "0"s. E aí vem o desafio: precisamos representar qualquer coisa, usando apenas esses dois números.

Vamos ver como isso funciona devagar. Imagine o número 0, como representar ele? Fácil: 0. E o número 1? Também é fácil, 1. Pronto, temos um **bit**.

O desafio começa quando queremos representar o número 2, usando somente os números 0 e 1. A solução é usar o 10 para representar o número 2. Cuidado. Não leia `10` como dez, leia como "um zero", afinal ele não vale "dez". E o número três? 11. Isto é, "um um". E depois o número quatro? 100. Depois 101, 110, 111.

Ficamos com uma tabela:

```c
0 =>    0
1 =>    1
2 =>   10
3 =>   11
4 =>  100
5 =>  101
6 =>  110
7 =>  111
8 => 1000
...
```

Repare que a conta aqui é parecida com a que fazemos com base decimal (que é a base que usamos, ou seja, representando todos os números possíveis usando apenas de 0 a 9). Veja que não temos um "desenho" para o número dez. O que fazemos quando chegamos no maior número da nossa escala (que no caso é 9)? Empurramos um dígito para esquerda, e começamos a contagem de novo: 10, 11, 12, 13, e assim por diante.

Com números binários, é a mesma coisa. Tínhamos o 0, e depois o 1. Como 1 é o maior dígito que temos, empurramos um dígito para a esquerda, e começamos a contagem de novo: 0, 1, 10, 11, 100, 101, 110, 111, e assim por diante.

Assim como na matemática tradicional, podemos preencher com zero a esquerda para padronizar a quantidade de dígitos. Por exemplo, se usarmos 8 dígitos, ou seja, 8 bits, temos:

```javascript
 0 => 00000000
 1 => 00000001
 2 => 00000010
 3 => 00000011
 4 => 00000100
 5 => 00000101
 6 => 00000110
 7 => 00000111
 8 => 00001000
 9 => 00001001
10 => 00001010
11 => 00001011
12 => 00001100
13 => 00001101
14 => 00001110
15 => 00001111
```

O conjunto de 8 bits juntos é conhecido por 1 byte. Podemos seguir o mesmo padrão até qualquer número inteiro. Um inteiro em C tem 4 bytes. Isso quer dizer que usamos `4 vezes 8` = 32 bits. Com 32 dígitos, conseguimos representar números bastante grandes.




