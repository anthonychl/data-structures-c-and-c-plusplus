#ifndef NODO_H
#define NODO_H
#include <iostream>

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" << endl;
     "|_|_|0|" << endl;
     "|0|0|0|" << endl;
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/
template <class TIPO> class pila;

template <class TIPO>

class nodo
{
private:
    nodo<TIPO> *siguiente;
    TIPO valor;

public:
    nodo(TIPO v, nodo<TIPO> *sig=NULL)
    {
        valor=v;
        siguiente=sig;
    }

    friend class pila<TIPO>;
};

#endif // NODO_H
