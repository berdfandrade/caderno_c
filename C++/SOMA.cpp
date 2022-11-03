

#include <iostream>
using namespace std;

int main(){

	int n; // int n
	cin >> n; // equivalente ao scanf, coloca o valor do input na variável n; 

	int soma = 0;
	for(int i = 0; i <= n - 1; i++){ // Porque n - 1? O número anterior a N? 
		int x; 
		cin >> x;
		soma += x;  	
}

	cout << soma << endl; // imprime a soma com uma newline; 
} 
