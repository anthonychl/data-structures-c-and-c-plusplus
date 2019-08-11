#ifndef NODO_H
#define NODO_H
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code:"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

#include <stdlib.h>

template<class TIPO> class lista;

template<class TIPO>
class nodo
{
private:
    TIPO valor;
    nodo<TIPO> *siguiente;
    nodo<TIPO> *anterior;
public:
nodo(TIPO v, nodo<TIPO> *sig = NULL, nodo<TIPO> *ant = NULL) :
valor(v), siguiente(sig), anterior(ant) {}

friend class lista<TIPO>;
};

#endif // NODO_H
