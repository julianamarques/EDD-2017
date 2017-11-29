#include <iostream>

using namespace std;

int vetor[30];
int ultimo = 0;

// REMOVE O ULTIMO ELEMENTO DO VETOR
void pop() {
    ultimo--;
}

// REMOVE POR POSIÇÃO
void remove(int p){
	for(int i = p; i < ultimo-1; i++) {
		vetor[i] = vetor[i+1];
    }

	ultimo--;
}

// RETORNA A POSIÇÃO DE UM VALOR
int index(int valor) {
    for(int i = 0; i < ultimo; i++) {
        if(vetor[i] == valor) {
            return i;
        }
    }

    return -1;
}

void percorre() {
    for(int i = 0; i < ultimo; i++) {
        cout << i << "-> " << vetor[i] << endl;
    }
}

void insert(int p, int valor) {
    for(int i = ultimo; i > p; i--) {
        vetor[i] = vetor[i-1];
    }

     vetor[p] = valor;
     ultimo++;   
}

// CONTA A OCORRÊNCIA DE UM VALOR NO VETOR
int count(int valor) {
    int contador = 0;

    for(int i = 0; i < ultimo; i++) {
        if(vetor[i] == valor) {
            contador++;
        }
    }

    return contador;
}

void append(int valor) {
    vetor[ultimo] = valor;
    ultimo++;
}

int len() {
    return ultimo+1;
}

int main() {
    append(3);
    append(5);
    append(2);
    append(43);
    insert(4,23);
    percorre();
}