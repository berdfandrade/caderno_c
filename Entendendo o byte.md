# Entendendo o byte

O conjunto de 8 bits juntos é conhecido por 1 byte. Podemos seguir o mesmo padrão até qualquer número inteiro. Um inteiro em C tem 4 bytes. Isso quer dizer que usamos `4 vezes 8` = 32 bits. Com 32 dígitos, conseguimos representar números bastante grandes.

## Bits: 8, 16, 32, 64

Se tivéssemos apenas oito bits para representar um número inteiro, poderíamos representar `2 elevado a 8` números, que é igual a 256. Parece pouco, mas acredite ou não, nossos primeiros videos games, como o Master System, tinham processadores de 8 bits, e sabiam só representar números de 0 a 255.

O Mega Drive, um pouco melhor, tinha um processador de 16 bits, e com isso, representava números inteiro de 0 a 65.535 (ou seja, `2 elevado a 16` números diferentes). Não é a toa que os jogos do Master tinham em geral no máximo 256 cores, enquanto as do Mega tinham até 65 mil.

Mas mesmo esse número, será que ele é capaz de representar todos os números inteiros que queremos? Ou ainda um processador capaz de entender e armazenar 16 bits é capaz de representar todas as letras de todos os alfabetos do mundo?

Os processadores modernos são capazes de representar números com até 64 bits, o que dá bons bilhões, além de todo o conjunto de caracteres dos alfabetos existentes no mundo. Mesmo assim existem otimizações para representar o alfabeto, como um padrão famoso por ter substituído o ASCII como mais utilizado na internet em 2008, o UTF-8.


