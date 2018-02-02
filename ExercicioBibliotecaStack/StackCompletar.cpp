#include <stack>
#include <iostream>
using namespace std;

template <class T>

class Stack: public stack<T> {
	protected:
		stack<T> pilha;

	public:
		T popStack() {
			T tmp = pilha.top();
			pilha.pop();
		
			return tmp;
		}
	
		void pushStack(T el) {
			pilha.push(el);
		}
		
		void popTodos() {
			while(pilha.empty() == false) {
				pilha.pop();
			}
    	}
    	
    	void imprimirPilha() {
    		cout << "PILHA:" << endl;
    		
			while(pilha.empty() == false) {
				cout << pilha.top() << endl;
				pilha.pop();
			}
		}
	
		void simularFila() {
			stack<T> pilhaAux;
			
			cout << "FILA SIMULADA:" << endl;
			
			while(pilha.empty() == false) {
				pilhaAux.push(pilha.top());
				pilha.pop();
			}
			
			while(pilhaAux.empty() == false) {
				cout << pilhaAux.top() << endl;
				pilhaAux.pop();
			}
		}
};

int main(){
	Stack<int> s;
	
	s.pushStack(3);
	s.pushStack(4);
	s.pushStack(5);
	s.pushStack(6);
	s.pushStack(7);
	s.pushStack(8);
	
	s.simularFila();
	
	return 0;
}
