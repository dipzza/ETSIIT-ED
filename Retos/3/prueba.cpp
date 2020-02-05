#include <iostream>
#include "pila_con_listas.h"
using namespace std;

int main(){
	
	PilaConListas pila;
	
	if (pila.empty())
		cout << "La pila esta vacia" << endl;
	
	pila.push(5);
	
	cout << pila.top() << " " << pila.size() << endl;
	
	pila.pop();
	
	cout << pila.size() << endl;
}
