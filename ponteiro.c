
// Ponteiro, exemplo; 
// pelo visto, o computador executa primeiro a função main()...

#include <stdio.h>

void calcula(int* c){
    printf("calcula %d %d\n", c, (*c));
    (*c)++;

}

int main() { 

    int c = 10; 
    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);

}

// O & é a palavra reservada da linguagem C que pega o endereço de memória de uma vairiável. 

// void calcula(int* c) // Aqui eu estou apontando para a função, que o seu parâmetro, é o endereço de memória da variável C. Porém, se eu fizer c++ direto, eu vou estar falando para o programa, acrescentar 1 no endereço de memória. É como se você pegasse o valor que o endereço de memória tem. 

 // calcula(&c); // Aqui eu passo o endereço de memória da variável C para a outra variável C. Ela deixa de ser uma variável alocada randomicamente em um endereço de memória e passa a ser um endereço específico armazenado na memória. 

// Quando eu coloco *, não é mais uma variável, e sim um PONTEIRO. O ponteiro, aponta para um endereço de memória que guarda uma varíavel, que por sua vez, guarda um inteiro. 