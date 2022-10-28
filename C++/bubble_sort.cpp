
// Bubble sort em c++


#include <iostream>
using namespace std;
int main ()

{
   int i, j, temp, pass= 0; // Declarando múltiplas variáveis como 0 >>
   int a[10] = {10, 2 ,0,14 ,43 ,88 ,18 ,1 ,5 ,2500};

   cout <<"Lista de números:\n";

   for(i = 0; i<10; i++) {
      cout <<a[i]<<"\t"; // Passa pela lista, e imprime cada número que vai ser percorrido no array...
   }

cout<<endl; // fim da linha

for(i = 0; i<10; i++) { // Vai percorrer o array de 10 números
   for(j = i+1; j<10; j++) // Vai percorrer o array da lista, e um número que está na frente dele. até terminarmos o array de 10 números
   {
      if(a[j] < a[i]) { // Se o número J, que é o número da frente do array, 
         temp = a[i]; // for menor que o número de trás, Colocamos o a[i], em uma variável temporária... 
         a[i] = a[j]; // o próximo número vira o anterior, portanto, ele vai para trás na lista, fazendo com que fique em ordem crescente.
         a[j] = temp; // temp vira o maior número... 
      }
   }

pass++; // Pass vai aumentando de acordo com a quantidade de tentativas para fazer o sort

}

cout <<"Lista de elementos ordenada...\n"; // imprime a lista que foi feita pelo bubble sort. 
for(i = 0; i<10; i++) {
   cout <<a[i]<<"\t";

}

cout<<"\nNúmero de loops que foi feito na lista:"<<pass<<endl; // pegamos o pass que foi a quantidade de vezes que o loop teve que repetir para conseguir fazer o sort. 
return 0;
}