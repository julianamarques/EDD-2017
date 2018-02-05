#include <iostream>
#include <stdlib.h>

using namespace std;

class No {
	public:
		int valor;
		No *prox;
	
		No(int v) {
			valor = v;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;
		
		Fila(){
			inicio = NULL;
			fim = NULL;
		}
		
		void push(int n){
			No *no = new No(n);
			
			if(inicio == NULL){
				inicio = no;
				fim = no;
			}
			
			else{
				fim -> prox = no;
				fim = no;
			}
		}
		
		bool estaVazia() {
			if(inicio == NULL) {
				return true;
			}
		
			return false;
		}
		
		int pop(){
			No *temp;
			int valor;
			
			if(!estaVazia()){
				temp = inicio;
				valor = inicio -> valor;
				inicio = inicio -> prox;
				free(temp);
			}
			
			return valor;
		}
	
		void exibir() {
			No *atual = inicio;
			
			while(atual != NULL) {
				cout << "End: " << &atual << " | Valor: " << atual -> valor << " | Prox: " << atual -> prox << endl;
				atual = atual -> prox;
			}
		}
};

int main() {
	Fila f;
	
	f.push(3);
	f.push(2);
	f.push(4);
	f.push(1);
	
	f.exibir();
	f.pop();
	
	cout << endl;
	
	f.exibir();
}