# Caderno de C

<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/berdfandrade/caderno_c?color=%23A8B9CC&label=.&logo=C&logoColor=FFFFFF">

Este é o meu caderno de exercícios e anotações referentes a linguagem de programação C. Aqui eu segui alguns tutoriais e incrementei funcionalidades específicas nos pequenos programas que eu desenvolvi. Alguns deles contém anotações. O principal projeto que desenvolvi foi o [jogo de adivinhação](https://github.com/berdfandrade/jogo_de_adivinhar_c) e também um jogo de [FOGE FOGE](https://github.com/berdfandrade/caderno_c/tree/main/foge%20foge) que é baseado em Pac-Man. 

A linguagem de programação C é uma das linguagens de programação mais populares e influentes de todos os tempos. Aqui estão alguns dos seus pontos fortes:

- Eficiência: A linguagem C é conhecida por ser uma linguagem de programação de baixo nível, o que significa que ela fornece acesso direto ao hardware do computador. Por isso, ela é muito eficiente em termos de tempo de execução e uso de memória. Isso a torna uma escolha popular para desenvolver sistemas operacionais, drivers de dispositivos e outras aplicações de baixo nível.

- Portabilidade: A linguagem C é portátil, o que significa que os programas escritos em C podem ser compilados e executados em diferentes plataformas sem necessidade de grandes mudanças no código. Isso a torna uma escolha popular para o desenvolvimento de aplicativos que precisam ser executados em vários sistemas operacionais.

- Flexibilidade: A linguagem C é uma linguagem de programação estruturada que permite que os desenvolvedores criem programas complexos de maneira organizada e bem estruturada. Além disso, ela fornece recursos para programação de baixo nível e de alto nível, o que significa que os desenvolvedores podem escolher a melhor abordagem para resolver um problema específico.

- Grande comunidade: A linguagem C tem uma comunidade grande e ativa, com muitos recursos, fóruns e bibliotecas disponíveis para os desenvolvedores. Isso torna mais fácil encontrar soluções para problemas específicos e aprender com outros programadores experientes.

Exemplos de código em C:

1. Hello World:

```c
#include <stdio.h>
int main() {
   printf("Hello, World!");
   return 0;
}
```
2. Bubble Sort

 Aqui está um exemplo de implementação do algoritmo de ordenação Bubble Sort em C:

```c
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        // troca os elementos arr[j] e arr[j+1]
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
```
O código acima recebe um array arr com n elementos e o ordena em ordem crescente utilizando o algoritmo Bubble Sort. O funcionamento do Bubble Sort consiste em percorrer o array diversas vezes, comparando elementos adjacentes e trocando-os caso necessário, até que o array esteja completamente ordenado.




