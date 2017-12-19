#include <stdio.h>
#include <iostream>
#include <string.h>

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
		No * fim;
		
		public:
			Lista() {
				inicio = NULL;
				fim = NULL;
			}
			
			Lista(int valor) {
				inicio = new No(valor);
				inicio = fim;
			}	
			
			void inserir(int valor) {
				No *no = new No(valor);
				
				No *novo = no;
				// ATRIBUI VALOR A LISTA
				novo -> valor = valor;
        
   	   	   	   // CRIA A LISTA
   	   	   	   if(inicio == NULL) {
      	  	  	  novo -> prox = NULL;
      	  	  	  novo -> ant  = NULL;
                
      	  	  	  inicio = novo;
      	  	  	  fim = novo;
                
      	  	  	  return ;
   	   	   	   }
   	   	   	   
   	   	   	   //INSERE NO FINAL
   	   	   	   fim -> prox = novo;
   	   	   	   novo -> prox = NULL;
   	   	   	   novo -> ant = fim;
   	   	   	   fim = novo;
   
   	   	   	   return ;
			}
					
			No *inserirMeio(int valor, int i) {
				//No *no = new No(valor);
				No *atual = inicio;
				No *ant = inicio;
				
				int indice = 0;
				// PERCORRE A LISTA E SE O VALOR DA POSIÇÃO FOR MAIOR QUE O VALOR INSERIDO
				// O VALOR É INSERIDO APÓS ELE
				// MAS ELE SOBRESCREVE A POSIÇÃO DO VALOR APÓS ELE 
				while(atual != NULL) {
					//if(atual ->valor > valor) {
					//	atual ->valor = valor;
						
					//	return atual;
					//}
					
					if(indice == i) {
						atual ->valor = valor;
						
						return atual;
					}
					
					atual = atual->prox;
					indice++;
				}
				
				return NULL;
				
			}
			
			void mostrar(){
				No *atual = inicio;
				
				while (atual!=NULL){
					cout<<"\nValor: "<<atual->valor<<endl;
					atual=atual->prox;
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
	l.inserirMeio(2,2); //(VALOR, POSIÇÃO)
	//l.inserirMeio(5);
	//l.inserirMeio(4);
	//l.inserirMeio(10);
	//l.inserirMeio(55);
	l.mostrar();
	return 0;
}