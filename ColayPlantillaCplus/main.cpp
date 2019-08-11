#include <iostream>
#include "cola.h"
using namespace std;
/*
     "Anthony Chaple did this(0_o)"
     "|_|0|_|"
     "|_|_|0|"
     "|0|0|0|"
     "---------------------------------"
     "original code in EDD book by:Salvador Pozo &Steven R. Davidson"
*/


int main()
{
    cout << "Hello World!" << endl;
    cout << "Anthony Chaple did this(0_o)" << endl;
    cout << "|_|0|_|" << endl;
    cout << "|_|_|0|" << endl;
    cout << "|0|0|0|" << endl;
    cout << "---------------------------------" << endl;

    cola<int> iCola;
    cola<float> fCola;
    cola<double> dCola;
    cola<char> cCola;
    cola<char *> sCola;

    // Prueba con <int>
    iCola.Queue(20);
    cout << "Queue(20)" << endl;
    iCola.Queue(10);
    cout << "Queue(10)" << endl;
    cout << "Dequeue: " << iCola.Dequeue() << endl;
    iCola.Queue(40);
    cout << "Queue(40)" << endl;
    iCola.Queue(30);
    cout << "Queue(30)" << endl;
    cout << "Dequeue: " << iCola.Dequeue() << endl;
    cout << "Dequeue: " << iCola.Dequeue() << endl;
    iCola.Queue(90);
    cout << "Queue(90)" << endl;
    cout << "Dequeue: " << iCola.Dequeue() << endl;
    cout << "Dequeue: " << iCola.Dequeue() << endl;

    // Prueba con <float>
    fCola.Queue(20.01);
    cout << "Queue(20.01)" << endl;
    fCola.Queue(10.02);
    cout << "Queue(10.02)" << endl;
    cout << "Dequeue: " << fCola.Dequeue() << endl;
    fCola.Queue(40.03);
    cout << "Queue(40.03)" << endl;
    fCola.Queue(30.04);
    cout << "Queue(30.04)" << endl;
    cout << "Dequeue: " << fCola.Dequeue() << endl;
    cout << "Dequeue: " << fCola.Dequeue() << endl;
    fCola.Queue(90.05);
    cout << "Queue(90.05)" << endl;
    cout << "Dequeue: " << fCola.Dequeue() << endl;
    cout << "Dequeue: " << fCola.Dequeue() << endl;
    // Prueba con <double>
    dCola.Queue(0.0020);
    cout << "Queue(0.0020)" << endl;
    dCola.Queue(0.0010);
    cout << "Queue(0.0010)" << endl;
    cout << "Dequeue: " << dCola.Dequeue() << endl;
    dCola.Queue(0.0040);
    cout << "Queue(0.0040)" << endl;
    dCola.Queue(0.0030);
    cout << "Queue(0.0030)" << endl;
    cout << "Dequeue: " << dCola.Dequeue() << endl;
    cout << "Dequeue: " << dCola.Dequeue() << endl;
    dCola.Queue(0.0090);
    cout << "Queue(0.0090)" << endl;
    cout << "Dequeue: " << dCola.Dequeue() << endl;
    cout << "Dequeue: " << dCola.Dequeue() << endl;
    // Prueba con <char>
    cCola.Queue('x');
    cout << "Queue(\'x\')" << endl;
    cCola.Queue('y');
    cout << "Queue(\'y\')" << endl;
    cout << "Dequeue: " << cCola.Dequeue() << endl;
    cCola.Queue('a');
    cout << "Queue(\'a\')" << endl;
    cCola.Queue('b');
    cout << "Queue(\'b\')" << endl;
    cout << "Dequeue: " << cCola.Dequeue() << endl;
    cout << "Dequeue: " << cCola.Dequeue() << endl;
    cCola.Queue('m');
    cout << "Queue(\'m\')" << endl;
    cout << "Dequeue: " << cCola.Dequeue() << endl;
    cout << "Dequeue: " << cCola.Dequeue() << endl;
    // Prueba con <char *>
    sCola.Queue("Hola");
    cout << "Queue(\"Hola\")" << endl;
    sCola.Queue("somos");
    cout << "Queue(\"somos\")" << endl;
    cout << "Dequeue: " << sCola.Dequeue() << endl;
    sCola.Queue("programadores");
    cout << "Queue(\"programadores\")" << endl;
    sCola.Queue("buenos");
    cout << "Queue(\"buenos\")" << endl;
    cout << "Dequeue: " << sCola.Dequeue() << endl;
    cout << "Dequeue: " << sCola.Dequeue() << endl;
    sCola.Queue("!!!!");
    cout << "Queue(\"!!!!\")" << endl;
    cout << "Dequeue: " << sCola.Dequeue() << endl;
    cout << "Dequeue: " << sCola.Dequeue() << endl;

    system("PAUSE");
    return 0;
}

