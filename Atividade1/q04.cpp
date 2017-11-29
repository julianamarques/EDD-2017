#include <iostream>

using namespace std;

int lista1[5];
int lista2[5];

using namespace std;

void ordenarLista() {
	int listaUniao[10];
	int aux;
	
	for(int i = 0; i < 5; i++) {
		listaUniao[i] = lista1[i];
	}
	
	for(int j = 5; j < 10; j++) {
		listaUniao[j] = lista2[j-5];
	}
	
	for(int k = 0; k < 10; k++) {
		for(int l = 0; l < 10; l++) {
			if(listaUniao[l] < listaUniao[k]) {
				aux = listaUniao[l];
				listaUniao[l] = listaUniao[k];
				listaUniao[k] = aux; 
			}
		}
	}
	
	for(int m = 0; m < 10; m++) {
		cout << listaUniao[m] << endl;
	}
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
	
	ordenarLista();
	
	return 0;
}