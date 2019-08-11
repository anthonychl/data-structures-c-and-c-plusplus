#ifndef LISTANODO_H
#define LISTANODO_H
#include <iostream>

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/
template <class TIPONODO> class Lista;
template <class TIPONODO>
//def clase Listanodo

class Listanodo
{
private:
    TIPONODO valor;
    Listanodo<TIPONODO> *pSiguienteNodo;
public:
//constructor
Listanodo(const TIPONODO &dato)
{
    valor = dato;
    pSiguienteNodo = NULL;
}
TIPONODO tenValor()const {return valor;}
friend class Lista<TIPONODO>;
};
#endif // LISTANODO_H
