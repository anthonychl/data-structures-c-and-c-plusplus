#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>

using namespace std;

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

#define ASCENDENTE 1
#define DESCENDENTE 0

template<class TIPO>
class lista
{
private:
    nodo<TIPO> *plista;
public:
    lista() : plista(NULL) {}
    ~lista();
    void Insertar(TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return plista == NULL; }
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    TIPO ValorActual() { return plista->valor; }
};

#endif // LISTA_H
