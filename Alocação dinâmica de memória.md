# Alocação dinâmica de memória

Mas e se quisermos mapas com tamanhos diferentes, para, por exemplo, diferenciar o nível do jogo? Quanto mais difícil, maior o mapa. O grande problema é: como variar o tamanho da matriz?

Uma possível estratégia seria ter uma matriz gigante, que suportasse o maior mapa possível. Por exemplo, uma matriz `mapa[100][100]`. Nosso programa então olharia apenas para a quantidade de linhas e colunas daquele mapa, em particular, que será sempre menor que 100x100.

Aqui, tomaremos outra decisão: a de gerar um array (ou matrizes) de tamanhos aleatórios. Leremos o arquivo, descobriremos o tamanho do mapa, e então, declararemos uma matriz com o tamanho ideal.

Para fazer isso, precisamos mudar a maneira de declararmos nosso array, alocando a memória necessária em tempo de execução. Para isso, usaremos a função `malloc()`. Ela recebe como parâmetro a **quantidade de bytes que precisa ser alocado**, e nos devolve um ponteiro para o primeiro byte alocado.

O código abaixo, por exemplo, aloca um único byte. Como ele nos devolve um ponteiro, o seu retorno pode ser armazenado em um ponteiro de `char`:

```c
char* letra = malloc(1);
*letra = 'M';
```

Se quiséssemos guardar um `int` precisaríamos de mais de 1 byte, afinal inteiros são representados por 4 bytes. O código então seria algo como:

```c
int* numero = malloc(4);
*numero = 20;
printf("%d", *numero);
```

Mas como a quantidade de bytes que um inteiro ocupa pode variar de plataforma para plataforma, é melhor dizermos ao compilador para usar o tamanho do inteiro daquela plataforma. Para isso, usamos a instrução `sizeof(int)`, que nos retorna o tamanho do inteiro correto:

```c
int* numero = malloc(sizeof(int));
*numero = 20;
printf("%d", *numero);
```

Como o `malloc()` simplesmente aloca a quantidade de bytes desejada e nos devolve um ponteiro, para declararmos um array de maneira dinâmica, basta apenas passarmos a quantidade de bytes corretos. Por exemplo, se quisermos um array de inteiros de 10 posições, precisamos passar 40 para ele (4 bytes por inteiro vezes 10 inteiros). Com esse número, sabemos que podemos manipular um ponteiro como se fosse um array:

```c
// calcula o tamanho de bytes
int colunas = 10;
int memoria = sizeof(int) * colunas;

// aloca memoria suficiente para o array
int* numeros = malloc(memoria);

// usa o ponteiro como se fosse um array
numeros[2] = 10;
printf("%d", numeros[2]);
```

Já para uma matriz, temos mais de uma abordagem. Imagine uma matriz de 5 linhas por 10 colunas. Precisamos primeiro alocar um array para guardar 5 ponteiros de inteiros. Depois, alocar 5 arrays de 10 posições, e guardar cada um desses arrays nos ponteiros de inteiros declarados anteriormente.

Veja, em código:

```c
int** matriz;

int linhas = 5;
int colunas = 10;

// alocando espaço para as linhas,
// que guardam ponteiro de inteiro.
matriz = malloc(sizeof(int*) * linhas);

// agora, para cada linha, alocamos
// espaço para um array com 10 ("colunas") posições.
for(int i = 0; i < linhas; i++) {
    matriz[i] = malloc(sizeof(int) * colunas);
}

// agora podemos usar 'matriz' como uma matriz
matriz[2][3] = 10;
```


