/**
 * @file : conjuntoLetras.cpp
 * @brief: Implementación TDA conjuntoLetras
 */

#include "conjuntoLetras.h"
using namespace std;

istream & operator>>(istream & is, ConjuntoLetras & conjunto)
{
	string sobrante;
	Letra leida;
	
	getline(is, sobrante);
	
	while (is >> leida)
		conjunto.letras.insert(leida);
	
	return is;
}

ostream & operator<<(ostream & os, ConjuntoLetras & conjunto)
{
	os << "#Letra\tCantidad\tPuntos" << endl;
	for (ConjuntoLetras::iterator it = conjunto.begin(); it != conjunto.end(); ++it)
	{
		os << *it;
	}
	
	return os;
}
