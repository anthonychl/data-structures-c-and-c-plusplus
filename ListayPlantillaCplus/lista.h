#ifndef LISTA_H
#define LISTA_H

#include <assert.h>
#include <iostream>
#include "listanodo.h"

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

using namespace std;

//def class Lista
template <class TIPONODO>

class Lista
{

private:
    Listanodo<TIPONODO> *pPrimero;
    Listanodo<TIPONODO> *pUltimo;
    unsigned int tamanyo;
public:
    //constructor
    Lista(): pPrimero(NULL),pUltimo(NULL),tamanyo(0){}
    //destroyer
    ~Lista()
    {
        if(!ListaVacia())
        {
            Listanodo<TIPONODO> *pActual=pPrimero,*pTemp;

            while(pActual != NULL)
            {
                pTemp = pActual;
                pActual = pActual->pSiguienteNodo;
                delete pTemp;
                tamanyo--;

            }

        }

    }
    //funciones basicas con listas
    /*
Insertar un nodo al comienzo de la lista.
** Creamos un nodo. Copiamos el dato del parámetro para el nodo.
** Retorno:
** True := El nodo se pudo crear e insertar
** 'False' := No existe la posibilidad, ya que el programa aborta si no es
** exitoso en crear un nodo: no hay recursos libres.
    */

    bool InsertarAlPpio(const TIPONODO &v)
    {
        //crear nodo nuevo
        Listanodo<TIPONODO> *pNuevo;

        assert((pNuevo= new Listanodo<TIPONODO>(v))!=NULL);

        if(ListaVacia())
        {
            //el comienzo y final de la lista es el mismo nodo
            pPrimero=pUltimo=pNuevo;
        }
        else //la lista ya tiene nodos
        {
            // El nuevo nodo apunta al siguiente nodo, que era el
            // primero
            pNuevo->pSiguienteNodo=pPrimero;
            //pPrimero apunta a pNuevo
            pPrimero=pNuevo;
        }
        tamanyo++;
        return true;
    }

    /* Insertar un nodo al final de la lista.
    ** Creamos un nodo. Copiamos el dato del par´<metro para el nodo.
    ** Retorno:
    ** True := El nodo se pudo crear e insertar
    ** 'False' := No existe la posibilidad, ya que el programa aborta si no es
    ** exitoso en crear un nodo: no hay recursos libres.
    */

    bool InsertarAlFinal(const TIPONODO &v)
    {
        Listanodo<TIPONODO> *pNuevo;
        assert((pNuevo= new Listanodo<TIPONODO>(v))!=NULL);

        if(ListaVacia())
        {
            pPrimero=pUltimo=pNuevo;
        }
        else
        {
            //pUltimo apunta a pNuevo, q sera el ultimo
            pUltimo->pSiguienteNodo=pNuevo;

            pUltimo=pNuevo;
        }
        tamanyo++;
        return true;

    }

    // Insertar en una posicion 'indice'
    bool Insertar(unsigned int indice, TIPONODO &v)
    {
        /* Si:
        ** Lista est´< Vacía, llama a la función InsertarAlPrincipio()
        ** Indice <= 1, llama a la función InsertarAlPrincipio()
        ** Indice > Tamaño, llama a la función InsertarAlFinal()
        ** Indice existe, procésalo en ésta función
        */
        if(ListaVacia()||indice<=1)return InsertarAlPpio(v);
        else if(indice>tamanyo)return InsertarAlFinal(v);
        else
        {
            Listanodo<TIPONODO> *pNuevo,*pActual;
            unsigned int posicion;

            //crear nodo nuevo
            assert((pNuevo= new Listanodo<TIPONODO>(v))!=NULL);

            //busqueda hasta el indice correcto
            pActual=pPrimero;
            for(posicion=2;posicion<indice;posicion++)
                pActual=pActual->pSiguienteNodo;

            //insertar el nodo nuevo despues de nodoactual(q es el nodo anterior)
            pNuevo->valor=v;
            pNuevo->pSiguienteNodo=pActual->pSiguienteNodo;
            pActual->pSiguienteNodo=pNuevo;
            tamanyo++;
        }
        return true;
    }

