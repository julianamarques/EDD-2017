#include <iostream>

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

class Lista {
	public:
		No *inicio;
		No *fim;
		
		Lista() {
			inicio = NULL;
			fim = NULL;
		}
		
		bool estaVazia() {
			return (inicio == NULL);
		}
		
		bool estaNaLista(int v) {
			No *atual = inicio;
			
			while(atual != NULL) {
				if(atual -> valor == v) {
					return true;
				}
				
				atual = atual -> prox;
			}
			
			return false;
		}
		
		void inserir(int valor) {
			No *no = new No(valor);
			
			no -> valor = valor;
				
			if(estaVazia()) {
				inicio = no;
				fim = no;
				
				return ;
				
			}
			
			fim -> prox = no;
			fim = no;
			
			return ;
	   }
	   	
		void mostrar(){
			No *atual = inicio;
			
			while(atual != NULL){
				cout << "\nValor: " << atual -> valor << endl;
				atual = atual -> prox;
			}
		}
};

int main() {
	Lista l;
	
	l.inserir(3);
	l.inserir(8);
	l.inserir(7);
	l.inserir(9);
	l.inserir(45);
	l.inserir(50);
	l.inserir(70);
	
	l.mostrar();
	
	if(l.estaNaLista(7)) {
		cout << endl << "Elemento esta na lista" << endl;
	}
	
	else {
		cout << endl << "Elemento nao esta na lista" << endl;
	}
	
	return 0;
}