/**
 * @file : BolsaLetras.h
 * @author Javier Bolívar
 * @brief: Cabecera TDA bolsaLetras
 **/

#ifndef BOLSA_H
#define BOLSA_H

#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include "conjuntoLetras.h"
using namespace std;

/**
  * @brief T.D.A. BolsaLetras
  *
  * Una instancia del tipo de datos abstracto @c BolsaLetras es un objeto
  * compuesto por generadores aleatorios y un conjunto de letras, de esta
  * bolsa se pueden obtener letras aleatorias
  * 
  * @date Enero 2018
  */
class BolsaLetras{
	private:
		random_device 	rand_dev;
		mt19937 		generator;
		vector<char> 	bolsa;
		
	public:
		/**
		* @brief Constructor por defecto
		*/
		BolsaLetras();
		
		/**
		* @brief Constructor a partir de un ConjuntoLetras
		* @param letras: conjuntoLetras de donde se extraen las letras para la bolsa de letras
		*/
		BolsaLetras(ConjuntoLetras letras);
		
		/**
		* @brief Añade a la bolsa las letras de un ConjuntoLetras
		* @param letras: conjuntoLetras de donde se extraen las letras para la bolsa de letras
		*/
		void meterLetras(ConjuntoLetras letras);
		
		/**
		* @brief Ordena aleatoriamente las letras contenidas en la bolsa
		*/
		void reordenar();
		
		/**
		* @brief Obtiene letras de la bolsa
		* @param n: numero de letras a devolver
		* @return un string compuesto por las \a n primeras letras de la bolsa
		*/
		string sacarLetras(int n);
};
    

#endif
