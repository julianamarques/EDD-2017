#include <iostream>

using namespace std;

void bubbleSort(int *vetor, int tamanho) {
	int aux;
	
	for(int i = 0; i < tamanho; i++) {
		for(int j = i; j < tamanho; j++) {
			if(vetor[i] > vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

int main() {
	int vetor[5];
	
	for(int i = 0; i < 5; i++) {
		cout << "VALOR: ";
		cin >> vetor[i];
	}
	
	bubbleSort(vetor, 5);
	
	cout << endl << "VETOR ORDENADO:" << endl;
	
	for(int i = 0; i < 5; i++) {
		cout << vetor[i] << endl;
	}
	
	return 0;
}