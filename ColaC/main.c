#include <stdio.h>
#include <stdlib.h>
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" << endl;
     "|_|_|0|" << endl;
     "|0|0|0|" << endl;
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
     "--------------------------------i change the code a little bit"
*/

typedef struct _nodo
{
    int valor;
    struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo; //aqui con solo declarar y usar un tipo (*pNodo) basta
typedef tipoNodo *pCola; //uso los dos para diferenciar mejor
//funciones con cola

void Anyadir(pCola *p, pCola *u, int v); //Queue    nombre habitual para esta funcion cuando se trata de colas
int Leer(pCola *p,pCola *u);             //Dequeue  nombre habitual para esta funcion cuando se trata de colas

int main(void)
{
    printf("Hello World!\n");
    printf("Anthony Chaple did this(0_o)\n");
    printf( "|_|0|_| \n");
    printf( "|_|_|0|\n");
    printf( "|0|0|0|\n");
    printf( "---------------------------------\n");

    pCola primero = NULL, ultimo = NULL;
    Anyadir(&primero, &ultimo, 20);  //se usa: & xq se esta trabajando con direcciones no directamente un valor
    printf("Añadir(20)\n");
    Anyadir(&primero, &ultimo, 10);
    printf("Añadir(10)\n");
    printf("Leer: %d\n", Leer(&primero, &ultimo));
    Anyadir(&primero, &ultimo, 40);
    printf("Añadir(40)\n");
    Anyadir(&primero, &ultimo, 30);
    printf("Añadir(30)\n");
    printf("Leer: %d\n", Leer(&primero, &ultimo));
    printf("Leer: %d\n", Leer(&primero, &ultimo));
    Anyadir(&primero, &ultimo, 90);
    printf("Añadir(90)\n");
    printf("Leer: %d\n", Leer(&primero, &ultimo));
    printf("Leer: %d\n", Leer(&primero, &ultimo));

    system("PAUSE");
    return 0;
}

void Anyadir(pCola *primero, pCola *ultimo, int v)//*primero y *ultimo reciben direcciones
{
    pNodo nuevo;
    //crear nuevo nodo
    nuevo =(pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor= v;
    //nuevo va a ser el ultimo por lo q no debe tener sigte
    nuevo->siguiente=NULL;
    //si la cola no estaba vacia anyadimos nuevo al final
    if(*ultimo) (*ultimo)->siguiente=nuevo;   //Qt se marea con el casteo pero pincha
    //ahora hacemos q nuevo sea el ultimo elemento
    *ultimo = nuevo;
    //si la cola estaba vacia entonces hacemos q nuevo tambien sea primero
    if(!*primero) *primero=nuevo;


}

int Leer(pCola *primero, pCola *ultimo)//*primero y *ultimo reciben direcciones
{
    pNodo nuevo;
    int v;  // vars aux

    nuevo = *primero; //a nuevo se le asigna el primer valor de la cola
    if(!nuevo)return 0; //si no hay nodos en la cola return 0

    *primero = nuevo->siguiente; //primero es ahora el 2do de la cola
    //Qt se marea con -> pero pincha
    v = nuevo->valor; //guardar valor de retorno

    free(nuevo); //borrar el elemento
    if(!*primero) *ultimo=NULL; //si la cola quedo vacia ultimo es NULL tambien
    return v;


}

