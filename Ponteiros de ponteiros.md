## Ponteiros de ponteiros

No curso anterior, discutimos que um array/vetor é simplesmente um ponteiro que aponta para uma posição da memória que tem espaços vazios para guardar as `N` posições declaradas.

Uma matriz é uma abstração ainda maior. Ela é um ponteiro que aponta para uma lista de arrays. Como arrays são ponteiros, então uma matriz é um ponteiro que aponta para uma lista de ponteiros.

Ou seja, `mapa` é um ponteiro que aponta para outros ponteiros. Isso significa que `mapa[0]` é um ponteiro que aponta para um array, `mapa[1]` é um ponteiro que aponta para outro array, e assim por diante. Veja na imagem abaixo:

![](https://s3.amazonaws.com/caelum-online-public/introducao-a-programacao-com-c-parte-3/matrizes2.png)

## Ponteiros de ponteiros

Em código, nada nos impede de declararmos uma matriz e depois declarar ponteiros que apontam para cada um dos vetores dentro dessa matriz. Veja o código abaixo. `linha0[0]` é igual a `numeros[0][0]`, afinal tanto `linha0` quanto `numeros[0]` apontam para o mesmo endereço de memória.

```c
int numeros[5][10];

int* linha0 = numeros[0];
int* linha1 = numeros[1];
int* linha2 = numeros[2];
int* linha3 = numeros[3];
int* linha4 = numeros[4];

// os numeros serao iguais, afinal
// ambos ponteiros apontam para o mesmo 
// endereço de memória
printf("%d %d", linha0, numeros[0]);
```

Ou seja, nesse loop que faremos, guardaremos a primeira linha no array `mapa[0]`, a segunda linha no array `mapa[1]` e assim por diante. Veja que no código acima, declaramos `int*` para representar cada array que está dentro da matriz. Mas e se quiséssemos um novo ponteiro para apontar para a matriz como um todo? Como ela é um ponteiro que aponta para outros ponteiros de inteiro, a declaração é `int**`, ou seja, duas estrelas para representar "ponteiro de ponteiro":

```c
int numeros[5][10];

// o ponteiro copia é idêntico ao
// ponteiro numeros... ambos apontam
// para uma lista de ponteiros de inteiros
int** copia = numeros;

// as duas operações abaixo são idênticas
numeros[0][0] = 10;
copia[0][0] = 10;
```

Ou seja, enquanto um array é um ponteiro para uma lista de posições de memória que estão livres para guardar o tipo escolhido, uma matriz é um ponteiro que aponta para uma lista de ponteiros, que por sua vez, apontam para posições de memória livres para guardar algo.
