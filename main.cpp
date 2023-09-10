#include <iostream>
#include "Arbol.h"

using namespace  std;

int main() {


    Arbol arbol1;


    arbol1.agregar(10);
    arbol1.agregar(9);
    arbol1.agregar(11);
    arbol1.agregar(12);

    arbol1.enOrden();

    arbol1.eliminar(10);
    cout<<endl;

    arbol1.enOrden();
    return 0;
}
