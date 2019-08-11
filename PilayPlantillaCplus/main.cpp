#include <iostream>
#include <stdlib.h>
#include "pila.h"
using namespace std;

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|" << endl;
     "|_|_|0|" << endl;
     "|0|0|0|" << endl;
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

int main()
{
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;

    pila<int> iPila;
    pila<float> fPila;
    pila<double> dPila;
    pila<char> cPila;
    pila<char *> sPila;

    // Prueba con <int>
    iPila.Push(20);
    iPila.Push(10);
    cout << iPila.Pop() << ",";
    iPila.Push(40);
    iPila.Push(30);
    cout << iPila.Pop() << ",";
    cout << iPila.Pop() << ",";
    iPila.Push(90);
    cout << iPila.Pop() << ",";
    cout << iPila.Pop() << endl;

   // Prueba con <float>
    fPila.Push(20.01);
    fPila.Push(10.02);
    cout << fPila.Pop() << ",";
    fPila.Push(40.03);
    fPila.Push(30.04);
    cout << fPila.Pop() << ",";
    cout << fPila.Pop() << ",";
    fPila.Push(90.05);
    cout << fPila.Pop() << ",";
    cout << fPila.Pop() << endl;

    // Prueba con <double>
    dPila.Push(0.0020);
    dPila.Push(0.0010);
    cout << dPila.Pop() << ",";
    dPila.Push(0.0040);
    dPila.Push(0.0030);
    cout << dPila.Pop() << ",";
    cout << dPila.Pop() << ",";
    dPila.Push(0.0090);
    cout << dPila.Pop() << ",";
    cout << dPila.Pop() << endl;

    // Prueba con <char>
    cPila.Push('x');
    cPila.Push('y');
    cout << cPila.Pop() << ",";
    cPila.Push('a');
    cPila.Push('b');
    cout << cPila.Pop() << ",";
    cout << cPila.Pop() << ",";
    cPila.Push('m');
    cout << cPila.Pop() << ",";
    cout << cPila.Pop() << endl;

    // Prueba con <char *>
    sPila.Push("Hola");
    sPila.Push("somos");
    cout << sPila.Pop() << ",";
    sPila.Push("programadores");
    sPila.Push("buenos");
    cout << sPila.Pop() << ",";
    cout << sPila.Pop() << ",";
    sPila.Push("!!!!");
    cout << sPila.Pop() << ",";
    cout << sPila.Pop() << endl;

    system("PAUSE");

    return 0;
}

