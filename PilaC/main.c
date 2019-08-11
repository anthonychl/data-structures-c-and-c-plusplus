#include <stdio.h>
#include <stdlib.h>

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" 
     "|_|_|0|" 
     "|0|0|0|" 
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo & Steven R. Davidson"
*/

typedef struct _nodo
{
      int valor;
      struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

//funciones con pila
void Push(Pila *l,int v);
int Pop(Pila *l);
//----------------------------------------------------------------
int main(void)
{

    printf("Anthony Chaple did this(0_o)\n");
    printf( "|_|0|_| \n");
    printf( "|_|_|0|\n");
    printf( "|0|0|0|\n");
    printf( "---------------------------------\n");
    Pila pila = NULL;
    Push(&pila, 20);
    Push(&pila, 10);
    printf("%d, ", Pop(&pila));
    Push(&pila, 40);
    Push(&pila, 30);
    printf("%d, ", Pop(&pila));
    printf("%d, ", Pop(&pila));
    Push(&pila, 90);
    printf("%d, ", Pop(&pila));
    printf("%d\n", Pop(&pila));
    return 0;
}
//----------------------------------------------------------------
void Push(Pila *pila,int v)
{
    //crear nodo nuevo
    pNodo nuevo;
    nuevo =(pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor=v;

    //anyadir la pila despues del nuevo nodo
    nuevo->siguiente= *pila;
    *pila = nuevo; //ahora la pila comienza con el nuevo nodo

}

int Pop(Pila *pila)
{
    pNodo nodo; //variable aux para manipular el nodo
    int v;

    nodo=*pila; //nodo apunta al primer elemento d la pila
    if(!nodo)return 0; //si no hay nodos: return 0

    *pila=nodo->siguiente; //se asigna toda la pila a partir del 2do elemento
    v=nodo->valor; //se guarda el valor del nodo en 'v' antes de borrarlo
    free(nodo);  //se borra el nodo
    return v;

}
