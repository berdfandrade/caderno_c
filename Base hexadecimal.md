# Base hexadecimal

A base binária, como vimos, tem somente dois algarismos distintos para representar **todos** os números. A que utilizamos no dia a dia, tem dez algarismos. Entretanto, uma outra base bastante utilizada, a base `hexadecimal`, que tem 16 algarismos. Para representar números de 0 a 15, precisamos apenas de quatro bits.

Agora precisamos de 16 "desenhos" para representar os 16 possíveis algarismos. Para isso completamos os números de 0 a 9 com as letras A, B, C, D, E e F para representar os outros seis algarismos faltantes. Novamente, sem a necessidade de decorar a fórmula de transformação, a tabela a seguir mostra os `16` primeiros números em base hexadecimal:

```
 0 => 0
 1 => 1
 2 => 2
 3 => 3
 4 => 4
 5 => 5
 6 => 6
 7 => 7
 8 => 8
 9 => 9
10 => A
11 => B
12 => C
13 => D
14 => E
15 => F
```

E poderíamos continuar, com:

```
16  => 10
17  => 11
18  => 12
...
32  => 21
...
177 => B1
...
255 => FF
```

Portanto, com dois algarismos de base hexadecimal (16 possibilidades cada), conseguimos representar `16 * 16`, 256, números. 

## Como representar letras em números binários?

Como representar letras (chars) em números binários? Basta fazermos uma tabela, dando um número para cada letra. Por exemplo, 'A = 65'. Então 'B = 66', 'C = 67':

```
A => 65 => 01000001
B => 66 => 01000010
C => 67 => 01000011
...
Z => 90 => 01011010
```

Pronto, o computador é capaz de representar todas as letras existentes no nosso alfabeto usando somente 8 dígitos, 0 ou 1. Essa tabela do nosso alfabeto, incluindo diversos outros caracteres é a **tabela ASCII**, usada por muito tempo como o principal padrão de tradução de números e caracteres por um computador.

## Bits e imagens

Agora, um último desafio: como representar uma imagem? É fácil. Mapearemos uma imagem para um conjunto de números inteiros. E já sabemos que conseguimos representar números inteiros de forma binária.

Imagine então uma foto. Ela é composta por diversos pontos, e cada um desses pontos tem uma cor diferente. Imagine que a foto tem 1000 por 1000 pontos. O que podemos fazer é primeiro enumerar todas as cores existentes. Mas vamos limitá-las a 256 diferentes:

```
cor0   = verdecor1   = vermelhocor2   = azulcor3   = pretocor4   = branco
...
cor255 = cinza
```

Mas não podemos usar o nome da cor: precisamos dar um número para ela. Por exemplo:

```
cor0   = 00FF00 (verde)
cor1   = FF0000 (vermelho)
cor2   = 0000FF (azul)
cor3   = 000000 (preto)
cor4   = FFFFFF (branco)
...
cor255 = CCCCCC (cinza)
```

Com essa tabela em mãos, podemos escrever uma linha para cada ponto na foto. Se o primeiro ponto da foto é vermelho (cor1) e o segundo azul (cor2) e o terceiro cinza (cor255), em uma imagem com diversas linhas, temos:

```
cor1 cor2 cor255 cor3 cor3 cor2 cor3 cor255cor1 cor3 cor255 cor3 cor2 cor3 cor3 cor255
...
```

Mas como sabemos que temos no máximo 256 cores, podemos representá-las mais facilmente com números em hexadecimal:

```
01 02 FF 03 03 02 03 FF
01 03 FF 03 02 03 03 FF
...
```

Isto é, a sequência `01 02 FF` representa uma pequena imagem de 3 pontos, cujas cores seriam vermelho, azul e cinza. Já `0102FF03030203FF\n0103FF03020303FF` representa uma imagem com 2 linhas e 8 colunas.

Com isso podemos representar qualquer imagem com tamanho finito (que caiba na memória) e que o número de cores esteja limitado a `256`. Esse é o raciocínio atrás de um mapa de bits de cores, um **bitmap**, o formato `BMP`, muito utilizado antigamente no mundo da computação. Sua adoção não é mais tão grande devido ao tamanho que o mesmo ocupa: uma imagem com grande qualidade exige uma tabela de cores enorme, e um número de pontos maior ainda. Algoritmos de compressão como o `JPEG` dominam esse mercado.

Assim como pensamos na alternativa de representar um terço como uma fração (um dividido por três), poderíamos representar uma imagem como uma sequência de traços, círculos etc. E essa também é uma idéia boa para diversos tipos de imagem, e é o raciocínio por trás das imagens vetoriais, como o **SVG**.

O mesmo pode ser aplicado ao mundo da música, com o `WAV` e `MP3`, aos filmes etc. No fim, representamos desde um número inteiro até uma imagem de tomografia com apenas zeros ou uns. Assustador.


