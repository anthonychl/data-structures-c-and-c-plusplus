#include "abb.h"
/*
ABB::ABB()
{
}
*/
/*
template <class DATO>
ABB<DATO>::~ABB()
{
    Podar(raiz);
}

template <class DATO>
void ABB<DATO>::Insertar(DATO dat)
{
    Nodo<DATO> *padre = NULL;
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
               raiz = new Nodo<DATO>(dat,NULL,NULL);

           }
           else if(dat < padre->dato)
           {
               actual = new Nodo<DATO>(dat,NULL,NULL);
               padre->izquierda = actual;

           }
           else if(dat > padre->dato)
           {
               actual = new Nodo<DATO>(dat,NULL,NULL);
               padre->derecha = actual;

           }
}

template <class DATO>
void ABB<DATO>::Borrar(DATO dat)
{
    Nodo<DATO> *padre = NULL;

       Nodo<DATO> *nodo;
       DATO aux;

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

template <class DATO>
bool ABB<DATO>::Buscar(DATO dat)
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

template <class DATO>
int ABB<DATO>::NumeroNodos()
{
    Nodo<DATO> *a = raiz;
        contador = 0;
        auxContador(a);
        return contador;
}

template <class DATO>
int ABB<DATO>::AlturaArbol()
{
     Nodo<DATO> *a = raiz;
     altura = 0; // (1)
     auxAltura(a, 0);
     return altura;
}

template <class DATO>
int ABB<DATO>::Altura(DATO dat)
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

template <class DATO>
void ABB<DATO>::MostrarArbolPreOrden()
{
   Nodo<DATO> *showpro = raiz;
   cout<<"Mostrar Arbol PreOrden"<<endl;
    PreO(showpro);

}

template <class DATO>
void ABB<DATO>::MostrarArbolInOrden()
{
    Nodo<DATO> *showino = raiz;
    cout<<"Mostrar Arbol InOrden"<<endl;
    InO(showino);
}

template <class DATO>
void ABB<DATO>::MostrarArbolPostOrden()
{
    Nodo<DATO> *showpso = raiz;
    cout<<"Mostrar Arbol PostOrden"<<endl;
    PostO(showpso);
}

template <class DATO>
void ABB<DATO>::PreO(Nodo<DATO> *pro)
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

template <class DATO>
void ABB<DATO>::InO(Nodo<DATO> *io)
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

template <class DATO>
void ABB<DATO>::PostO(Nodo<DATO> *pso)
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

template <class DATO>
void ABB<DATO>::Podar(Nodo<DATO> *a)
{
    if(a==NULL)return;
    if(a->izquierda) Podar(a->izquierda); // Subárbol izquierdo
    if(a->derecha) Podar(a->derecha); // Subárbol derecho
    delete a; // Aplicar la función al dato del nodo actual
}

template <class DATO>
void ABB<DATO>::auxContador(Nodo<DATO> *nodo)
{
     contador++; ///* Acción: incrementar número de nodos. (Preorden)
     if(nodo->izquierda) auxContador(nodo->izquierda);// /* Rama izquierda
     if(nodo->derecha) auxContador(nodo->derecha); ///* Rama derecha
}

template <class DATO>
void ABB<DATO>::auxAltura(Nodo<DATO> *nodo, int a)
{
    if(nodo->izquierda) auxAltura(nodo->izquierda, a+1);
    if(nodo->derecha) auxAltura(nodo->derecha, a+1);
    if(EsHoja(nodo) && a > altura) altura = a; //postorden
}
*/
