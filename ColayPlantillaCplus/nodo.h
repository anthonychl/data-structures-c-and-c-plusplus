#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <stdlib.h>

template <class TIPO> class cola;
template <class TIPO>
class nodo
{
private:
    TIPO valor;
    nodo *siguiente;

public:
    nodo(TIPO v,nodo *sig=NULL)
    {
        valor = v;
        siguiente = sig;
    }

    friend class cola<TIPO>;
};

#endif // NODO_H
