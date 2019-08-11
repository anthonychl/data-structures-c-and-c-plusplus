#include <iostream>

using namespace std;
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

class nodo
 {
   private:
        int valor;
        nodo *siguiente;
   public:
        nodo(int v,nodo *sig=NULL)
        {
            valor = v;
            siguiente = sig;
        }

        friend class lista;

 };

typedef nodo *pnodo;

class lista
{
private:
    pnodo actual;
public:
    lista():actual(NULL){}
    ~lista();

    void Insertar(int);
    void Borrar(int);
    bool ListaVacia(){return actual == NULL;}//si actual=NULL return true
    void Mostrar();
    void Siguiente();
    bool Actual(){return actual != NULL;} //si actual existe return true
    int ValorActual(){return actual->valor;}
};



int main()
{
    cout << "-------H3ll0 W0rld!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "i changed original code a little 'bit' :)" << endl;
    cout << "---------------------------------" << endl;

    lista Lista;

    Lista.Insertar(20);
    Lista.Insertar(10);
    Lista.Insertar(40);
    Lista.Insertar(30);
    Lista.Insertar(60);
    cout << "Lista de elementos:" << endl;
    Lista.Mostrar();

    Lista.Borrar(10);
    Lista.Borrar(30);

    cout << "Lista de elementos (despues de borrar):" << endl;
    Lista.Mostrar();

    system("PAUSE");

    return 0;
}

lista::~lista()
{
    pnodo nodo;
    //mientras q la lista tenga mas de un nodo
    while(actual->siguiente != actual)
    {
        //borrar el nodo sgite al apuntado por lista
        nodo = actual->siguiente;
        actual->siguiente = nodo->siguiente;
        delete nodo;
    }
    //y borrar el ultimo nodo
    delete actual;
    actual = NULL;
}

void lista::Insertar(int v)
{
    //crear nuevo nodo
    pnodo Nuevo;
    Nuevo = new nodo(v);

    //si la lista esta vacia: Nodo sera la lista
    //si la lista tiene elementos: se inserta Nodo a continuacion del apuntado por lista
    if(ListaVacia())actual = Nuevo;
    else
        Nuevo->siguiente = actual->siguiente;
    //y en cualquiera de los dos casos antariores hay q cerrar la lista
    actual->siguiente=Nuevo;

}

void lista::Borrar(int v)
{
    pnodo Aux;

    Aux = actual;
    //hacer q la lista apunte al valor anterior a v
    do
    {
        if (actual->siguiente->valor != v)
            Siguiente();

    }while((actual->siguiente->valor != v) && (actual != Aux));

    if(actual->siguiente->valor == v)
    {
        //si la lista solo tiene un nodo
        if(actual == actual->siguiente)
        {
            //borrar toda la lista
            delete actual;
            actual = NULL;
        }
        else
        {
            //si la lista tiene mas nodos: borrar el de valor v
            Aux = actual->siguiente;
            actual->siguiente = Aux->siguiente;
            delete Aux;
        }
    }
}

void lista::Mostrar()
{
    pnodo Aux = actual;
    do
    {
        cout << Aux->valor << "-> ";
        Aux = Aux->siguiente;
    } while(Aux != actual);

        cout << endl;
}


void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

