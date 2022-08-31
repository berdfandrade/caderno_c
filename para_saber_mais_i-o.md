## Para saber mais: Mais sobre I/O

A biblioteca de entrada e saída da linguagem C é bastante extensa. Mesmo as funções estudadas aqui podem fazer muito mais do que o mostrado. Todas as funções, por exemplo, possuem retorno. A própria `fscanf()`, por exemplo, retorna o número de itens devolvidos. Por exemplo, se a máscara for "%d", ela retornará 1, se tudo der certo. Se a máscara for "%d %d", ou seja, capturar 2 inteiros, ela retornará 2.

```c
int n1, n2;

int sucesso = fscanf("%d %d", &n1, &n2);
if(sucesso == 2) {
    printf("Os dois números: %d e %d", n1, n2);
}
else {
    printf("Aconteceu um erro");
}
```

Podemos verificar também se o ponteiro atual do arquivo está apontando para o fim. Para isso, basta usar a função `feof()`. Ele pode ser bastante útil quando queremos ler o arquivo inteiro até o fim. Por exemplo, se quisermos ler caractere a caractere do arquivo e imprimí-lo, precisamos repetir isso enquanto não chegarmos ao fim do arquivo.

Por enquanto, a única função de leitura que vimos até então é a `fscanf()`. Ela é importante quando queremos ler caracteres ASCII e strings. Mas, muitas vezes precisamos ler um byte, um char, ou mesmo uma struct (que aprenderemos no próximo jogo). Nesses casos, precisamos ler e escrever dados de maneira "mais bruta". A função `fgetc()`, por exemplo, lê apenas o próximo `char`.

```c
FILE* f;
char c;

f = fopen("arquivo.txt", "r");
while(!feof(f)) {
    c = fgetc(f);        printf("Char %c\n", c);
}
```

Nesses casos também, as funções `fread()` e `fwrite()` podem ajudar. Elas lêem uma quantidade específica de bytes e as guardam na estrutura que você passar, seja ela um array, uma variável ou uma struct. No próximo jogo, faremos uso delas.

Perceba que daqui pra frente você começará a aprender e fazer uso de funções que são complexas e fazem muita coisa. A melhor maneira de entendê-las melhor é ler o manual oficial delas. Nisso, o Google te ajudará. Sempre que tiver dúvida dos parâmetros que uma função recebe, o que ela retorna e como interpretar esse retorno, procure pela sua definição na internet. Buscar é também parte do dia a dia do programador.
