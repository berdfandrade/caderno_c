

#include <cstdio>
#include <iostream>
#include <time.h>

using namespace std;

int inp(string text){
    cout << text;
    int a = 0; 
    cin >> a;
    cout << endl;
    return a; 
}

int main(){

    srand(time(NULL));

    int n = rand() % 100 + 1; 
    int chute = 0;

    chute = inp("Chute um número de 1 a 100: ");

    while(true) {
        if(chute > n){
            cout << "\nNumero maior do que o numero secreto\n";
            chute = inp("Tente novamente: ");

        }else if (chute < n){
            cout << "\nNúmero menor do que o número secreto\n";
            chute = inp("Tente novamente: ");

        } else {
            cout << "\nVocê acertou o número secreto!\n";
            break;
        }
    }

    return 0; 
} 
