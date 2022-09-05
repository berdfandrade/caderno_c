# Definindo Structs

Repare que sempre que usamos o `mapa`, usamos também as variáveis `linhas` e `colunas`. Afinal, sempre precisamos delas para navegar na matriz. Como essas variáveis são globais, não temos problemas para usá-las. Mas e se precisássemos passá-las como parâmetros para alguma função? Seria trabalhoso; teríamos muitos parâmetros.

Pela primeira vez temos um conjunto de variáveis que "não fazem sentido separadas". A matriz só faz sentido se tiver uma linha e coluna junto. Precisamos agrupá-las, e garantir que elas sempre serão "transportadas" juntas. Para tal, usaremos uma **struct**. Estruturas (ou, em C, `struct`) são uma maneira que temos para agrupar variáveis. Ou seja, definiremos que a estrutura "mapa" contém uma matriz (o ponteiro de ponteiro de `char`), uma variável para guardar a quantidade de linhas (`int`) e outra para guardar a quantidade de colunas (também `int`). Com essa estrutura definida, podemos declarar variáveis que a seguem. Dessa forma, garantiremos sempre que mapas tem uma matriz, e a quantidade de linhas e colunas.

Veja a declaração da `struct` abaixo, que colocamos dentro do nosso `fogefoge.h`. Dentro dele, declaramos a matriz e os dois inteiros para guardar as suas dimensões:

```c
struct mapa {
    char** matriz;
    int linhas;
    int colunas; 
};
```

Como dissemos anteriormente, com essa struct em mãos, podemos fazer uso dela e declarar variáveis desse tipo. Mas diferente de um inteiro ou um char que usamos até então, ela tem variáveis dentro dela. Para acessá-las, usamos ponto (.). Veja o trecho de código abaixo, por exemplo, onde definimos um mapa e setamos os valores para `linhas` e `colunas`. Repare na palavra `struct` no começo da declaração:

```c
struct mapa facil;

char tabuleiro[10][20];
facil.matriz = &tabuleiro;
facil.linhas = 10;
facil.colunas = 20;

printf("O mapa tem tamanho %d x %d", facil.linhas, facil.colunas);
```

Vamos fazer as devidas alterações no código, usando agora a struct que definimos. A começar pelas variáveis globais, que são substituídas:

```c
struct mapa m;
```

Em todo lugar que fazia uso de `linhas` ou `colunas`, precisamos trocar para `m.linhas` e `m.colunas`. Em todo lugar que tínhamos a matriz `mapa`, agora precisamos usar `m.matriz`.

Um detalhe importante é perceber precedência de operadores. Por exemplo, dentro da função `lemapa()`, temos o `fscanf()`, que agora ficou parecido com o código abaixo:

```c
fscanf(f, "%d %d", &m.linhas, &m.colunas);
```

A instrução `&m.linhas` é processada corretamente. Passamos o endereço da variável `linhas` que está dentro da struct `m`. Uma outra interpretação dessa instrução seria que o `&` é para a variável `m`, ou seja, gostaríamos do endereço de memória da estrutura `m` como um todo. Para evitar essa possível ambiguidade, é comum fazermos uso de parênteses para deixar claro a ordem de precedência:

```c
fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
```

A função `move()`, com todas as alterações, fica como a abaixo:

```c
void move(char direcao) {
    int x;
    int y;

    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {
            if(m.matriz[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }     switch(direcao) {
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'w':
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
    }

    m.matriz[x][y] = '.';
}
```

Apesar da sensação de que agora temos muito mais código escrito, usar `struct`s para agrupar dados que devem ficar perto é uma boa prática. Você verá que, em breve, deixaremos de usar variáveis globais, e começaremos a passar essas structs pra lá e pra cá. Mas, como elas agrupam tudo o que precisamos, fica fácil: a função receberá apenas um ponteiro para a estrutura.
