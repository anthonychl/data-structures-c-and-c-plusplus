/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors)in EDD book by:Salvador Pozo &Steven R. Davidson"
*/
#include <iostream>
#include "lista.h"
#include "lista.cpp"
#include <string>

#define ASCENDENTE 1
#define DESCENDENTE 0

using namespace std;

int main()
{
    cout << "---H3ll0 W0rld!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;

    lista<int> iLista;
    lista<float> fLista;
    lista<double> dLista;
    lista<char> cLista;
    //lista<char *> cadLista;
    lista<string> cadLista;

    // Prueba con <int>
    iLista.Insertar(20);
    iLista.Insertar(10);
    iLista.Insertar(40);
    iLista.Insertar(30);
    iLista.Mostrar(ASCENDENTE);
    iLista.Mostrar(DESCENDENTE);
    iLista.Primero();
    cout << "Primero: " << iLista.ValorActual() << endl;
    iLista.Ultimo();
    cout << "Ultimo: " << iLista.ValorActual() << endl;
    iLista.Borrar(10);
    iLista.Borrar(15);
    iLista.Borrar(45);
    iLista.Borrar(40);
    iLista.Mostrar(ASCENDENTE);
    iLista.Mostrar(DESCENDENTE);
    cout<<endl;

    // Prueba con <float>
    fLista.Insertar(20.01);
    fLista.Insertar(10.02);
    fLista.Insertar(40.03);
    fLista.Insertar(30.04);
    fLista.Mostrar(ASCENDENTE);
    fLista.Mostrar(DESCENDENTE);
    fLista.Primero();
    cout << "Primero: " << fLista.ValorActual() << endl;
    fLista.Ultimo();
    cout << "Ultimo: " << fLista.ValorActual() << endl;
    fLista.Borrar(10.02);
    fLista.Borrar(15.05);
    fLista.Borrar(45.06);
    fLista.Borrar(40.03);
    fLista.Mostrar(ASCENDENTE);
    fLista.Mostrar(DESCENDENTE);
    cout<<endl;

    // Prueba con <double>
    dLista.Insertar(0.0020);
    dLista.Insertar(0.0010);
    dLista.Insertar(0.0040);
    dLista.Insertar(0.0030);
    dLista.Mostrar(ASCENDENTE);
    dLista.Mostrar(DESCENDENTE);
    dLista.Primero();
    cout << "Primero: " << dLista.ValorActual() << endl;
    dLista.Ultimo();
    cout << "Ultimo: " << dLista.ValorActual() << endl;
    dLista.Borrar(0.0010);
    dLista.Borrar(0.0015);
    dLista.Borrar(0.0045);
    dLista.Borrar(0.0040);
    dLista.Mostrar(ASCENDENTE);
    dLista.Mostrar(DESCENDENTE);
    cout<<endl;

    // Prueba con <char>
    cLista.Insertar('x');
    cLista.Insertar('y');
    cLista.Insertar('a');
    cLista.Insertar('b');
    cLista.Mostrar(ASCENDENTE);
    cLista.Mostrar(DESCENDENTE);
    cLista.Primero();
    cout << "Primero: " << cLista.ValorActual() << endl;
    cLista.Ultimo();
    cout << "Ultimo: " << cLista.ValorActual() << endl;
    cLista.Borrar('y');
    cLista.Borrar('m');
    cLista.Borrar('n');
    cLista.Borrar('a');
    cLista.Mostrar(ASCENDENTE);
    cLista.Mostrar(DESCENDENTE);
    cout<<endl;

    // Prueba con <string> // no muestra las cadenas, tampoco con char* , why??
    cadLista.Insertar("Hola");
    cadLista.Insertar("seguimos");
    cadLista.Insertar("estando");
    cadLista.Insertar("aquí");
    cadLista.Mostrar(ASCENDENTE);
    cadLista.Mostrar(DESCENDENTE);
    cadLista.Primero();
    cout << "Primero: " << cadLista.ValorActual() << endl;
    cadLista.Ultimo();
    cout << "Ultimo: " << cadLista.ValorActual() << endl;
    cadLista.Borrar("seguimos");
    cadLista.Borrar("adios");
    cadLista.Borrar("feos");
    cadLista.Borrar("estando");
    cadLista.Mostrar(ASCENDENTE);
    cadLista.Mostrar(DESCENDENTE);

    system("PAUSE");
    return 0;
}

