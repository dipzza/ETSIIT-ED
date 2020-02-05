#include "pila_con_listas.h"
#include <list>
#include <cassert>

using namespace std;

PilaConListas::PilaConListas(const PilaConListas& copia)
	:pila(copia.pila) {}

bool PilaConListas::empty() const{
	return pila.empty();
}

int PilaConListas::size() const{
	return pila.size();
}

int& PilaConListas::top(){
	assert(!pila.empty());
	return pila.back();	//Devuelve el número final de la lista
}

const int& PilaConListas::top () const{
	assert(!pila.empty());
	return pila.back();
}

void PilaConListas::push(const int& num){
	pila.push_back(num); //Inserta un número al final de la lista
}

void PilaConListas::pop(){
	assert(!pila.empty());
	pila.pop_back(); //Elimina el número del final de la lista
}
