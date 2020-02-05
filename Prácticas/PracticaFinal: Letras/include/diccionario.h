/**
 * @file : diccionario.h
 * @author Javier Bolívar
 * @brief: Cabecera TDA Diccionario
 **/

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include<string>
#include<set>
#include<vector>

using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia del tipo de datos abstracto @c Letra es un objeto
  * compuesto de una lista de palabras únicas ordenadas por orden lexicográfico
  * 
  * @date Enero 2018
  */
class Diccionario{
	private:
		set<string> datos;
	public:
		/**
		* @brief Calcula la cantidad de palabras del diccionario
		* @return tamaño del diccionario
		*/
		int size() const;
		
		/**
		* @brief Obtiene las palabras de un determinado tamaño
		* @param longitud: longitud de las palabras a devolver
		* @return vector con todas las palabras con tamaño \a longitud en el diccionario
		*/
		vector<string> palabrasLongitud (int longitud);
		
		/**
		* @brief Comprueba si una palabra está en el diccionario
		* @param palabra: string a buscar en el diccionario
		* @return bool que es true si la palabra está
		*/
		bool esta(string palabra);
		
		/**
		* @brief Escritura del Diccionario
		* @param is: flujo de salida
		* @param D: Diccionario
		* @return el flujo de salida
		*/
		friend istream & operator>>(istream & is, Diccionario & D);
		
		/**
		* @brief Lectura del Diccionario
		* @param is: flujo de entrada
		* @param D: Diccionario
		* @return el flujo de entrada
		*/
		friend ostream & operator<<(ostream & os, const Diccionario & D);
		
		/**
		 * @brief clase para iterar sobre el Diccionario
		 */
		class iterator{
			private:
				set<string>::iterator it;
				
			public:
				iterator & operator++(){ ++it; return *this;}
			   
				iterator & operator--(){ --it; return *this;}
			   
				string operator *(){ return *it;}
			   
				bool operator ==(const iterator &i){ return i.it==it;}
		       
				bool operator !=(const iterator &i){ return i.it!=it;}
			
				friend class Diccionario;
		};
		
		/**
		 * @brief Inicializa un iterator al comienzo del diccionario
		 */
		iterator begin()
		{
			iterator i;
			i.it = datos.begin();
			return i;
		}
		
		/**
		 * @brief Inicializa un iterator al final del diccionario
		 */
		iterator end()
		{
			iterator i;
			i.it = datos.end();
			return i;
		}
};
#endif
