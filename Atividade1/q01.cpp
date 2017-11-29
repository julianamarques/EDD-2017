#include <iostream>

using namespace std;

char L1[30];

void inverter() {
	for(int i = 30; i >= 0; i--) {
		cout << L1[i];
	}
}

int main() {
	cout << "DIGITE UM TEXTO: ";
	cin >> L1;
	
	cout << "TEXTO INVERTIDO: ";
	inverter();
	
	return 0;
}