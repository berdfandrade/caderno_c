# Lendo arquivos

A única parte chata do jogo é que a palavra secreta está fixa. Depois que ele adivinhar a primeira vez, acabou. Precisamos dar um jeito de fazer com que a palavra seja randômica. Criar números randômicos é fácil, mas agora palavras que façam sentido... isso é, com certeza, um problema computacional bastante desafiador.

O que faremos é escolher uma palavra aleatória de um arquivo de texto, que será nosso "banco de dados de palavras". Esse arquivo pode ter qualquer tamanho, ou seja, você poderá colocar novas palavras lá sempre que quiser, e o programa deve entender isso.

Vamos começar então escrevendo um arquivo de exemplo. Sempre que queremos criar um arquivo que será lido pelo computador, precisamos definir um formato. Como separaremos as palavras? Por vírgula? Por enter? O formato é importante, afinal, o programa precisará saber como interpretá-lo.

Nosso arquivo terá o seguinte formato: a primeira linha nos indicará quantas palavras existem naquele arquivo. Em seguida, teremos as várias palavras, uma em cada linha. Isso facilitará a nossa leitura via código. Veja o arquivo, que chamaremos de `palavras.txt`:

```c
3
MELANCIAMORANGOMELAO
```

Agora vamos começar a ler esse arquivo. A primeira coisa que precisamos fazer é abrí-lo. Para isso, precisamos declarar um ponteiro do tipo `FILE*`, e usar a função `fopen()` que abre um arquivo do disco. Essa função nos devolve então um ponteiro (que guardaremos na variável já declarada), e a partir daí, passamos esses ponteiros para as funções que lerão os caracteres desse arquivo. Repare no `"r"`. Isso indica que estamos abrindo o arquivo somente para leitura (poderíamos tê-lo aberto para escrita).

Todo o código estará dentro da função `escolhepalavra()`:

```c
void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
}
```

Essa é a primeira vez que estamos lidando com recursos de I/O, ou seja, de entrada ou saída. Na prática, elas podem falhar, pois o arquivo pode não estar disponível, ou não termos permissão de leitura, etc. Então, sempre que lidamos com isso, precisamos tratar as possíveis falhas.

A função `fopen()` devolve um ponteiro com endereço 0, caso algum erro tenha acontecido. Vamos tratar esse possível erro, e caso ele tenha acontecido, devolveremos uma mensagem para o usuário e acabaremos com nosso programa ali mesmo (usando a função `exit()`, que finaliza a aplicação). Repare que o parâmetro 1, passado ao `exit` indica ao sistema operacional que o programa terminou de maneira que ele não gostaria; ou seja, um erro ocorreu. Se tivéssemos retornado 0, o sistema operacional saberia que o programa rodou de acordo com o esperado. A função `exit()` está declarada em `stdlib.h`. Precisamos colocar o `include`:

```c
#include <stdlib.h>

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }
}
```

Agora sim, estamos prontos para começar a ler nosso arquivo, e sabemos que na primeira linha, temos a quantidade de palavras que leremos na sequência. Vamos capturar esse número. Você já sabe mais ou menos como ler do arquivo. Em C, temos a função `fscanf()`, similar a função que você já conhece. A diferença dela é que o primeiro parâmetro é o ponteiro para um arquivo.

Se quisermos ler um inteiro de um arquivo, por exemplo, fazemos igual ao código abaixo. Repare que a função sabe que o número "acabou" quando encontrar um enter no arquivo. Ou seja, nesse caso, ela lê até achar um fim de linha.

```c
int qtddepalavras;
fscanf(f, "%d", &qtddepalavras);
```

Toda vez que lemos de um arquivo, a leitura é sequencial. Ou seja, se já capturamos o primeiro número, a próxima vez que chamarmos a função `fscanf()`, ela continuará a leitura do ponto que parou. É como se ela tivesse uma pequena seta, que aponta para a posição que está lendo no arquivo no momento.

Vamos ler então a próxima coisa que aparece no arquivo. Sabemos que é uma palavra. Vamos declarar um array e ler, usando a máscara "%s". Dado que em nosso exemplo, sabemos que temos 3 palavras lá, vamos ler 3 palavras de uma só vez, apenas para teste:

```c
char palavra1[50];
fscanf(f, "%s", palavra1);

char palavra2[50];
fscanf(f, "%s", palavra2);

char palavra3[50];
fscanf(f, "%s", palavra3);
```

Nesse momento, se imprimirmos as 3 strings, teremos MELANCIA, MORANGO e MELAO, igual esperávamos. Mas, nesse nosso jogo em particular, não precisamos salvar todas elas, mas sim somente uma (a que escolhermos de maneira aleatória). Vamos então gerar um número aleatório, de 0 até a quantidade de elementos, e salvar apenas a palavra que estiver naquela posição.

Não temos como pular direto para a linha que queremos, então precisaremos fazer um loop com a função `fscanf()` e, na linha certa, salvar o retorno. Para facilitar, vamos salvar a palavra secreta já na variável correta `palavrasecreta`. Repare que a última interação do loop será justamente a linha randômica escolhida. O loop acabará e a a variável terá a palavra secreta que queremos:

```c
int qtddepalavras;
fscanf(f, "%d", &qtddepalavras);

// gera numero aleatorio
// nao esqueça de incluir time.h 
srand(time(0));
int randomico = rand() % qtddepalavras;

// lê do arquivo até chegar na linha desejada
for(int i = 0; i <= randomico; i++) {
    fscanf(f, "%s", palavrasecreta);
}
```

Nosso código está quase pronto. Já selecionamos uma palavra aleatória dentro do nosso banco de dados de palavras. Só estamos esquecendo uma coisa: sempre que lidamos com I/O, precisamos lembrar de abrir o arquivo (ou qualquer outra fonte de entrada), usá-la e, ao final, fechá-la.

Fechar é importante. Ele libera aquele recurso para que outros programas consigam fazer uso dele também. Quando abrimos um arquivo para leitura, o sistema operacional pode bloquear a leitura dele de outros aplicativos até que o programa corrente termine seu trabalho. Ou seja, feche o mais rápido possível. Fazemos isso com a função `fclose()`.

O método `escolhepalavra()` completo ficou:

```c
void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}
```

Veja só que ao longo dessa seção, só alteramos um ponto do nosso arquivo, que foi a função `escolhepalavra()`. E tudo funciona. Veja só como dividir nosso programa em funções bem definidas é realmente útil. Podemos fazer mudanças em pequenas partes do programa sem nos preocuparmos com o todo. É isso que faz um código ser fácil de ser mantido: quando conseguimos mexer apenas em pontos específicos, sem a necessidade de ler ou alterar todo o código.
