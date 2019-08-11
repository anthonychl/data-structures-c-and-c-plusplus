/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
     "original code isnt a complete program so I added & changed some code"
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _nodo
{
    int dato;
    struct _nodo *izquierda;
    struct _nodo *derecha;
}tipoNodo;

typedef tipoNodo *Arbol;
typedef tipoNodo *pNodo;

void Insertar(Arbol *a,int dat);
int Borrar(Arbol *a,int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int *contador);
void auxContador(Arbol nodo, int *c);
int AlturaArbol(Arbol a, int *altura);
void auxAltura(pNodo nodo, int a, int *altura);
int Altura(Arbol a, int dat);
void MostrarArbolPreOrden(Arbol a);
void MostrarArbolInOrden(Arbol a);
void MostrarArbolPostOrden(Arbol a);
/*
 void InOrden(Arbol a, void (*func)(int*));
 void PreOrden(Arbol a, void (*func)(int*));
 void PostOrden(Arbol a, void (*func)(int*));
*/


int main(void)
{
    printf("------#3ll0 W0RlD!\n");
    printf("Anthony Chaple did this(0_o)\n");
    printf( "|_|0|_|\n");
    printf( "|_|_|0|\n");
    printf( "|0|0|0|\n");
    printf( "---------------------------------\n");

    Arbol tree = NULL;

    printf("Insertar 20,15,30,25,10,50,5,17\n");
    Insertar(&tree,20);
    Insertar(&tree,15);
    Insertar(&tree,30);
    Insertar(&tree,25);
    Insertar(&tree,10);
    Insertar(&tree,50);
    Insertar(&tree,5);
    Insertar(&tree,17);

    if(Vacio(tree))printf("arbol vacio\n");
    else printf("el arbol tiene elementos\n");
    printf("------\n");
    printf("\n");

    printf("-Mostrar Arbol PreOrden\n");
    MostrarArbolPreOrden(tree);
    printf("------\n");
    printf("-Mostrar Arbol InOrden\n");
    MostrarArbolInOrden(tree);
    printf("------\n");
    printf("-Mostrar Arbol PostOrden\n");
    MostrarArbolPostOrden(tree);
    printf("------\n");
    printf("\n");

    printf("-Buscar el numero 70\n");
    if(Buscar(tree,70))printf("Se encontro el no. en el arbol\n");
    else printf("No se encontro el no. en el arbol\n");
    printf("------\n");
    printf("-Buscar el numero 25\n");
    if(Buscar(tree,25))printf("Se encontro el no. en el arbol\n");
    else printf("No se encontro el no. en el arbol\n");
    printf("------\n");
    printf("\n");

    printf("-Numero de nodos en el arbol\n");
    int numnodos = 0;
    printf(":%d\n",NumeroNodos(tree,&numnodos));
    printf("------\n");
    printf("\n");

    printf("-Altura del arbol\n");
    int treeheight;
    treeheight = 0;
    printf(":%d\n",AlturaArbol(tree,&treeheight));
    printf("------\n");
    printf("\n");

    printf("-Altura del nodo de valor 15 en el arbol\n");
    printf(":%d\n",Altura(tree,15));
    printf("------\n");
    printf("\n");

    printf("-Altura del nodo de valor 5 en el arbol\n");
    printf(":%d\n",Altura(tree,5));
    printf("------\n");
    printf("\n");

    printf("-Altura del nodo de valor 20 en el arbol\n");
    printf(":%d\n",Altura(tree,20));
    printf("------\n");
    printf("\n");


    printf("-Borrar nodo de valor 75 en el arbol\n");
    if(Borrar(&tree,75))printf("-Borrado\n");
    else printf("-No se encontro\n");
    printf("------\n");
    printf("\n");

    printf("-Borrar nodo de valor 5 en el arbol\n");
    if(Borrar(&tree,5))printf("-Borrado\n");
    else printf("-No se encontro\n");
    printf("------\n");
    printf("\n");

    printf("-Altura del arbol\n");
    treeheight = 0;
    printf(":%d\n",AlturaArbol(tree,&treeheight));
    printf("------\n");
    printf("\n");

    printf("-Mostrar Arbol PreOrden\n");
    MostrarArbolPreOrden(tree);
    printf("------\n");
    printf("-Mostrar Arbol InOrden\n");
    MostrarArbolInOrden(tree);
    printf("------\n");
    printf("-Mostrar Arbol PostOrden\n");
    MostrarArbolPostOrden(tree);
    printf("------\n");
    printf("\n");




    system("PAUSE");
    return 0;
}



