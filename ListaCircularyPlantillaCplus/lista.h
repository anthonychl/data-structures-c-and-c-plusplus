#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

template <class TIPO>
class lista
{
private:
    TIPO valor;
    nodo<TIPO> *actual;
public:
    lista(){actual = NULL;}
    ~lista();

    void Insertar(TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return actual == NULL; }
    void Mostrar();
    void Siguiente();
    bool Actual() { return actual != NULL; }
    TIPO ValorActual() { return actual->valor; }

};

#endif // LISTA_H
