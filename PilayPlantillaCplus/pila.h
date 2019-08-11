#ifndef PILA_H
#define PILA_H
#include "nodo.h"

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" 
     "|_|_|0|" 
     "|0|0|0|" 
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

/* //asi estaba originalmente en el ejemplo
  //junto con la implementacion en la .cpp pero no funciona
template <class TIPO>
class pila
{
private:
   nodo<TIPO> *ultimo;

public:
    pila():ultimo(NULL){}
    ~pila();
    void Push(TIPO v);
    TIPO Pop();

};

//!!!!! ver pila.cpp al final
*/

//con la implementacion dentro de la misma clase si pincha
template <class TIPO>
class pila
{
private:
   nodo<TIPO> *ultimo;

public:
    pila():ultimo(NULL){}
    ~pila(){ while(ultimo)Pop();}
    void Push(TIPO v)
    {
        //----crear nuevo nodo
        nodo<TIPO> *nuevo;
        nuevo = new nodo<TIPO>(v,ultimo);
        ultimo = nuevo; //ahora la pila comienza por nuevo
    }
    TIPO Pop()
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

};
#endif // PILA_H
