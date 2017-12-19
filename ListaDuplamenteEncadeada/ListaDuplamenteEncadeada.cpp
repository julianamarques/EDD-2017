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
		No * fim;
		
		public:
			Lista() {
				inicio = NULL;
				fim = NULL;
			}
				
			void inserir(int valor) {
				No *no = new No(valor);

				// ATRIBUI VALOR A LISTA
				no -> valor = valor;
        
   	   	   	   // CRIA A LISTA
   	   	   	   if(inicio == NULL) {
      	  	  	  no -> prox = NULL;
      	  	  	  no -> ant  = NULL;
                
      	  	  	  inicio = no;
      	  	  	  fim = no;
                
      	  	  	  return ;
   	   	   	   }
   	   	   	   
   	   	   	   //INSERE NO FINAL
   	   	   	   fim -> prox = no;
   	   	   	   no -> prox = NULL;
   	   	   	   no -> ant = fim;
   	   	   	   fim = no;
   	   	   	   
   	   	   	   return ;
			}
			
			// RECEBE VALOR E POSIÇÃO COMO PARÂMETRO
			void inserirNoMeio(int valor, int i) {
				No *no = new No(valor);
				No *atual = inicio;
				
				int indice = 0;
				
				// PERCORRE A LISTA E INSERE VALOR EM DETERMINADA POSIÇÃO
				while(atual != NULL) {
					if(indice == i) {
						no -> prox = atual; // PONTEIRO PRÓXIMO DO NÓ RECEBE ATUAL 
						no -> ant = atual -> ant; // PONTEIRO ANTERIOR DO PRÓXIMO NÓ RECEBE PONTEIRO ANTERIOR DO NÓ ATUAL
						atual -> ant -> prox = no; // PONTEIROS ATUAL, ANTERIOR E PRÓXIMO APONTAM PARA O PRÓXIMO NÓ
						atual -> ant = no; // ATUAL PASSA PRA PRÓXIMA POSIÇÃO E SEU PONTEIRO ANTERIOR APONTA PARA O NÓ
						
						return ;
					}
					
					atual = atual -> prox; // ATUAL PASSA PARA O PRÓXIMO NÓ
					indice++;
				}
			}
       
       		 // RECEBE UM VALOR E ADICIONA NO MEIO DA LISTA (COM BASE NA MEDIANA)
       		 void inserirNoMeio(int valor) {
 		 		No *no = new No(valor);
				No *atual = inicio;
				
				int indice = 0;
				int tamanho = 0;
				float mediana = 0.0;
				
				// PERCORRE A LISTA CONTA AS POSIÇÕES
				while(atual != NULL) {
					atual = atual -> prox;
					tamanho++;
				}
				
				atual = inicio; // SETA O ATUAL PARA A POSIÇÃO INICIAL PARA PERCORRER NOVAMENTE
				
				// POR ALGUM MOTIVO A MEDIANA TÁ SENDO ARREDONDADA PARA BAIXO, MAS NÃO TEM PROBLEMA
				mediana = tamanho / 2;
				
				// PERCORRE NOVAMENTE E COMPARA O VALOR DO INDICE COM A MEDIANA
				// SE FOREM IGUAIS O NOVO NÓ É ADICIONADO NA POSIÇÃO	
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
				
				cout << "Mediana: " << mediana << endl;
				cout << "Tamanho: " << tamanho << endl;
				cout << "" << endl;
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
	//l.inserirNoMeio(2,5); //(VALOR, POSIÇÃO)
	//l.inserirNoMeio(99,3);
	l.inserirNoMeio(88);
	l.inserirNoMeio(90);
	
	l.mostrar();
	
	return 0;
}