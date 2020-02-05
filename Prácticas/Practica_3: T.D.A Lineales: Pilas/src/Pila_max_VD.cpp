/**
  * @file Pila_max_VD.cpp
  * @brief Fichero código del TDA Pila max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  *
  */
#include "Pila_max_VD.h"
#include "VDG.cpp"
#include <cassert>

ostream& operator<< (ostream & os,const elemento & a){
    os << a.ele << " Maximo: "<< a.maximo <<endl;
    return os;
}

Pila_max::Pila_max(const Pila_max & otra)
    :datos(otra.datos), num_datos(otra.num_datos){}


Pila_max& Pila_max::operator= (const Pila_max& otra){
	datos = otra.num_datos;
    num_datos = otra.num_datos;
	return *this;
}

bool Pila_max::vacia() const{
    return (num_datos==0);
}

elemento & Pila_max::tope (){
    assert(num_datos>0);       //Si la pila está vacía, abortar
    return datos[num_datos - 1]; //Devuelve el elemento del tope de la pila
}

const elemento & Pila_max::tope () const{
    assert(num_datos>0);       //Si la pila está vacía, abortar
    return datos.componente(num_datos - 1); //Devuelve el elemento del tope de la pila
}

void Pila_max::poner(const int & elem){
    elemento a;
    
    if (num_datos==0 ){
        a={elem,elem};
    }
    else{
        if (tope().maximo > elem){
            a={elem,datos.componente(num_datos - 1).maximo};
        }
        else {
            a={elem,elem};
        }
    }
    
    if (num_datos == datos.dimension())
        datos.redimensionar(datos.dimension() + 10);
    
    datos[num_datos] = a;
    num_datos++;
}   

void Pila_max::quitar(){
    assert(num_datos > 0);       //Si la pila está vacía, abortar
	num_datos--;
}	

int Pila_max::num_elementos() const{
    return num_datos;
}
