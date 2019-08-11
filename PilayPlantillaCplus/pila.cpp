#include "pila.h"
/*
template<class TIPO>
pila<TIPO>::~pila()
{
    while(ultimo)Pop();
}

template<class TIPO>
void pila::Push(TIPO v)
{
    //----crear nuevo nodo
    nodo<TIPO> *nuevo;
    nuevo = new nodo<TIPO>(v,ultimo);
    ultimo = nuevo; //ahora la pila comienza por nuevo
}

template<class TIPO>
TIPO pila::Pop()
{
    nodo<TIPO> *nuevo ;// vars aux
    TIPO v;

    if(!ultimo) return 0; //si no hay nodos return 0
    //si hay nodos:
    nuevo = ultimo; //se asigna toda la pila a nuevo
    ultimo = nuevo->siguiente; //se asigna a ultimo la pila a partir del 2do elemento

    v=nuevo->valor; //guardar valor d retorno
    delete nuevo;   //borrar el nuevo nodo(nodo al ppio d la pila)

    return v;

}

*/

/* !!!!!!!!!!!!!Attention!!!!!!!!!!!Atencion!!!!!!!!!!!!
ya se xq no pincha lo de arriba 
hay q agregar <TIPO> en las implementaciones antes de los :: de esta manera

template <class TIPO>
void pila<TIPO>::Push(TIPO v)
{
  //lo q va aqui dentro
}

asi q lo pueden dejar como esta(q funciona igual) o arreglarlo y tenerlo mas organizado

*/