#include "lista.h"

using namespace std;

template <class TIPO>
lista<TIPO>::~lista()
{
    nodo<TIPO> *Aux;
    //mientras la lista tenga mas de un nodo
    while(actual != actual->siguiente )
    {
        Aux = actual->siguiente;
        actual->siguiente = Aux->siguiente;
        delete Aux;
    }
    //y borrar el ultimo nodo
    delete actual;
    actual = NULL;
}

template <class TIPO>
void lista<TIPO>::Insertar(TIPO v)
{
    //crear nuevo nodo
    nodo<TIPO> *Nuevo;
    Nuevo = new nodo<TIPO>(v);

    if(ListaVacia())actual = Nuevo; // si la lista esta vacia Nuevo es la lista
    else        //si no esta vacia
      Nuevo->siguiente = actual->siguiente;

   //y en cualquiera de los dos casos cerramos la lista
    actual->siguiente = Nuevo;

}

template <class TIPO>
void lista<TIPO>::Borrar(TIPO v)
{
    nodo<TIPO> *Aux;

    Aux = actual;

    do  //hacer q actual apunte al nodo con valor v
    {
        if(actual->siguiente->valor != v)
            Siguiente();

    }while((actual->siguiente->valor != v) && (actual != Aux) );

    if(actual->siguiente->valor == v) // si se encontro el valor v
      {
        if(actual->siguiente == actual)//si hay un solo nodo en la lista
        {
            delete actual;
            actual = NULL;
        }
        else // si hay mas nodos borrar el de valor v
        {
            Aux = actual->siguiente;
            actual->siguiente = Aux->siguiente;
            delete Aux;
        }
      }
}

template<class TIPO>
void lista<TIPO>::Mostrar()
{
    nodo<TIPO> *Nodo = actual;
    do {
        cout << Nodo->valor << "-> ";
        Nodo = Nodo->siguiente;
       } while(Nodo != actual);
    cout << endl;
}


template<class TIPO>
void lista<TIPO>::Siguiente()
{
    if(actual) actual = actual->siguiente;
}
