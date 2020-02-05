/**
 * @file : ConjuntoLetras.h
 * @author Javier Bolívar
 * @brief: Cabecera TDA ConjuntoLetras
 **/

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <set>
#include <iostream>
#include "letra.h"
using namespace std;

/**
  * @brief T.D.A. ConjuntoLetras
  *
  * Una instancia del tipo de datos abstracto @c ConjuntoLetras es un objeto
  * compuesto de una lista de Letras únicas ordenadas de menor a mayor
  * 
  * @date Enero 2018
  */
class ConjuntoLetras{
	private:
		set<Letra> letras;
		
	public:
		/**
		* @brief Escritura del ConjuntoLetras
		* @param is: flujo de salida
		* @param D: ConjuntoLetras
		* @return el flujo de salida
		*/
		friend istream & operator>>(istream & is, ConjuntoLetras & D);
		
		/**
		* @brief Lectura del ConjuntoLetras
		* @param is: flujo de entrada
		* @param D: ConjuntoLetras
		* @return el flujo de entrada
		*/
		friend ostream & operator<<(ostream & is, ConjuntoLetras & D);
		
		/**
		 * @brief clase para iterar sobre el conjunto de letras
		 */
		class iterator{
			private:
				set<Letra>::iterator it;
				
			public:
				iterator & operator++(){ ++it; return *this;}
			   
				iterator & operator--(){ --it; return *this;}
			   
				Letra operator *(){ return *it;}
			   
				bool operator ==(const iterator &i){ return i.it==it;}
		       
				bool operator !=(const iterator &i){ return i.it!=it;}
			   
				friend class ConjuntoLetras;
		};
		
		/**
		 * @brief Inicializa un iterator al comienzo del conjunto de letras
		 */
		iterator begin()
		{
			iterator i;
			i.it = letras.begin();
			return i;
		}
		
		/**
		 * @brief Inicializa un iterator al comienzo del conjunto de letras
		 */
		iterator end()
		{
			iterator i;
			i.it = letras.end();
			return i;
		}
};
#endif
