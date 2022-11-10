

#include <iostream>
using namespace std;

int main (){
	bool leu42 = false;

	while(!leu42){
		int numero;
		cin >> numero;

		if(numero == 42){
            cout << "Você acertou" << endl; 
			leu42 = true;
		}
		else{
			cout << numero << endl;
		}
	}
}
