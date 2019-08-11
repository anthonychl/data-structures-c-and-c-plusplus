/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/
#include <stdio.h>
#include <stdlib.h>

#define ASCENDENTE 1
#define DESCENDENTE 0

typedef struct _nodo
{
    int valor;
    struct _nodo *anterior;
    struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//funciones

void Insertar(Lista *,int);
void Borrar(Lista *,int);
void MostrarLista(Lista ,int);
void BorrarLista(Lista *);

int main(void)
{
    printf("-------------H3llo World!\n");
    printf("Anthony Chaple did this(0_o)\n");
    printf( "|_|0|_|\n");
    printf( "|_|_|0|\n");
    printf( "|0|0|0|\n");
    printf( "---------------------------------\n");
    printf("error log:\n");
    printf("En Qt al mostrar la lista muestra primero el q primero entro y ordena el resto\n");
    printf("pero en Code::Blocks corre perfect y ordena bien\n");
    printf( "---------------------------------\n");

    Lista lista = NULL;


    Insertar(&lista, 20);
    Insertar(&lista, 10);
    Insertar(&lista, 40);
    Insertar(&lista, 30);

    MostrarLista(lista, ASCENDENTE);
    MostrarLista(lista, DESCENDENTE);

    Borrar(&lista, 10);
    Borrar(&lista, 15);
    Borrar(&lista, 45);
    Borrar(&lista, 30);

    MostrarLista(lista, ASCENDENTE);
    MostrarLista(lista, DESCENDENTE);

    BorrarLista(&lista);

    system("PAUSE");
    return 0;
}

void Insertar(Lista *lista, int v)
{
    pNodo nuevo, actual;
    //crear nodo nuevo
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor=v;

    //colocar actual en la 1ra posicion de la lista
    actual = *lista;
    if(actual)while(actual->anterior)actual = actual->anterior;

    //si la lista esta vacia o el 1er nodo es mayor q el nuevo
    if((!actual) || (actual->valor > nuevo))
    {
        //anyadir la lista a continuacion del nuevo nodo
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if(actual) actual->anterior = nuevo;
        if(!*lista) *lista = nuevo;

    }
    else
    {
       //avanzar hasta el ultimo nodo o hasta q un el nodo siguiente tenga un valor > o = q v
       while((actual->siguiente) && (actual->siguiente->valor<=v))actual = actual->siguiente;

       //insertar el nodo nuevo entre el actual(menor q v) y el siguiente(igual o mayor q v)
       nuevo->siguiente = actual->siguiente;
       nuevo->anterior = actual;
       actual->siguiente = nuevo;
       //si nuevo no es el ultimo: nuevo es el anterior del proximo nodo
       if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;

    }
}

void Borrar(Lista *lista, int v)
{
    pNodo Aux;
    //buscar nodo de valor v
    Aux = *lista;
    //recorrer lista hacia atras hasta el ppio o hasta q encuentre un valor = o < q v
    while (Aux->anterior && Aux->anterior->valor>=v)Aux=Aux->anterior;
    //recorrer lista hacia adelante hasta el final o hasta q encuentre un valor = o > q v
    while (Aux->siguiente && Aux->siguiente->valor<=v)Aux=Aux->siguiente;

    //no hay lista o no existe el valor v
    if(!Aux || Aux->valor!=v)return;

    //borrar el nodo
    //si lista apunta al nodo q queremos borrar, apuntarlo a otro nodo
    if(Aux == *lista)
    {
        if(Aux->anterior) *lista = Aux->anterior;
        else *lista = Aux->siguiente;
    }

    if(Aux->anterior)//si aux no es el 1er elemento
        Aux->anterior->siguiente=Aux->siguiente;
    if(Aux->siguiente)//si aux no es el ultimo
        Aux->siguiente->anterior = Aux->anterior;

    free(Aux);
}

void BorrarLista(Lista *lista)
{
    pNodo Aux,actual;

    actual = *lista;
    while(actual->anterior)actual = actual->anterior;

    while(actual)
    {
        Aux = actual;
        actual = actual->siguiente;
        free(Aux);
    }
    *lista = NULL;
}

void MostrarLista(Lista lista, int orden)
{
    pNodo nodo = lista;
    if(!lista) printf("Lista vacía");
        nodo = lista;
    if(orden == ASCENDENTE)
      {
        while(nodo->anterior) nodo = nodo->anterior;
        printf("Orden ascendente: ");
        while(nodo)
        {
             printf("%d -> ", nodo->valor);
            nodo = nodo->siguiente;
        }
      }
    else
      {
        while(nodo->siguiente) nodo = nodo->siguiente;
        printf("Orden descendente: ");
        while(nodo)
        {
            printf("%d -> ", nodo->valor);
            nodo = nodo->anterior;
        }
      }
    printf("\n");
}









