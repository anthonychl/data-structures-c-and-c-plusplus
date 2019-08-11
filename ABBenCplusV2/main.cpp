/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "Based on C code(there is no C++ example)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

#include <iostream>

using namespace std;

//definicion de la clase nodo
class Nodo
{
private:
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
public:
    //constructor
    Nodo(int dat,Nodo *izq,Nodo *der):dato(dat),izquierda(izq),derecha(der){}

    friend class ArbolABB;
};

typedef Nodo *pNodo;

class ArbolABB
{
private:
//public:
    pNodo raiz;
    pNodo actual;
    int altura;
    int contador;

public:
    ArbolABB():raiz(NULL),actual(NULL){}
    ~ArbolABB(){Podar(raiz);}

    // Insertar en árbol ordenado:
    void Insertar(int dat);
    // Borrar un elemento del árbol:
    void Borrar(int dat);
    // Función de búsqueda:
    bool Buscar(int dat);
    // Comprobar si el árbol está vacío:
    bool Vacio(pNodo r) { return r==NULL; }
    // Comprobar si es un nodo hoja:
    bool EsHoja(pNodo r) { return !r->derecha && !r->izquierda; }
    // Contar número de nodos:
    int NumeroNodos();
    int AlturaArbol();
    // Calcular altura de un int:
    int Altura(int dat);
    // Devolver referencia al int del nodo actual:
    int &ValorAct() { return actual->dato; }
    // Moverse al nodo raiz:
    void Raiz() { actual = raiz; }

    void MostrarArbolPreOrden();
    void MostrarArbolInOrden();
    void MostrarArbolPostOrden();
    void PreO(pNodo pro);
    void InO(pNodo io);
    void PostO(pNodo pso);
    /*
    // Aplicar una función a cada elemento del árbol:
    void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
    */

    // Funciones auxiliares
    void Podar(pNodo );
    void auxContador(pNodo nodo);
    void auxAltura(pNodo nodo, int a);

};

int main()
{
    cout << "--#3110 W0rld!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;

    ArbolABB tree ;

    cout<<"Insertar 20,15,30,25,10,50,5,17"<<endl;
    tree.Insertar(20);
    tree.Insertar(15);
    tree.Insertar(30);
    tree.Insertar(25);
    tree.Insertar(10);
    tree.Insertar(50);
    tree.Insertar(5);
    tree.Insertar(17);
    cout<<endl;

    tree.MostrarArbolPreOrden();
    cout<<endl;
    tree.MostrarArbolInOrden();
    cout<<endl;
    tree.MostrarArbolPostOrden();
    cout<<endl;
    cout<<endl;

    cout<<"Altura del arbol: ";
    cout<<tree.AlturaArbol();
    cout<<endl;
    cout<<"Cantidad de nodos del arbol: "<<tree.NumeroNodos()<<endl;
    cout<<endl;

    cout<<"Borrar 10 y 60"<<endl;
    tree.Borrar(10);
    tree.Borrar(60);
    cout<<endl;
    tree.MostrarArbolPreOrden();
    cout<<endl;
    cout<<endl;

    cout<<"Buscar el numero 10"<<endl;
    if(tree.Buscar(10))
        cout<<"Se encontro el numero"<<endl;
    else
        cout<<"No se encontro el numero"<<endl;

    cout<<"Buscar el numero 50"<<endl;
    if(tree.Buscar(50))
        cout<<"Se encontro el numero"<<endl;
    else
        cout<<"No se encontro el numero"<<endl;

    cout<<endl;
    cout<<"Altura del arbol: ";
    cout<<tree.AlturaArbol()<<endl;
    cout<<endl;

    int height = 0;
    cout<<"Altura del nodo d valor 5: ";
    height = tree.Altura(5);
    (height>=0)?cout<<height<<endl:cout<<"No se encontro el nodo"<<endl;
    cout<<endl;
    cout<<"Altura del nodo d valor 6: ";
    height = tree.Altura(6);
    (height>=0)?cout<<height<<endl:cout<<"No se encontro el nodo"<<endl;
    cout<<endl;


    system("PAUSE");
    return 0;
}



void ArbolABB::Insertar(int dat)
{
    pNodo padre = NULL;
       actual = raiz;

       while(!Vacio(actual) && dat != actual->dato)
       {
           padre = actual;

           if(dat < actual->dato) actual =actual->izquierda;
           else if(dat > actual->dato) actual = actual->derecha;
       }

       if(!Vacio(actual) && dat == actual->dato)return;

       if(Vacio(padre))
       {
           raiz = new Nodo(dat,NULL,NULL);

       }
       else if(dat < padre->dato)
       {
           actual = new Nodo(dat,NULL,NULL);
           padre->izquierda = actual;

       }
       else if(dat > padre->dato)
       {
           actual = new Nodo(dat,NULL,NULL);
           padre->derecha = actual;

       }
}

