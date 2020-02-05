/**
 * @file : letras.cpp
 * @brief: Programa que construye las palabras de longitud (o puntuación) mayor de 
 * 		   un diccionario a partir de una serie de letras seleccionadas de forma aleatoria.
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <utility>
#include <unordered_map>
#include "diccionario.h"
#include "conjuntoLetras.h"
#include "bolsaLetras.h"

using namespace std;

/**
 * @brief Comprueba si una palabra se puede formar con una serie de letras
 * @param palabra: palabra a comprobar si se puede formar con \a letrasValidas
 * @param letrasValidas: conjunto de letras que se pueden usar para formar una palabra valida
 * @return bool que es true si \a  palabra se puede formar usando solo las letras en \a letrasValidas
 */
bool esPalabraValida(string palabra, string letrasValidas)
{
	bool valida = true;
	int pos;
	
	for (int i=0; i < palabra.size() && valida; ++i)
	{
		pos = letrasValidas.find_first_of(palabra[i]);
		
		if (pos == -1)
			valida = false;
		else
			letrasValidas.erase(pos, 1);
	}
	
	return valida;
}

/**
 * @brief Calcula la puntuacion asociada a una palabra
 * @param palabra: palabra de la que calcular la puntuacion
 * @param puntuaciones: puntuaciones asociadas a cada letra
 * @return puntuacion asociada a \a palabra
 */
int calcularPuntuacion(string palabra, const unordered_map<char, int> &puntuaciones)
{
	int puntuacion = 0;
	
	for (int i=0; i < palabra.size(); i++)
		puntuacion += puntuaciones.at(palabra[i]);
	
	return puntuacion;
}

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		cout << "Usage: letras < diccionario > < letras.txt > < cantidadletras > < -LP >" << endl;
		exit(EXIT_SUCCESS);
	}
	
	
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
	
	
	unordered_map<char, int> puntuaciones;
	BolsaLetras bolsa(letras);
	string letrasRandom;
	string letrasRestantes;
	string solucionUsuario;
	set<string> soluciones;
	int puntuacion, puntuacionMax;
	char opcion;
	
	for (ConjuntoLetras::iterator it = letras.begin(); it != letras.end(); ++it)
		puntuaciones.insert(make_pair((*it).getCaracter(), (*it).getPuntuacion()));
	
	do
	{
		puntuacionMax = 1;
		soluciones.clear();
		bolsa.reordenar();
		letrasRandom = bolsa.sacarLetras((int) strtol(argv[3], NULL, 10));
		
		cout << "Las letras son: ";
		for (int i=0; i < letrasRandom.size(); i++)
			cout << letrasRandom[i] << "\t";
		cout << endl;
		
		cout << "Dime tu solucion: ";
		
		cin >> solucionUsuario;
		while (!esPalabraValida(solucionUsuario, letrasRandom))
		{
			cout << "Solucion incorrecta, prueba otra vez: ";
			cin >> solucionUsuario;
		}
		cout << solucionUsuario << "\tPuntuacion: ";
		
		
		if (strcmp(argv[4], "-L") == 0)
		{
			cout << solucionUsuario.size() << "\n\n";
			
			for (Diccionario::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
			{
				if (esPalabraValida(*it, letrasRandom))
				{
					puntuacion = (*it).size();
					if (puntuacion > puntuacionMax)
					{
						puntuacionMax = puntuacion;
						soluciones.clear();
						soluciones.insert(*it);
					}
					else if (puntuacion == puntuacionMax)
						soluciones.insert(*it);
				}
			}
		}
		else if (strcmp(argv[4], "-P") == 0)
		{
			cout << calcularPuntuacion(solucionUsuario, puntuaciones) << "\n\n";
			
			for (Diccionario::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
			{
				if (esPalabraValida(*it, letrasRandom))
				{
					puntuacion = calcularPuntuacion(*it, puntuaciones);
					
					if (puntuacion > puntuacionMax)
					{
						puntuacionMax = puntuacion;
						soluciones.clear();
						soluciones.insert(*it);
					}
					else if (puntuacion == puntuacionMax)
						soluciones.insert(*it);
				}
			}
		}
		cout << "Mis soluciones son:\n";
		for (set<string>::iterator it = soluciones.begin(); it != soluciones.end(); ++it)
			cout << *it << "\tPuntuacion: " << puntuacionMax << "\n";
		cout << "¿Quieres seguir jugando[s/n]?";
		cin >> opcion;
	} while (opcion == 's');
	
	return 0;
}
