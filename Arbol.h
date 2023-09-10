//
// Created by Marco on 09/09/2023.
//

#ifndef INC_001_ARBOLES_ARBOL_H
#define INC_001_ARBOLES_ARBOL_H

class Nodo{
public:
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(){
        izq = nullptr;
        der = nullptr;
    }
    Nodo(int dato):Nodo(){
        this->dato = dato;
    }
};

class Arbol{
private:

    Nodo* raiz;

    Nodo* agregar(Nodo* raiz,int dato);
    Nodo* eliminar(Nodo* raiz,int dato);
    Nodo* encontrarMaximo(Nodo* raiz){
        Nodo* aux = raiz;
        while( aux->der != nullptr)
        {
            aux = aux->der;
        }
        return  aux;
    };
    Nodo* encontrarMenor(Nodo* raiz){
        Nodo* aux = raiz;
        while( aux->izq != nullptr)
        {
            aux = aux->izq;
        }
        return  aux;
    }
    void preOrden(Nodo* raiz);
    void enOrden(Nodo* raiz,int nivel =0);
    void postOrden(Nodo* raiz);
    void eliminarTodo(Nodo* raiz);
    int numeroNodos(Nodo* raiz);
    int altura(Nodo* raiz);
public:
    Arbol();
    void agregar(int dato);
    void eliminar(int dato);
    void eliminarTodo();
    void preOrden();
    void enOrden();
    void postOrden();
    int numeroNodos();
    int altura();
};



#endif //INC_001_ARBOLES_ARBOL_H
