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

class nodo
{
private:
    nodo *siguiente;
    int valor;
public:
    nodo(int v,nodo *sig=NULL)
    {
        valor =v;
        siguiente=sig;
    }

    friend class pila; //se hace q la clase pila sea amiga d la clase nodo
                       //para q pila pueda acceder al private de nodo
};
//------------------------------------------
typedef nodo *pnodo;  //se crea un tipo de dato clase 'nodo', asi el obj pila puede
                      //crear punteros con las propiedades(private) de clase nodo
class pila
{
private:
    pnodo ultimo;
public:
    pila():ultimo(NULL){}
    ~pila();

    void Push(int v);
    int Pop();

};

pila::~pila()
{
    while(ultimo)Pop();
}

void pila::Push(int v)
{
     pnodo nuevo; //crear nuevo nodo q apunta a ultimo
     nuevo = new nodo(v,ultimo);
     ultimo = nuevo; //ahora nuevo es el ultimo(top of the pile)

}

int pila::Pop()
{
    //variables aux
    pnodo nodo;
    int v;

    if(!ultimo)return 0;//si no hay nodos return 0
    nodo = ultimo; //nodo apunta al primer(top of the pile) elemento de la pila

    ultimo = nodo->siguiente; // el primero de arriba va a ser el 2do de la pila
    v=nodo->valor; //guardar valor del nodo antes de borrar
    delete nodo; //borrar nodo
    return v;
}
//-------------------------------------------
int main()
{
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;
	
    pila Pila;
    Pila.Push(20);
    cout << "Push(20)" << endl;
    Pila.Push(10);
    cout << "Push(10)" << endl;
    cout << "Pop() = " << Pila.Pop() << endl;
    Pila.Push(40);
    cout << "Push(40)" << endl;
    Pila.Push(30);
    cout << "Push(30)" << endl;
    cout << "Pop() = " << Pila.Pop() << endl;
    cout << "Pop() = " << Pila.Pop() << endl;
    Pila.Push(90);
    cout << "Push(90)" << endl;
    cout << "Pop() = " << Pila.Pop() << endl;
    cout << "Pop() = " << Pila.Pop() << endl;
    system("PAUSE");

    return 0;
}

