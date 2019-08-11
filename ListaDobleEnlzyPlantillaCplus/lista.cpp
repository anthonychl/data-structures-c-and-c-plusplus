#include "lista.h"

template<class TIPO>
lista<TIPO>::~lista()
{
    nodo<TIPO> *aux;
    Primero();
    while(plista)
    {
        aux = plista;
        plista = plista->siguiente;
        delete aux;
    }
}

template<class TIPO>
void lista<TIPO>::Insertar(TIPO v)
{
    nodo<TIPO> *nuevo;
    Primero();
    // Si la lista está vacía o el valor del primer nodo > v
    if(ListaVacia() || plista->valor > v)
    {
        // Asignamos a lista un nuevo nodo de valor v y
        // cuyo siguiente elemento es la lista actual
        nuevo = new nodo<TIPO>(v, plista);
        if(!plista) plista = nuevo;
        else plista->anterior = nuevo;
    }
    else
    {
        // Buscar el nodo de valor menor a v
        // Avanzamos hasta el último elemento o hasta que el q tenga
        // un valor mayor que v
        while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
        // Creamos un nuevo nodo después del nodo actual
        nuevo = new nodo<TIPO>(v, plista->siguiente, plista);
        plista->siguiente = nuevo;
        if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
    }
}


template<class TIPO>
void lista<TIPO>::Borrar(TIPO v)
{
    nodo<TIPO> *pnodo;
    pnodo = plista;

    //buscar el valor recorriendo la lista primero en un sentido y luego en otro
    while(pnodo && pnodo->valor < v) pnodo = pnodo->siguiente;
    while(pnodo && pnodo->valor > v) pnodo = pnodo->anterior;

    //si la lista esta vacia o no se encuentra el valor: salir
    if(!pnodo || pnodo->valor != v) return;

    // Borrar el nodo
    if(pnodo->anterior) //si no es el primer elemento
    pnodo->anterior->siguiente = pnodo->siguiente;
    if(pnodo->siguiente) // no el el último nodo
    pnodo->siguiente->anterior = pnodo->anterior;

    delete pnodo;
}


template<class TIPO>
void lista<TIPO>::Mostrar(int orden)
{
    nodo<TIPO> *pnodo;
    if(orden == ASCENDENTE)
    {
        Primero();
        pnodo = plista;
        while(pnodo)
        {
         cout << pnodo->valor << "-> ";
         pnodo = pnodo->siguiente;
        }
    }
    else
    {
        Ultimo();
        pnodo = plista;
        while(pnodo)
        {
         cout << pnodo->valor << "-> ";
         pnodo = pnodo->anterior;
        }
    }
 cout << endl;
}


template<class TIPO>
void lista<TIPO>::Siguiente()
{
 if(plista) plista = plista->siguiente;
}


template<class TIPO>
void lista<TIPO>::Anterior()
{
 if(plista) plista = plista->anterior;
}


template<class TIPO>
void lista<TIPO>::Primero()
{
 while(plista && plista->anterior) plista = plista->anterior;
}


template<class TIPO>
void lista<TIPO>::Ultimo()
{
 while(plista && plista->siguiente) plista = plista->siguiente;
}
