#include <iostream>
#include "Fecha_Historica.h"
#include <assert.h>

using namespace std;

//Resize simple
  void Fecha_Historica::resize(int r){
     string *aux = new string[r];   
     for(int i=0; i<numeventos; ++i){
        aux[i]=str[i]; 
     }
     delete[] str;
     str = aux;
     reservados = r;
  }

//Constructor vacío
  Fecha_Historica::Fecha_Historica():anio(0),reservados(0),numeventos(0),str(0){}


//Constructor con parametros año, cadena de eventos y número de eventos a añadir
  Fecha_Historica::Fecha_Historica(int a, string *s, int n):reservados(n),numeventos(n){
     assert(a >= 0 && a<= 9999);
     anio = a;
     string *str = new string[n];   
     for (int i=0; i<n; i++)
        str[i]=s[i];
  }

//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica& e){
      str = new string[e.reservados];
      anio=e.anio;
      numeventos = e.numeventos;
      reservados = e.numeventos;
      for(int i=0; i<numeventos; ++i)
         str[i] = e.str[i];
   }
   
//Destructor
    Fecha_Historica::~Fecha_Historica(){
        anio=0;
        reservados=0;
        numeventos=0;
        delete[] str;
    }
   
   
//Método de acceso a año
int Fecha_Historica::getAnio() const{
    return anio;
}
   
//Método de acceso a evento
   string Fecha_Historica::getEvento(int num){
        assert (num < numeventos);
        return str[num];
   }


//Añade un evento
  void Fecha_Historica::aniadirevento(string& event){
     if (numeventos == reservados){
        if (numeventos==0)
           resize(1);
        else
        resize(reservados+10);
     }
     str[numeventos]=event;
     numeventos++;
  }


//Buscador de eventos
  bool Fecha_Historica::buscarEventos(string s, Fecha_Historica &matches){
     bool encontrado=false;
     for (int i=0; i < numeventos; ++i){
        if(str[i].find(s) != -1 ){
           matches.aniadirevento(str[i]);
           encontrado = true;
        }
     }
     if (encontrado){
        matches.anio=anio;
      }
    return encontrado;       
   }

//Operador <<
  ostream& operator<< (ostream& os, const Fecha_Historica& e){
      os << e.getAnio();
      
      for (int i=0; i < e.numeventos; i++)
          os << '#' << e.str[i];
      return os;
  }

//Operador >>
  istream& operator>> (istream& is, Fecha_Historica& e){
      string evento;
      
      getline (is, evento, '#');
      
      e.anio = atoi (evento.c_str());
      
      while (!is.eof()){
          getline (is, evento, '#');
          e.aniadirevento(evento);
      }
      return is;
  }  
