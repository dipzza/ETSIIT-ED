/**
 * @file : diccionario.cpp
 * @brief: Implementación TDA Diccionario
 */

#include <algorithm>	//Funciones utiles, por ejemplo para buscar una palabra de una determinada longitud
#include <iostream>
#include "diccionario.h"

int Diccionario::size() const { return datos.size(); }

bool Diccionario::esta (string palabra) { return datos.find(palabra) != datos.end(); }

vector<string> Diccionario::palabrasLongitud (int longitud)
{
	set<string>::iterator it;
	vector<string> palabras;

	for(it=datos.begin(); it != datos.end(); ++it)
		if ((*it).size() == longitud)
			palabras.push_back(*it);
	
	return palabras;
}

istream & operator>>(istream & is, Diccionario & D)
{
	string palabra;
	
	while(getline(is, palabra))
		D.datos.insert(palabra);
	
	return is;
}

ostream & operator <<(ostream & os, const Diccionario & D)
{
	set<string>::iterator it;
	
	for(it=D.datos.begin(); it != D.datos.end(); ++it)
		os << *it << endl;
	
	return os;
}
