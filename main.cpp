#include <iostream>
#include "Arbol.h"

using namespace  std;

int main() {


    Arbol arbol1;



    arbol1.agregar(10);

    arbol1.agregar(9);
    arbol1.agregar(11);


    arbol1.agregar(5);
    arbol1.agregar(6);
    arbol1.agregar(4);

    arbol1.enOrden();
    cout<<"El numero de nodos es "<<arbol1.numeroNodos()<<endl;
    cout<<"La altura es  "<<arbol1.altura()<<endl;
    arbol1.eliminar(9);

    cout<<endl;

    arbol1.enOrden();
    cout<<"El numero de nodos es "<<arbol1.numeroNodos()<<endl;
    cout<<"La altura es  "<<arbol1.altura()<<endl;
    return 0;
}
