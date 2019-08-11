#ifndef NODO_H
#define NODO_H

#include <iostream>

template <class DATO> class ABB;
template <class DATO>
class Nodo
{
public:
    // Constructor:
    Nodo(DATO dat, Nodo<DATO> *izq=NULL, Nodo<DATO> *der=NULL) :
    dato(dat), izquierda(izq), derecha(der) {}
    // Miembros:
private:
    DATO dato;
    Nodo<DATO> *izquierda;
    Nodo<DATO> *derecha;

    friend class ABB<DATO>;
};



#endif // NODO_H
