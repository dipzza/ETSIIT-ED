// Autor: Francisco Javier Bolívar Expósito 2ºD

#ifndef PILACLISTAS
#define PILACLISTAS

#include <list>

using namespace std;

class PilaConListas{
	private:
		list<int> pila; //Montamos la pila en base al tipo "list" de la stl
	public:
		PilaConListas(){}
	
		PilaConListas(const PilaConListas& copia);
    
		~PilaConListas(){}

		bool empty() const; //Devuelve true si la pila está vacía, en caso contrario false
		
		int size() const; //Devuelve el tamaño

		int& top();		//Devuelve una referencia al número tope

		const int& top () const; //Devuelve una referencia constante al número tope

		void push(const int& num); //Inserta un número
		
		void pop(); //Elimina el número del tope
};
#endif
