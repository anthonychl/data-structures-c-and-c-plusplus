#include "cola.h"
/*
cola::cola()
{
}
*/
/*
template <class TIPO>
cola::~cola()
{
    while(primero)Dequeue();
}

template <class TIPO>
void cola::Queue(TIPO v)
{
    nodo<TIPO> *Nuevo;

    Nuevo = new nodo(v);

    // Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo
    if(ultimo) ultimo->siguiente = Nuevo;
    // Ahora, el último elemento de la cola es el nuevo nodo
    ultimo = nuevo;
    // Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo
    if(!primero) primero = Nuevo;

}

template <class TIPO>
TIPO cola::Dequeue()
{
    nodo<TIPO> *Nodo;
    TIPO v;  //vars aux

    if(!primero)return 0; //si no hay nada en la cola salir

    //asignar el segundo valor de la cola como primero
    Nodo = primero;
    primero = Nodo->siguiente;

    v = Nodo->valor; // guardar valor de retorno

    delete Nodo; // eliminar nodo de la cola
    return v;

}
*/

/* !!!!!!!!!!!!!Attention!!!!!!!!!!!Atencion!!!!!!!!!!!!
ya se xq no pincha lo de arriba 
hay q agregar <TIPO> en las implementaciones antes de los :: de esta manera

template <class TIPO>
void cola<TIPO>::Queue(TIPO v)
{
  //lo q va aqui dentro
}

asi q lo pueden dejar como esta(q funciona igual) o arreglarlo y tenerlo mas organizado

*/