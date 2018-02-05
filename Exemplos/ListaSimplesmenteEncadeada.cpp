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
		
		void inserir(int valor) {
			No *no = new No(valor);
			
			no -> valor = valor;
				
			if(inicio == NULL) {
				no -> prox = NULL;
				inicio = no;
				fim = no;
				
				return ;
				
			}
			
			fim -> prox = no;
			no -> prox = NULL;
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
	
	return 0;
}