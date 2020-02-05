/**
 * @file : testdiccionario.cpp
 * @brief: Programa para probar las distintas funciones del TDA Diccionario
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "diccionario.h"

int main(int argc,char * argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: testdiccionario <diccionario>" << endl;
		return 0;
	}
	
	fstream f(argv[1]);
	
	if (!f)
	{
		cerr << "Error: No se puede abrir el fichero" << endl;
		return 0;
	}
	
	Diccionario D;
	
	cout << "Cargando diccionario ..." << endl;
	f >> D;
	cout << "Leido diccionario" << endl;
	
	cout << D << endl;
	cout << "En este diccionario hay" << D.size() << "palabras" << endl;
	
	
	string palabra;
	cout << "Dime una palabra: ";
	cin >> palabra;
	
	if (D.esta(palabra))
		cout << "La palabra existe" << endl;
	else
		cout << "La palabra no existe" << endl;
	
	
	int longitud;
	
	cout << "Introduce una longitud: ";
	cin >> longitud;
	
	vector<string> palabras = D.palabrasLongitud(longitud);
	
	for(int i=0; i < palabras.size(); ++i)
		cout << palabras[i] << endl;
	
	return 0;
}
