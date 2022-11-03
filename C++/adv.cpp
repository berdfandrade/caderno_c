
#include <iostream>
using namespace std; // teste

int main () {

    const int NUMERO_SECRETRO = 45;
    bool nao_acertou = true;
    int tentativas = 0; 


    while (nao_acertou){ 

    int chute;
    cout << "Qual é o valor do seu chute? ";
    cin >> chute;
    cout << "O valor do chute é " << chute << endl; 

    
    bool acertou = chute == NUMERO_SECRETRO; 
    bool maior = chute > NUMERO_SECRETRO;

            
    if(acertou){
        cout << "Parabéns feller" << endl;
        cout << "Acabou!" << endl;
        tentativas++;
        nao_acertou = false;
        // Mensagem de fim de jogo. 
        cout << "Você acertou em " << tentativas << "tentativas" << endl; 
    } else if (maior){
        cout << "Seu chute foi maior que o número secreto" << endl;
        tentativas++;
        cout << "Suas tentativas foram: " << tentativas << endl; 

    } else {
        cout << "Seu chute foi menor que o número secreto" << endl;
        tentativas++;
        cout << "Suas tentativas foram: " << tentativas << endl; 
    }
    
} 

}