    // Funciones para Borrar nodos
    /* Borramos el primer nodo de la lista. Además copiamos el valor
    ** del nodo a borrar, en v.
    ** Retorno:
    ** True := El nodo ha sido borrado.
    ** False := El nodo no se pudo borrar.
    */
    bool BorrarAlPpio(TIPONODO &v)
    {
        // Si la Lista NO está vacía
        if(!ListaVacia())
        {
            // Necesitamos un nodo temporal que apunte al principio
            Listanodo<TIPONODO> *pTemp=pPrimero;

            // Si sólo hay un nodo, entonces ya no tenemos una lista
            if(pPrimero==pUltimo)
                pPrimero=pUltimo=NULL;
            // Si tenemos más de un nodo, entonces el primer nodo será
            // el segundo
            else
                pPrimero=pPrimero->pSiguienteNodo;

            // Copiar el valor del nodo a borrar antes de serlo
            v = pTemp->valor;
            delete pTemp;
            tamanyo--;
            return true; // Realizado con éxito
         }
        return false; //si fallo
    }

    /* Borramos el último nodo de la lista. Además copiamos el valor
    ** del nodo a borrar, en 'v'.
    ** Retorno:
    ** True := El nodo ha sido borrado.
    ** False := El nodo no se pudo borrar.
    */
    bool BorrarAlFinal( TIPONODO &v)
    {
    /* Si la Lista NO está vacía */
        if (!ListaVacia())
        {
            // Necesitamos un nodo temporal que apunte al final
            Listanodo<TIPONODO> *pTemp = pUltimo;
            // Si sólo hay un nodo, entonces ya no tenemos una lista
            if( 1 == tamanyo )
            pPrimero = pUltimo = NULL;
            // Si tenemos más de un nodo, entonces el penúltimo nodo
            // será el último
            else
            {
                Listanodo<TIPONODO> *pActual=pPrimero;
                unsigned int contador;
                // Encontrar el penúltimo nodo, que se convertirá en el
                // último
                for( contador=1; contador < tamanyo-1; contador++ )
                pActual = pActual->pSiguienteNodo;

                pUltimo = pActual;
                pActual->pSiguienteNodo = NULL;

            }
            // Copiar el valor del nodo a borrar antes de eliminarlo
            v = pTemp->valor;
            delete pTemp;
            tamanyo--;
            return true; // Realizado con éxito
        }
        return false;
     }

    // Borrar el nodo con la misma posición que 'indice'
    bool Borrar( unsigned int indice, TIPONODO &v )
    {
        /* Si:
        ** Lista está Vacía, retorna False
        ** Indice <= 1, llama a la función BorrarAlPrincipio()
        ** Indice > Tamaño, llama a la función BorrarAlFinal()
        ** Indice existe, procésalo en ésta función
        */
        if( indice <= 1 ) return BorrarAlPrincipio( v );
        else if( indice > tamanyo ) return BorrarAlFinal( v );
        else
        {
            Listanodo<TIPONODO> *pTemp,*pActual;
            unsigned int posicion;
            // Empezamos nuestra búsqueda desde el principio de la lista
            pActual = pPrimero;
            // Avanzamos hasta que se llegue a la posición anterior al
            // índice correcto
            for( posicion = 2; posicion < indice; posicion++ )
            pActual = pActual->pSiguienteNodo;
            /* Borramos el nodo después del nodo pActual, que
            ** simplemente salta al siquiente nodo en la lista.
            ** El nodo saltado es borrado.
            */
            pTemp = pActual->pSiguienteNodo;
            v = pTemp->valor;
            pActual->pSiguienteNodo = pTemp->pSiguienteNodo;
            delete pTemp;
            tamanyo--;
         }
            return true;

      }

     //
    bool ListaVacia( void ) const { return (tamanyo == 0); }
    //

    // Mostrar la Lista en pantalla
    void MostrarLista()
    {
        Listanodo<TIPONODO> *pActual=pPrimero;

        if(ListaVacia())cout<<"Lista vacia\n";
        else
        {
            unsigned int contador;
            // Obtener el dato de cada nodo, y visualizarlo
            for( contador=1; contador < tamanyo; contador++ )
            {
            cout << pActual->valor << " -> ";
            pActual = pActual->pSiguienteNodo;
            }
            cout << pActual->valor << endl;
        }
    }


};

#endif // LISTA_H