void ArbolABB::Borrar(int dat)
{
    pNodo padre = NULL;

       pNodo nodo;
       int aux;

       actual = raiz;

       while(!Vacio(actual))
       {
           if(dat == actual->dato)
           {
               if(EsHoja(actual))
               {
                   if(padre)
                   {
                       if(padre->derecha == actual)padre->derecha = NULL;
                       else if(padre->izquierda == actual)padre->izquierda = NULL;
                   }
                   delete actual;
                   actual = NULL;
                   cout<<"Se borro el numero"<<endl;
                   return ;
               }
               else
               {
                   padre = actual;
                   if(actual->derecha)
                   {
                       nodo = actual->derecha;
                       while(nodo->izquierda)
                       {
                           padre = nodo;
                           nodo = nodo->izquierda;
                       }
                   }
                   else
                   {
                       nodo = actual->izquierda;
                       while(nodo->derecha)
                       {
                           padre = nodo;
                           nodo = nodo->derecha;
                       }
                   }
                   aux = actual->dato;
                   actual->dato = nodo->dato;
                   nodo->dato = aux;
                   actual = nodo;
               }
           }
           else
           {
               padre = actual;
               if(dat > actual->dato) actual = actual->derecha;
               else if(dat < actual->dato) actual = actual->izquierda;
           }
       }
       cout<<"No se encotro el numero en el arbol"<<endl;
       return ;
}

bool ArbolABB::Buscar(int dat)
{
    Raiz();
       while(!Vacio(actual))
       {
           if(dat == actual->dato) return true; // Está en árbol
           else if(dat < actual->dato) actual = actual->izquierda;
           else if(dat > actual->dato) actual = actual->derecha;
       }
       return false; // No está en árbol
}

int ArbolABB::NumeroNodos()
{
    pNodo a = raiz;
    contador = 0;
    auxContador(a);
    return contador;
}

int ArbolABB::AlturaArbol()
{
     pNodo a = raiz;
     altura = 0; /* (1) */
     auxAltura(a, 0);
     return altura;
}

int ArbolABB::Altura(int dat)
{
    int altura = 0;
      Raiz();
      while(!Vacio(actual))
      {
         if(dat == actual->dato) return altura;
         else
         {
            altura++;
            if(dat < actual->dato) actual = actual->izquierda;
            else if(dat > actual->dato) actual = actual->derecha;
         }
      }
     return -1; // No está en árbol
}


void ArbolABB::MostrarArbolPreOrden()
{
   pNodo showpro = raiz;
   cout<<"Mostrar Arbol PreOrden"<<endl;
    PreO(showpro);

}

void ArbolABB::MostrarArbolInOrden()
{
    pNodo showino = raiz;
    cout<<"Mostrar Arbol InOrden"<<endl;
    InO(showino);
}

void ArbolABB::MostrarArbolPostOrden()
{
    pNodo showpso = raiz;
    cout<<"Mostrar Arbol PostOrden"<<endl;
    PostO(showpso);
}

void ArbolABB::PreO(pNodo pro)
{
    if(pro == NULL)return;
    cout<<"--"<<pro->dato<<"--";
    if(pro->izquierda)
    {
        PreO(pro->izquierda); // Subárbol izquierdo
    }

    if(pro->derecha)
    {
        PreO(pro->derecha); // Subárbol derecho
    }
}

void ArbolABB::InO(pNodo io)
{
    if(io == NULL)return;
    if(io->izquierda)
    {
        InO(io->izquierda); // Subárbol izquierdo
    }
    cout<<"--"<<io->dato<<"--";
    if(io->derecha)
    {
        InO(io->derecha); // Subárbol derecho
    }
}

void ArbolABB::PostO(pNodo pso)
{
    if(pso == NULL)return;
    if(pso->izquierda)
    {
        PostO(pso->izquierda); // Subárbol izquierdo
    }
    if(pso->derecha)
    {
        PostO(pso->derecha); // Subárbol derecho
    }
    cout<<"--"<<pso->dato<<"--";
}
void ArbolABB::Podar(pNodo a)
{
    if(a==NULL)return;
    if(a->izquierda) Podar(a->izquierda); // Subárbol izquierdo
    if(a->derecha) Podar(a->derecha); // Subárbol derecho
    delete a; // Aplicar la función al dato del nodo actual
}

void ArbolABB::auxContador(pNodo nodo)
{
     contador++; /* Acción: incrementar número de nodos. (Preorden) */
     if(nodo->izquierda) auxContador(nodo->izquierda); /* Rama izquierda */
     if(nodo->derecha) auxContador(nodo->derecha); /* Rama derecha */
}

void ArbolABB::auxAltura(pNodo nodo, int a)
{
    if(nodo->izquierda) auxAltura(nodo->izquierda, a+1);
    if(nodo->derecha) auxAltura(nodo->derecha, a+1);
    if(EsHoja(nodo) && a > altura) altura = a; //postorden
}


