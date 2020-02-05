/**
 * @file : letra.cpp
 * @brief: Implementación del TDA BolsaLetras
 */

#include "bolsaLetras.h"

using namespace std;

BolsaLetras::BolsaLetras()
{
	generator.seed(rand_dev());
}

BolsaLetras::BolsaLetras(ConjuntoLetras letras)
{
	generator.seed(rand_dev());
	meterLetras(letras);
}

void BolsaLetras::meterLetras(ConjuntoLetras letras)
{
	char caracter;
	for (ConjuntoLetras::iterator it = letras.begin(); it != letras.end(); ++it)
	{
		caracter = (*it).getCaracter();
		
		for (int i = 0; i < (*it).getCantidad(); ++i)
			bolsa.push_back(caracter);
	}
}

void BolsaLetras::reordenar()
{
	shuffle(bolsa.begin(), bolsa.end(), generator);
}

string BolsaLetras::sacarLetras(int n)
{
	string sacadas;
	
	for (int i=0; i < n && i < bolsa.size(); ++i)
		sacadas.push_back(bolsa[i]);
	
	return sacadas;
}
