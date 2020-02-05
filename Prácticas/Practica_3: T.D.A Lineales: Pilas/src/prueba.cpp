#include "Pila_max_VD.h"
#include <iostream>

using namespace std;

int main()
{
    Pila_max a;
    
    for (int i=0; i < 6; i++)
    {
        a.poner(i);
        cout << a.tope();
    }
    a.poner(2);
    cout << a.tope();
    
    cout << endl;
    
    cout << "Hay " << a.num_elementos() << " elementos en la pila" << endl;
    
    while(!a.vacia())
    {
        cout << a.tope();
        a.quitar();
    }
}
