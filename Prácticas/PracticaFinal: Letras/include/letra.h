/**
 * @file : letra.h
 * @author Javier Bolívar
 * @brief: Cabecera TDA Letra
 **/

#ifndef LETRA_H
#define LETRA_H

using namespace std;

/**
  * @brief T.D.A. Letra
  *
  * Una instancia del tipo de datos abstracto @c Letra es un objeto
  * formado por un char y dos int
  * 
  * @date Enero 2018
  */
class Letra{
	private:
		char caracter;
		int cantidad;
		int puntuacion;
		
	public:
		Letra(){}
		/**
		 * @brief Constructor con todos los parámetros para inicializar la letra
		 * @param caracter2: letra asociada al objeto
		 * @param cantidad2: repeticiones de esta Letra
		 * @param puntuacion2: puntuacion de esta Letra
		 */
		Letra(char caracter2, int cantidad2, int puntuacion2);
		
		/**
		 * @brief Acceso a un atributo
		 * @return el atributo caracter
		 */
		char getCaracter();
		
		/**
		* @brief Acceso a un atributo
		* @return el atributo cantidad
		*/
		int getCantidad();
		
		/**
		* @brief Acceso a un atributo
		* @return el atributo puntuacion
		*/
		int getPuntuacion();
		
		/**
		* @brief Operador para comparar si una letra es menor que otra
		* @return bool que es true si la letra *this es menor que comp
		*/
		bool operator<(const Letra &comp) const;
		
		/**
		* @brief Escritura de la Letra
		* @param is: flujo de salida
		* @param D: Letra.
		* @return el flujo de salida
		*/
		friend istream & operator>>(istream & is, Letra & D);
		
		/**
		* @brief Lectura de la Letra
		* @param is: flujo de entrada
		* @param D: Letra.
		* @return el flujo de entrada
		*/
		friend ostream & operator<<(ostream & os, const Letra & D);
};
#endif
