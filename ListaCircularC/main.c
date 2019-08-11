#include <stdio.h>
#include <stdlib.h>

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

//Listas Circulares en C--------------------------------------------

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//funciones
void Insertar(Lista *lista,int v);
void Borrar(Lista *lista,int v);
void BorrarLista(Lista *lista);
void MostrarLista(Lista lista);

int main(void)
{
    printf("----H3ll0 World!\n");
    printf("Anthony Chaple did this (0_o)\n");
    printf( "|_|0|_|\n");
    printf( "|_|_|0|\n");
    printf( "|0|0|0|\n");
    printf( "---------------------------------\n");

    Lista lista=NULL;

    Insertar(&lista,10);
    Insertar(&lista,40);
    Insertar(&lista,30);
    Insertar(&lista,20);
    Insertar(&lista,50);

    MostrarLista(lista);

    Borrar(&lista,30);
    Borrar(&lista,50);

    MostrarLista(lista);

    BorrarLista(&lista);

    system("PAUSE");
    return 0;
}

void Insertar(Lista *lista, int v)
{
    //crear nuevo nodo
    pNodo nuevo;
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor=v;

    //si la lista esta vacia. tambien: if(*lista==NULL)
     if(!*lista) *lista = nuevo;
     else nuevo->siguiente = (*lista)->siguiente;
    //en cualquiera de los dos casos cerramos la lista
    (*lista)->siguiente = nuevo;
}

void Borrar(Lista *lista, int v)
{
    pNodo node = *lista; //var aux

    do
    {
        if((*lista)->siguiente->valor !=v)
            *lista = (*lista)->siguiente; //hacer q lista sea igual al elemento sigte mientras q:
                                          //el valor del proximo nodo sea diferente del q se
                                          //quiere borrar, y q: lista sea diferente del nodo por
                                          //el q comenzo el bucle

    }
    while((*lista)->siguiente->valor!=v && *lista!=node);


    //si se encontro el valor q se quiere borrar entonces:-----(es necesario esta condicion
    //xq el do while anterior puede parar xq encuentre el valor v o xq el bucle recorrio
    //la lista sin encontrarlo en cuyo caso no se hace nada)
    if((*lista)->siguiente->valor == v)
    {
        //si es una lista de un solo elemento borrar toda la lista
        if(*lista == (*lista)->siguiente)
        {
            free(*lista);
            *lista = NULL;
        }
        else //si la lista tiene mas de un nodo borrar el nodo de valor v
        {
            node = (*lista)->siguiente;
            (*lista)->siguiente = node->siguiente;
            free(node);
        }
    }
}

void BorrarLista(Lista *lista)
{
    pNodo node;

    while((*lista)->siguiente != *lista)//mientras la lista tenga mas de un elemento
    {
        //borrar el nodo sigte apuntado por lista
        node = (*lista)->siguiente;
        (*lista)->siguiente = node->siguiente;
        free(node);
    }
    //y borrar el ultimo nodo (esto hace falta xq el while se detiene cuando queda uno)
    free(*lista);
    *lista=NULL;
}

void MostrarLista(Lista lista)
{
    pNodo node = lista;

    do
    {
        printf("%d ->",node->valor);
        node = node->siguiente;
    }while(node != lista);
    printf("\n");

}


