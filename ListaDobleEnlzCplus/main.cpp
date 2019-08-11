#include <iostream>
#include <stdlib.h>
using namespace std;
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

#define ASCENDENTE 1
#define DESCENDENTE 0

class nodo
{
private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
public:
    nodo(int v,nodo *sig=NULL,nodo *ant=NULL):valor(v),siguiente(sig),anterior(ant){}

    friend class lista;
};

typedef nodo *pNodo;
class lista
{
private:
   pNodo actual;
public:
   lista():actual(NULL){}
   ~lista();

   void Insertar(int v);
   void Borrar(int v);
   bool ListaVacia(){return actual==NULL;}
   void Mostrar(int);
   void Primero();
   void Ultimo();
   void BorrarLista();
   void Anterior();
   void Siguiente();
   pNodo Actual(){return actual;}
   int ValorActual(){return actual->valor;}

};

lista::~lista()
{
    pNodo aux;

    Primero();
    while(actual)
    {
        aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}

void lista::Insertar(int v)
{
    pNodo nuevo;

    Primero();
    // Si la lista está vacía
    if(ListaVacia() || actual->valor >v)
    {
    // Asignamos a lista un nuevo nodo de valor v y
    // cuyo siguiente elemento es la lista actual
    nuevo = new nodo(v, actual);
    if(!actual) actual = nuevo;
    else actual->anterior = nuevo;
    }
    else
    {
       // Buscar el nodo de valor menor a v
       // Avanzamos hasta el último elemento o hasta que el siguiente tenga
       // un valor mayor que v
       while(actual->siguiente && actual->siguiente->valor <= v) Siguiente();
       // Creamos un nuevo nodo después del nodo actual
       //tener cuidado con el orden en q las variables aparecen en el constructor de la clase
       //y el orden en que se ponen en la declaracion de la variable (ver q coincidan)
        nuevo = new nodo(v, actual->siguiente, actual);
        actual->siguiente = nuevo;
        if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
    }
}

void lista::Borrar(int v)
{
    pNodo aux;

    aux = actual;

    while(aux && aux->valor < v) aux = aux->siguiente;
    while(aux && aux->valor > v) aux = aux->anterior;

    //si la lista esta vacia o no se encontro el valor salir
    if(!aux || aux->valor != v)return;

    //borrar el nodo
    if(aux->anterior) // no es el primer elemento
    aux->anterior->siguiente = aux->siguiente;
    if(aux->siguiente) // no el el último nodo
    aux->siguiente->anterior = aux->anterior;
    delete aux;

}

void lista::Mostrar(int orden)
{
    pNodo aux;
    if(orden == ASCENDENTE)
    {
        Primero();
        aux = actual;
       while(aux)
       {
            cout <<aux->valor <<"-> ";
            aux = aux->siguiente;
       }
    }
    else
    {
        Ultimo();
    aux = actual;
        while(aux)
        {
            cout << aux->valor << "-> ";
            aux = aux->anterior;
        }
    }
    cout << endl;
}

void lista::Siguiente()
{
if(actual) actual = actual->siguiente;
}

void lista::Anterior()
{
if(actual) actual = actual->anterior;
}

void lista::Primero()
{
while(actual && actual->anterior) actual = actual->anterior;
}

void lista::Ultimo()
{
while(actual && actual->siguiente) actual = actual->siguiente;
}


int main()
{
    cout << "-----H3ll0 W0rld!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;

    lista Lista;
    Lista.Insertar(20);
    Lista.Insertar(10);
    Lista.Insertar(40);
    Lista.Insertar(30);
    Lista.Mostrar(ASCENDENTE);
    Lista.Mostrar(DESCENDENTE);
    Lista.Primero();
    cout << "Primero: " << Lista.ValorActual() << endl;
    Lista.Ultimo();
    cout << "Ultimo: " << Lista.ValorActual() << endl;
    Lista.Borrar(10);
    Lista.Borrar(15);
    Lista.Borrar(45);
    Lista.Borrar(40);
    Lista.Mostrar(ASCENDENTE);
    Lista.Mostrar(DESCENDENTE);



    system("PAUSE");
    return 0;
}





