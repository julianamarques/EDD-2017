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

class Pilha {
	public:
		No *topo;
	
		Pilha() {
			topo = NULL;
		}
	
		bool estaVazia() {
			if(topo == NULL) {
				return true;
			}
		
			return false;
		}
	
		void push(int valor) {
			No *no = new No(valor);
		
			if(estaVazia()) {
				topo = no;
			}
		
			else {
				no -> prox = topo;
				topo = no;
			}
		}
	
		int pop(){
			No *temp;
			int popped;
		
			if(!estaVazia()){
				temp = topo;
				popped = temp -> valor;
				topo = topo -> prox;
				free(temp);
			}
		
			return popped;
		}
		
		// FUNCIONA, MAS NÃO É ACONSELHÁVEL PARA PILHAS	
		void exibir() {
			No *atual = topo;
		
			while(atual != NULL) {
				cout << "End: " << &atual << " | Valor: " << atual -> valor << " | Prox: " << atual -> prox << endl;
				atual = atual -> prox;
			}
		}
};

int main() {
	Pilha p;
	
	p.push(5);
	p.push(3);
	p.push(7);
	
	p.exibir();
	p.pop();
	
	cout << endl;
	
	p.exibir();
	
	return 0;
}

