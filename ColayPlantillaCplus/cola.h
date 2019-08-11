#ifndef COLA_H
#define COLA_H

#include "nodo.h"

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
     "i had to implement the functions within the class,doesnt work anywhere else in the .h or the .cpp"

*/

template<class TIPO>
class cola
{
private:
    nodo<TIPO> *primero,*ultimo;
public:
    cola():primero(NULL),ultimo(NULL){}
    ~cola()
    {
        while(primero)Dequeue();
    }

    void Queue(TIPO v)
    {
        nodo<TIPO> *Nuevo;

        Nuevo = new nodo<TIPO>(v);

        // Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo
        if(ultimo) ultimo->siguiente = Nuevo;
        // Ahora, el último elemento de la cola es el nuevo nodo
        ultimo = Nuevo;
        // Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo
        if(!primero) primero = Nuevo;
    }

    TIPO Dequeue()
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

};

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

#endif // COLA_H