void Insertar(Arbol *a,int dat)
{
    pNodo padre = NULL;
    pNodo actual = *a;

    while(!Vacio(actual) && dat != actual->dato)
    {
        padre = actual;

        if(dat < actual->dato) actual =actual->izquierda;
        else if(dat > actual->dato) actual = actual->derecha;
    }

    if(!Vacio(actual))return;

    if(Vacio(padre))
    {
        *a = (Arbol)malloc(sizeof(tipoNodo));
        (*a)->dato = dat;
        (*a)->izquierda = (*a)->derecha = NULL;
    }
    else if(dat < padre->dato)
    {
        actual = (Arbol)malloc(sizeof(tipoNodo));
        padre->izquierda = actual;
        actual->dato = dat;
        actual->izquierda = actual->derecha = NULL;
    }
    else if(dat > padre->dato)
    {
        actual = (Arbol)malloc(sizeof(tipoNodo));
        padre->derecha = actual;
        actual->dato = dat;
        actual->izquierda = actual->derecha = NULL;
    }
}


int Borrar(Arbol *a,int dat)
{
    pNodo padre = NULL;
    pNodo actual;
    pNodo nodo;
    int aux;

    actual = *a;
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
                free(actual);
                actual = NULL;
                return 1;
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
    return 0;
}

int Buscar(Arbol a, int dat)
{
    pNodo actual = a;
    while(!Vacio(actual))
    {
        if(dat == actual->dato) return TRUE; // Está en árbol
        else if(dat < actual->dato) actual = actual->izquierda;
        else if(dat > actual->dato) actual = actual->derecha;
    }
  return FALSE; // No está en árbol
}

int Vacio(Arbol r)
{
return r==NULL;
}

int EsHoja(pNodo r)
{
return !r->derecha && !r->izquierda;
}

int NumeroNodos(Arbol a, int *contador)
{
    *contador = 0;
    auxContador(a, contador);
    return *contador;
}

void auxContador(Arbol nodo, int *c)
{
    (*c)++; /* Acción: incrementar número de nodos. (Preorden) */
    if(nodo->izquierda) auxContador(nodo->izquierda, c); /* Rama izquierda */
    if(nodo->derecha) auxContador(nodo->derecha, c); /* Rama derecha */
}

int AlturaArbol(Arbol a, int *altura)
{
    *altura = 0; /* (1) */
    auxAltura(a, 0, altura);
    return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura)
{
    if(nodo->izquierda) auxAltura(nodo->izquierda, a+1, altura);
    if(nodo->derecha) auxAltura(nodo->derecha, a+1, altura);
    if(EsHoja(nodo) && a > *altura) *altura = a; //postorden
}

int Altura(Arbol a, int dat)
{
  int altura = 0;
  pNodo actual = a;
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

void MostrarArbolPreOrden(Arbol a)
{
    if(a==NULL)return;
    printf("--%d--",a->dato); // Aplicar la función al dato del nodo actual
    if(a->izquierda) MostrarArbolPreOrden(a->izquierda); // Subárbol izquierdo
    if(a->derecha) MostrarArbolPreOrden(a->derecha); // Subárbol derecho
}

void MostrarArbolInOrden(Arbol a)
{
    if(a==NULL)return;
    if(a->izquierda) MostrarArbolInOrden(a->izquierda); // Subárbol izquierdo
    printf("--%d--",a->dato); // Aplicar la función al dato del nodo actual
    if(a->derecha) MostrarArbolInOrden(a->derecha); // Subárbol derecho
}

void MostrarArbolPostOrden(Arbol a)
{
    if(a==NULL)return;
    if(a->izquierda) MostrarArbolPostOrden(a->izquierda); // Subárbol izquierdo
    if(a->derecha) MostrarArbolPostOrden(a->derecha); // Subárbol derecho
    printf("--%d--",a->dato); // Aplicar la función al dato del nodo actual
}


/*
void InOrden(Arbol a, void (*func)(int*))
{
    if(a->izquierda) InOrden(a->izquierda, func); // Subárbol izquierdo
    func(&(a->dato)); // Aplicar la función al dato del nodo actual
    if(a->derecha) InOrden(a->derecha, func); // Subárbol derecho
}

void PreOrden(Arbol a, void (*func)(int*))
{
    func(&(a->dato)); // Aplicar la función al dato del nodo actual
    if(a->izquierda) PreOrden(a->izquierda, func); // Subárbol izquierdo
    if(a->derecha) PreOrden(a->derecha, func); // Subárbol derecho
}

void PostOrden(Arbol a, void (*func)(int*))
{
    if(a->izquierda) PostOrden(a->izquierda, func); // Subárbol izquierdo
    if(a->derecha) PostOrden(a->derecha, func); // Subárbol derecho
    func(&(a->dato)); // Aplicar la función al dato del nodo actual
}
*/
