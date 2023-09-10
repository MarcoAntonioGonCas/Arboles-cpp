//
// Created by Marco on 09/09/2023.
//

#include "Arbol.h"
#include <iostream>
using namespace  std;
Arbol::Arbol(){
    this->raiz = nullptr;
}

// Agregar un nodo a un arbol
Nodo* Arbol::agregar(Nodo* raiz,int dato){

    if(raiz == nullptr){
        Nodo* nuevo = new Nodo(dato);
        raiz = nuevo;
    }else if(dato < raiz->dato){

        raiz->izq = agregar(raiz->izq,dato);

    }else{
        raiz->der = agregar(raiz->der,dato);
    }
    return raiz;

}

void Arbol::agregar(int dato){
    raiz = agregar(raiz,dato);
}


// Eliminar un nodo a un arbol
Nodo* Arbol::eliminar(Nodo* raiz,int dato){
    // Si el nodo esta vacio
    if(raiz == nullptr){
        return raiz;
    }

    // Si el dato del nodo es igual al valor buscado
    if(raiz->dato == dato){

        // Si el nodo no tiene hojas
        if(raiz->izq == nullptr && raiz->der == nullptr){
            delete raiz;
            return nullptr;

        // Si el nodo tiene dos hojas
        }else if(raiz->izq != nullptr && raiz->der != nullptr){
            Nodo* actual = raiz;
            Nodo* menor = encontrarMaximo(actual->izq);

            actual->dato = menor->dato;


            actual->izq = eliminar(actual->izq, menor->dato);


        }else if(raiz->der != nullptr){
            //raiz = raiz->der;
            // -o-
            Nodo* temp = raiz->der;
            delete raiz;
            return temp;

        }else{
            Nodo* temp = raiz->izq;
            delete raiz;
            return temp;
        }


    }else if(dato < raiz->dato){ // Si el dato a buscar es menor que el del nodo actual
        // Buscamos en el nodo izquierdo
        raiz->izq =  eliminar(raiz->izq,dato);
    }else{
        // Buscamos en el nodo derecho
        raiz->der =  eliminar(raiz->der,dato);
    }
    return raiz;
}

void Arbol::eliminar(int dato){
    raiz = eliminar(raiz,dato);
}

void Arbol::preOrden(Nodo *raiz) {
    if(raiz == nullptr){
        return;
    }
    cout<<raiz->dato<<endl;
    enOrden(raiz->izq);
    enOrden(raiz->der);
}
void Arbol::enOrden(Nodo *raiz) {
    if(raiz == nullptr){
        return;
    }


    enOrden(raiz->izq);
    cout<<raiz->dato<<endl;
    enOrden(raiz->der);


}
void Arbol::postOrden(Nodo *raiz) {

    enOrden(raiz->izq);
    enOrden(raiz->der);
    cout<<raiz->dato<<endl;
}

// Mostrar arbol
void Arbol::preOrden() {

    preOrden(this->raiz);
}
void Arbol::enOrden() {
    enOrden(this->raiz);
}
void Arbol::postOrden() {
    postOrden(this->raiz);
}

// Elimina todo el arbol
void Arbol::eliminarTodo(Nodo *raiz) {

    if(raiz== nullptr){
        return;
   }
    eliminarTodo(raiz->izq);
    eliminarTodo(raiz->der);


    delete raiz;
}
void Arbol::eliminarTodo() {
    eliminarTodo(raiz);
    raiz = nullptr;
}