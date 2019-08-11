#ifndef NODO_H
#define NODO_H

#include <iostream>

template<class TIPO> class lista;
template<class TIPO>
class nodo
{
    private:
        TIPO valor;
        nodo<TIPO> *siguiente;

    public:
        nodo(TIPO v, nodo<TIPO> *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }

friend class lista<TIPO>;
};

#endif // NODO_H
