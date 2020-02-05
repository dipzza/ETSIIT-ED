/**
 * @file : cantidadLetras.cpp
 * @brief: Programa que a partir de un diccionario y un archivo con un conjunto de letras
 * 		   genera un archivo de salida con las Frecuencias absolutas y relativas de
 * 		   aparición de cada letra en el diccionario. Además actualiza las cantidades
 * 		   y las puntuaciones asignadas a las letras en el archivo del conjunto de letras.
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unordered_map>
#include <utility>
#include "diccionario.h"
#include "conjuntoLetras.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Usage: cantidad_letras diccionario letras ficherosalida" << endl;
		exit(EXIT_SUCCESS);
	}
	
	//Cargar el fichero con el diccionario y el de las letras en memoria
	fstream f(argv[1]);
	Diccionario diccionario;
	ConjuntoLetras letras;
	
	if (!f)
	{
		cerr << "Error: No se puede abrir el diccionario" << endl;
		return 0;
	}
	f >> diccionario;
	f.close();
	
	f.open(argv[2]);
	if (!f)
	{
		cerr << "Error: No se puede abrir el fichero de letras" << endl;
		return 0;
	}
	f >> letras;
	f.close();
	
	//Calculo de las apariciones de cada letra del conjunto en el diccionario
	unordered_map<char, int> frecsAbsolutas;
	unordered_map<char, int>::iterator itMap;
	string::iterator itStr;
	double  frecTotal = 0;
	
	for (ConjuntoLetras::iterator it = letras.begin(); it != letras.end(); ++it)
		frecsAbsolutas.insert(make_pair((*it).getCaracter(), 0));
	
	for (Diccionario::iterator itDic = diccionario.begin(); itDic != diccionario.end(); ++itDic)
	{
		itStr = (*itDic).begin();
		for (int i = 0; i < (*itDic).size(); ++i)
		{
			if ((itMap = frecsAbsolutas.find(*itStr)) != frecsAbsolutas.end())
			{
				(*itMap).second++;
				frecTotal++;
			}
			itStr++;
		}
	}
	
	//Volcado a los ficheros de salida de los resultados
	char caracter;
	double frecRelativa;
	fstream fletras(argv[2], fstream::out | fstream::trunc);
	
	if (!fletras)
	{
		cerr << "Error: No se puede abrir el fichero de letras" << endl;
		return 0;
	}
	
	f.open(argv[3], fstream::out | fstream::trunc);
	if (!f)
	{
		cerr << "Error: No se puede abrir el fichero de salida" << endl;
		return 0;
	}
	
	fletras << "#Letra	Cantidad	Puntos" << endl;
	f << "#Letra	FAbs.	Frel." << endl;
	for (ConjuntoLetras::iterator it = letras.begin(); it != letras.end(); ++it)
	{
		caracter = (*it).getCaracter();
		frecRelativa = frecsAbsolutas[caracter] / frecTotal;
		
		f << caracter << "\t" << frecsAbsolutas[caracter] << "\t" << frecRelativa << "\n";
		
		frecRelativa *= 100;
		
		if (frecRelativa < 1)
			fletras << caracter << "\t" << 1 << "\t";
		else
			fletras << caracter << "\t" << (int) frecRelativa << "\t";
		
		if (10/frecRelativa > 10)
			fletras << 10 << endl;
		else if (10/frecRelativa < 1)
			fletras << 1 << endl;
		else
			fletras << (int) (10/frecRelativa) << endl;
	}
	fletras.close();
	f.close();
}
