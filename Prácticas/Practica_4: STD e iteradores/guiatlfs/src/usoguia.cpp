#include "guiatlf.h"
#include <fstream>
int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Dime el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  
 Guia_Tlf g;
 
 f>>g;
 cout<<"La guia insertada "<<endl<<g<<endl;
 cin.clear();
 cout<<"Dime un telefono sobre el que quieres obtener el nombre"<<endl;
 string n;
 
getline(cin,n);
cout<<"Buscando "<<n<<"...."<<endl;
string nombre = g.getnombre(n);

if (nombre=="")
	cout<<"No existe ese telefono en la guia"<<endl;	
else 
	cout<<"El nombre es "<<nombre<<endl;

cin.clear();
cout<<"Dime dos nombres para borrar todos los telefonos entre ellos"<<endl;
 
string m;
getline(cin,n);
getline(cin,m);
g.borrarEntreNombres(n, m);

cout<<endl<<"Ahora la guia es:"<<endl;
cout<<g<<endl;

cout<<endl<<"Dime un nombre para establecer los siguientes"<<endl;
cin>>n;
Guia_Tlf p = g.siguientes(n);
cout<<endl<<"Los nombre siguientes: "<<endl<<p<<endl;

cin.clear();
Guia_Tlf otraguia;
cout<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
cin>>otraguia; cin.clear();
Guia_Tlf un = g+otraguia;
Guia_Tlf dif = g-otraguia;
cout<<endl<<"La union de las dos guias: "<<un<<endl;
 
cout<<endl<<"La diferencia de las dos guias:"<<dif<<endl;
 
cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
cin>>n;
string tlf= g.gettelefono(n);
p = g.previos(n,tlf);
cout<<endl<<"Los nombre previos: "<<p<<endl;
 
 
cout<<"Listando la guia con iteradores:"<<endl;
Guia_Tlf::iterator it;
for (it=g.begin(); it!=g.end(); ++it)
	cout<<*it<<endl;
}
