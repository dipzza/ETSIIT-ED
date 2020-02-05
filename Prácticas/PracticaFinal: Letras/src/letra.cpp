/**
 * @file : letra.cpp
 * @brief: Implementación TDA Letra
 */

#include <iostream>
#include "letra.h"

Letra::Letra(char caracter2, int cantidad2, int puntuacion2)
	:caracter(caracter2), cantidad(cantidad2), puntuacion(puntuacion2) {}
	
char Letra::getCaracter() { return caracter;}

int Letra::getCantidad() { return cantidad;}

int Letra::getPuntuacion() {return puntuacion;}

bool Letra::operator<(const Letra &comp) const
{
	return (this->caracter < comp.caracter);
}

istream & operator>>(istream & is, Letra & D)
{
	is >> D.caracter;
	is >> D.cantidad;
	is >> D.puntuacion;
	
	return is;
}

ostream & operator<<(ostream & os, const Letra & D)
{
	os << D.caracter << "\t";
	os << D.cantidad << "\t";
	os << D.puntuacion << endl;
	
	return os;
}
