#include <stdlib.h>
#include <iostream>
#include "lista.h"
#include "listanodo.h"

/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code(had errors, at least when i compiled it on Qt)"
     "in EDD book by:Salvador Pozo &Steven R. Davidson"
*/

using namespace std;
int main()
{

        cout << "Anthony Chaple did this(0_o)" << endl;
        cout << "|_|0|_|" << endl;
        cout << "|_|_|0|" << endl;
        cout << "|0|0|0|" << endl;
        cout << "---------------------------------" << endl;

Lista<int> iLista; int iValor;
Lista<char> cLista; char cValor;
Lista<float> fLista; float fValor;
Lista<double> dLista; double dValor;
// Prueba con
iLista.InsertarAlPpio(20);
iLista.InsertarAlPpio(10);
iLista.InsertarAlPpio(40);
iLista.InsertarAlPpio(30);
iLista.MostrarLista();
iLista.BorrarAlPpio( iValor );
iLista.BorrarAlPpio( iValor );
iLista.BorrarAlPpio( iValor );
iLista.BorrarAlPpio( iValor );
iLista.BorrarAlPpio( iValor );
iLista.MostrarLista();
// Prueba con <char>
cLista.InsertarAlPpio(101);
cLista.InsertarAlPpio(87);
cLista.InsertarAlPpio(43);
cLista.InsertarAlPpio(39);
cLista.MostrarLista();
cLista.BorrarAlPpio( cValor );
cLista.BorrarAlPpio( cValor );
cLista.BorrarAlPpio( cValor );
cLista.BorrarAlPpio( cValor );
cLista.BorrarAlPpio( cValor );
cLista.MostrarLista();
// Prueba con <float>
fLista.InsertarAlPpio(23.203);
fLista.InsertarAlPpio(43.102);
fLista.InsertarAlPpio(2.401);
fLista.InsertarAlPpio(1.301);
fLista.MostrarLista();
fLista.BorrarAlPpio( fValor );
fLista.BorrarAlPpio( fValor );
fLista.BorrarAlPpio( fValor );
fLista.BorrarAlPpio( fValor );
fLista.BorrarAlPpio( fValor );
fLista.MostrarLista();
// Prueba con <double>
dLista.InsertarAlPpio(0.01123233l);
dLista.InsertarAlPpio(0.12312312l);
dLista.InsertarAlPpio(1131.123112l);
dLista.InsertarAlPpio(1233.9891323l);
dLista.MostrarLista();
dLista.BorrarAlPpio( dValor );
dLista.BorrarAlPpio( dValor );
dLista.BorrarAlPpio( dValor );
dLista.BorrarAlPpio( dValor );
dLista.BorrarAlPpio( dValor );
dLista.MostrarLista();
// Insertar y Borrar desde el Final
// Prueba con <int>
iLista.InsertarAlFinal(20);
iLista.InsertarAlFinal(10);
iLista.InsertarAlFinal(40);
iLista.InsertarAlFinal(30);
iLista.MostrarLista();
iLista.BorrarAlFinal( iValor );
iLista.BorrarAlFinal( iValor );
iLista.BorrarAlFinal( iValor );
iLista.BorrarAlFinal( iValor );
iLista.BorrarAlFinal( iValor );
iLista.MostrarLista();
// Prueba con <char>
cLista.InsertarAlFinal(101);
cLista.InsertarAlFinal(87);
cLista.InsertarAlFinal(43);
cLista.InsertarAlFinal(39);
cLista.MostrarLista();
cLista.BorrarAlFinal( cValor );
cLista.BorrarAlFinal( cValor );
cLista.BorrarAlFinal( cValor );
cLista.BorrarAlFinal( cValor );
cLista.BorrarAlFinal( cValor );
cLista.MostrarLista();
// Prueba con <float>
fLista.InsertarAlFinal(23.203);
fLista.InsertarAlFinal(43.102);
fLista.InsertarAlFinal(2.401);
fLista.InsertarAlFinal(1.301);
fLista.MostrarLista();
fLista.BorrarAlFinal( fValor );
fLista.BorrarAlFinal( fValor );
fLista.BorrarAlFinal( fValor );
fLista.BorrarAlFinal( fValor );
fLista.BorrarAlFinal( fValor );
fLista.MostrarLista();
// Prueba con <double>
dLista.InsertarAlFinal(0.01123233);
dLista.InsertarAlFinal(0.12312312);
dLista.InsertarAlFinal(1131.123112);
dLista.InsertarAlFinal(1233.9891323);
dLista.MostrarLista();
dLista.BorrarAlFinal( dValor );
dLista.BorrarAlFinal( dValor );
dLista.BorrarAlFinal( dValor );
dLista.BorrarAlFinal( dValor );
dLista.BorrarAlFinal( dValor );
dLista.MostrarLista();
system("PAUSE");
return 0;

}

