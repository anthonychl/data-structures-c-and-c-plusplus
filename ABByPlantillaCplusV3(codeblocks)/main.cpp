/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "Based on C code & Class declaration"
     "(there is no FULL C++ template example)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "abb.h"

using namespace std;

int main()
{
       cout << "--#3110 W0rld!" << endl;
       cout << "Anthony Chaple did this(0_o)" << endl;
       cout << "|_|0|_|" << endl;
       cout << "|_|_|0|" << endl;
       cout << "|0|0|0|" << endl;
       cout << "---------------------------------" << endl;

       ABB<int> tree;
       ABB<char> ctree;
       //int tree
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

       //char tree
       cout<<"Insertar a,r,b,s,g,c,t,z"<<endl;
       ctree.Insertar('a');
       ctree.Insertar('r');
       ctree.Insertar('b');
       ctree.Insertar('s');
       ctree.Insertar('q');
       ctree.Insertar('c');
       ctree.Insertar('t');
       ctree.Insertar('z');
       cout<<endl;

       ctree.MostrarArbolPreOrden();
       cout<<endl;
       ctree.MostrarArbolInOrden();
       cout<<endl;
       ctree.MostrarArbolPostOrden();
       cout<<endl;
       cout<<endl;

       cout<<"Altura del arbol: ";
       cout<<ctree.AlturaArbol();
       cout<<endl;
       cout<<"Cantidad de nodos del arbol: "<<ctree.NumeroNodos()<<endl;
       cout<<endl;

       cout<<"Borrar q y x"<<endl;
       ctree.Borrar('q');
       ctree.Borrar('x');
       cout<<endl;
       ctree.MostrarArbolPreOrden();
       cout<<endl;
       cout<<endl;

       cout<<"Buscar el char q"<<endl;
       if(ctree.Buscar('q'))
           cout<<"Se encontro el char"<<endl;
       else
           cout<<"No se encontro el char"<<endl;

       cout<<"Buscar el char a"<<endl;
       if(ctree.Buscar('a'))
           cout<<"Se encontro el char"<<endl;
       else
           cout<<"No se encontro el char"<<endl;

       cout<<endl;
       cout<<"Altura del arbol: ";
       cout<<ctree.AlturaArbol()<<endl;
       cout<<endl;

       int cheight = 0;
       cout<<"Altura del nodo d valor b: ";
       cheight = ctree.Altura('b');
       (cheight>=0)?cout<<cheight<<endl:cout<<"No se encontro el nodo"<<endl;
       cout<<endl;
       cout<<"Altura del nodo d valor s: ";
       cheight = ctree.Altura('s');
       (cheight>=0)?cout<<cheight<<endl:cout<<"No se encontro el nodo"<<endl;
       cout<<endl;



       system("PAUSE");
       return 0;
}

