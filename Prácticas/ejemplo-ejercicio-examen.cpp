#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

set<int> unionDisjunta(set<int> a, set<int> b, set<int> c)
{
	set<int> resultado;
	set<int>::const_iterator it;
	bool repetido;
	
	for (it=a.begin(); it != a.end(); it++)
	{
		repetido=false;
		
		if (b.count(*it) > 0)
			repetido = true;
		if (c.count(*it) > 0)
			repetido = true;
		
		if(!repetido)
			resultado.insert(*it);
	}
	
	for (it=b.begin(); it != b.end(); it++)
	{
		repetido=false;
		
		if (a.count(*it) > 0)
			repetido = true;
		if (c.count(*it) > 0)
			repetido = true;
		
		if(!repetido)
			resultado.insert(*it);
	}
	
	for (it=c.begin(); it != c.end(); it++)
	{
		repetido=false;
		
		if (a.count(*it) > 0)
			repetido = true;
		if (b.count(*it) > 0)
			repetido = true;
		
		if(!repetido)
			resultado.insert(*it);
	}
	
	return resultado;
}

set<int> interseccionDisjunta(set<int> a, set<int> b, set<int> c)
{
	set<int> resultado;
	set<int>::const_iterator it;
	bool insertar;
	
	for (it=a.begin(); it != a.end(); it++)
	{
		insertar=false;
		
		if (b.count(*it) > 0)
			insertar = true;
		if (c.count(*it) > 0)
			insertar = false;
		
		if(insertar)
			resultado.insert(*it);
	}
	
	for (it=b.begin(); it != b.end(); it++)
	{
		insertar=false;
		
		if (c.count(*it) > 0)
			insertar = true;
		if (a.count(*it) > 0)
			insertar = false;
		
		if(insertar)
			resultado.insert(*it);
	}
	
	for (it=c.begin(); it != c.end(); it++)
	{
		insertar=false;
		
		if (a.count(*it) > 0)
			insertar = true;
		if (b.count(*it) > 0)
			insertar = false;
		
		if(insertar)
			resultado.insert(*it);
	}
	
	return resultado;
}

int main(){
  
  set<int> a, b, c, union_dis, inter_dis;
  
  InicializarSemilla();
  
  for (int i=0;i<5;i++)	//inserta enteros generado aleatoriamente en el rango 1-100 en cada conjunto
  {
	a.insert(generaEntero(1,10));
	b.insert(generaEntero(1,10));
    c.insert(generaEntero(1,10)); 
  }
  cout<<endl<<a;
  cout<<endl<<b;
  cout<<endl<<c<<endl;
  
  union_dis = unionDisjunta(a, b, c);
  inter_dis = interseccionDisjunta(a, b, c);
  
  cout<<endl<<"Union disjunta: " << union_dis;
  cout<<endl<<"Interseccion disjunta: " << inter_dis<<endl;
  
  
}
