/**
 * @ file : guiatlf.cpp
 * @brief: Implementación TDA guia de telefonos
 * */

#include "guiatlf.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;

Guia_Tlf Guia_Tlf::siguientes(const string &nombre)
{
	Guia_Tlf aux;
	map<string,string>::iterator it= datos.lower_bound(nombre);
	
	it++;
	while(it != datos.end())
		aux.insert(*it++);
	
	return aux;
}

string Guia_Tlf::getnombre(const string & telefono)
{
	map<string,string>::iterator it;
	
	for(it=datos.begin(); it != datos.end(); it++)
		if(it->second == telefono)
			return it->first;
	
	return "";
}

void Guia_Tlf::borrarEntreNombres(const string &nombrePrimero, const string &nombreUltimo)
{
	map<string,string>::iterator itlow = datos.lower_bound(nombrePrimero);
	map<string,string>::iterator itupper = datos.upper_bound(nombreUltimo);
	datos.erase(itlow,itupper);
}



istream & operator>>(istream &is,pair<string,string> &d){
	getline(is,d.first,'\t');
	getline(is,d.second);
	return is;
}

ostream & operator<<(ostream &os,const pair<const string,string> &d){
	  
	os<<d.first<<'\t'<<d.second<<endl;
	return os;
}

string & Guia_Tlf::operator[](const string &nombre) {
	return datos[nombre];
}

string  Guia_Tlf::gettelefono(const string & nombre){
	map<string,string>::iterator it=datos.find(nombre);
	
	if (it==datos.end()) 
		return string("");
	else 
		return it->second;
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
	pair<string,string> p (nombre,tlf);
	pair< map<string,string> ::iterator,bool> ret;
	
	ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
	
	return ret;     
}
    
pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){
	pair<map<string,string> ::iterator,bool> ret;

	ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
	return ret;    
}

void Guia_Tlf::borrar(const string &nombre){
	map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
	map<string,string>::iterator itupper = datos.lower_bound(nombre);//el primero que ya no tiene dicho nombre
	datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
}

int Guia_Tlf::size()const{
	return datos.size();
}	      

unsigned int Guia_Tlf::contabiliza(const string &nombre){
	return datos.count(nombre);
}

void Guia_Tlf::clear(){
	datos.clear();
}	      

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;
	
	for (it=g.datos.begin();it!=g.datos.end();++it){
	   aux.insert(it->first,it->second);
	}
	
	return aux;
}  

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;

	for (it=g.datos.begin();it!=g.datos.end();++it){
	   aux.borrar(it->first);
	}
	
	return aux;
}

Guia_Tlf Guia_Tlf::previos(const string &nombre,const string &tlf){
	map<string,string>::value_compare vc=datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
	Guia_Tlf aux;
	pair<string,string>p(nombre,tlf);
	map<string,string>::iterator it=datos.begin();
	
	while (vc(*it,p)){
		aux.insert(*it++);
	}
	
	return aux;
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
	map<string,string>::iterator it;
	
	for (it=g.datos.begin(); it!=g.datos.end();++it){
		os<<it->first<<"\t"<<it->second<<endl;
	}
	
	return os;
}
    
istream & operator>>(istream & is, Guia_Tlf & g){
	pair<string,string> p;
	Guia_Tlf aux;
	      
	while (is>>p){
		aux.insert(p);
	}
	g=aux;
	
	return is;
}
