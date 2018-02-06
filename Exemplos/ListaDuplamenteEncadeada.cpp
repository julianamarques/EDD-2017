// ATIVIDADE EM GRUPO: QUESTÃO 16 DO LIVRO DE EDD
// GRUPO: JULIANA, PAULO ROBERTO, BRUNO DARSHAN, MARCOS, DIEGO, LEONARDO TORRES

#include <iostream>

using namespace std;

class No {
	public:
		int valor;
		
		No *prox;
		No *ant;
		
		No(int v) {
			valor = v;
			prox = NULL;
			ant = NULL;
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
			no -> ant = fim;
			fim = no;
			
			return ;
	   }
	   
	   // INSERIR NO MEIO, COM BASE EM UMA POSIÇÃO PASSADA COMO PARAMETRO
	   void inserirNoMeio(int valor, int i) {
	   	    No *no = new No(valor);
			No *atual = inicio;
			
			int indice = 0;
			
			while(atual != NULL) {
				if(indice == i) {
					no -> prox = atual;
					no -> ant = atual -> ant;
					atual -> ant -> prox = no;
					atual -> ant = no;
					
					return ;
				}
				
				atual = atual -> prox;
				indice++;
			}
	    }
		
		// INSERIR NO MEIO COM BASE NA MEDIANA
		void inserirNoMeio(int valor) {
			No *no = new No(valor);
			No *atual = inicio;
			
			int indice = 0;
			int tamanho = 0;
			float mediana = 0.0;
			
			while(atual != NULL) {
				atual = atual -> prox;
				tamanho++;
			}
			
			atual = inicio;
			
			mediana = tamanho / 2;

			while(atual != NULL) {
				if(indice == mediana) {
					no -> prox = atual; 
					no -> ant = atual -> ant;
					atual -> ant -> prox = no;
					atual -> ant = no;
					
					break;
				}
				
				atual = atual -> prox;
				indice++;
			}
		}
		
		void mostrar(){
			No *atual = inicio;
			
			while(atual != NULL){
				cout << endl << "Valor: " << atual -> valor << endl;
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
	//l.inserirNoMeio(2,5); //(VALOR, POSIÇÃO)
	//l.inserirNoMeio(99,3);
	l.inserirNoMeio(88);
	l.inserirNoMeio(90);
	
	l.mostrar();
	
	if(l.estaNaLista(2)) {
		cout << endl << "Elemento esta na lista" << endl;
	}
	
	else {
		cout << endl << "Elemento nao esta na lista" << endl;
	}
	
	return 0;
}
