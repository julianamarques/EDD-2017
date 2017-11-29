#include <iostream>

using namespace std;

template <class TipoGenerico>
class Lista {
    public:
        int tamanho;
        int ultimo;
        TipoGenerico vetor[5];

        Lista(int t) {
            ultimo = 0;
            tamanho = t;
        }
        
        // *SOBRECARGA DE MÉTODOS
        // REMOVE O ULTIMO ELEMENTO DO VETOR
        void pop() {
            ultimo--;
        }

        // REMOVE POR POSIÇÃO
        void pop(int p){
	        for(int i = p; i < ultimo-1; i++) {
		        vetor[i] = vetor[i+1];
            }

	        ultimo--;
        }

        // REMOVE POR POSIÇÃO
        void remove(int valor){
	        for(int i = 0; i < ultimo; i++) {
		        if(vetor[i] == valor) {
                    vetor[i] = NULL;
                }
            }
        }

        // RETORNA A POSIÇÃO DE UM VALOR
        int index(TipoGenerico valor) {
            for(int i = 0; i < ultimo; i++) {
                if(vetor[i] == valor) {
                    return i;
            }
        }

            return -1;
        }

        void percorre() {
            for(int i = 0; i < ultimo; i++) {
                cout << i << "-> " << vetor[i] << "\n";
            }
        }

        void insert(int p, TipoGenerico valor) {
            for(int i = ultimo; i > p; i--) {
                vetor[i] = vetor[i-1];
            }

            vetor[p] = valor;
            ultimo++;   
        }

        // CONTA A OCORRÊNCIA DE UM VALOR NO VETOR
        int count(TipoGenerico valor) {
            int contador = 0;

            for(int i = 0; i < ultimo; i++) {
                if(vetor[i] == valor) {
                    contador++;
                }
            }

            return contador;
        }

        void append(TipoGenerico valor) {
            vetor[ultimo] = valor;
            ultimo++;
        }

        int len() {
            return ultimo+1;
        }
};

int main() {

    Lista<int> objeto(5);
    
    for(int i = 0; i < 5; i++) {
        objeto.append(i);
    }

    objeto.percorre();

    return 0;
}