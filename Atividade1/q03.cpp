#include <iostream>

using namespace std;

int lista1[5];
int lista2[5];

bool verificarIgualdade() {
	bool saoIguais = false;
	
	for(int i = 0; i < 5; i++) {
		if(lista1[i] != lista2[i]) {
			saoIguais = true;
		} 
		
		else {
			saoIguais = false;
			break;
		}
	}
	
	return saoIguais;
}

int main() {
	cout << "LISTA 1: " << endl;
	for(int i = 0; i < 5; i++) {
		cin >> lista1[i];	
	}
	
	cout << "LISTA 2: " << endl;
	for(int j = 0; j < 5; j++) {
		cin >> lista2[j];
	}
	
	if(verificarIgualdade() == 1) {
		cout << "SAO IGUAIS";
	}
	
	else{
		cout << "SAO DIFERENTES";
	}
	
	return 0;
}