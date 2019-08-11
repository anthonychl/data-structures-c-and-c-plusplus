#ifndef ABB_H
#define ABB_H

#include "nodo.h"
#include <iostream>
using namespace std;


template <class DATO>
class ABB
{
private:
//public:
    Nodo<DATO> *raiz;
    Nodo<DATO> *actual;
    int altura;
    int contador;
public:
    ABB():raiz(NULL),actual(NULL){}
    ~ABB();
    // Insertar en árbol ordenado:
    void Insertar(DATO dat);
    // Borrar un elemento del árbol:
    void Borrar(DATO dat);
    // Función de búsqueda:
    bool Buscar(DATO dat);
    // Comprobar si el árbol está vacío:
    bool Vacio(Nodo<DATO> *r) { return r==NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(Nodo<DATO> *r) { return !r->derecha && !r->izquierda; }
    // Contar número de nodos:
    int NumeroNodos();
    int AlturaArbol();
    // Calcular altura de un int:
    int Altura(DATO dat);
    // Devolver referencia al int del nodo actual:
    int &ValorAct() { return actual->dato; }
    // Moverse al nodo raiz:
    void Raiz() { actual = raiz; }

    void MostrarArbolPreOrden();
    void MostrarArbolInOrden();
    void MostrarArbolPostOrden();
    void PreO(Nodo<DATO> *pro);
    void InO(Nodo<DATO> *io);
    void PostO(Nodo<DATO> *pso);
    /*
    // Aplicar una función a cada elemento del árbol:
    void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    */

    // Funciones auxiliares
    void Podar(Nodo<DATO>* );
    void auxContador(Nodo<DATO> *nodo);
    void auxAltura(Nodo<DATO> *nodo, int a);
};

#endif // ABB_H
