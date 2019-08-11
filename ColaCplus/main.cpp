#include <iostream>

using namespace std;
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" << endl;
     "|_|_|0|" << endl;
     "|0|0|0|" << endl;
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/
class nodo
{
private:
    int valor;
    nodo *siguiente;
public:
    nodo(int v, nodo *sig=NULL)
    {
        valor = v;
        siguiente = sig;
    }

    friend class cola; //cola amiga de nodo para q pueda acceder al private de nodo
};

typedef nodo *pNodo;

class cola
{
private:
    pNodo primero,ultimo;
public:
    cola():primero(NULL),ultimo(NULL){}
    ~cola();

    void Queue(int v);//Queue: Anyadir a cola
    int Dequeue();    //Dequeue: leer y sacar de cola
};

cola::~cola()
{
    while(primero)Dequeue();
}

void cola::Queue(int v)
{
    pNodo nuevo;
    nuevo = new nodo(v);

    if(ultimo)ultimo->siguiente = nuevo; //si habia elementos en la cola hacer a nuevo el ultimo
    ultimo = nuevo;

    if(!primero)primero=nuevo;//si primero es NULL(cola vacia): nuevo es el primero

}

int cola::Dequeue()
{
    pNodo nodo; //vars aux
    int v;

    nodo = primero; //nodo apunta a primero

    if(!nodo)return 0; //si no hay nodos return 0

    primero =nodo->siguiente; //primero es ahora el 2do elemento d la cola
    v = nodo->valor; //guardar el valor de retorno

    delete nodo;

    if(!primero)ultimo =NULL; //si no hay elementos ultimo es NULL tambien

    return v;


}

int main()
{
    cout << "Hello World!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;


    cola Cola;
    Cola.Queue(20);
    cout << "Anyadir 20"<<endl;
    Cola.Queue(10);
    cout << "Anyadir 10"<<endl;
    cout << "Leer: "<<Cola.Dequeue()<<endl;
    Cola.Queue(40);
    cout << "Anyadir 40"<<endl;
    Cola.Queue(30);
    cout << "Anyadir 30"<<endl;
    cout << "Leer: "<<Cola.Dequeue()<<endl;
    cout << "Leer: "<<Cola.Dequeue()<<endl;
    Cola.Queue(90);
    cout << "Anyadir 90"<<endl;
    cout << "Leer: "<<Cola.Dequeue()<<endl;
    cout << "Leer: "<<Cola.Dequeue()<<endl;

    system("PAUSE");
    return 0;
}

