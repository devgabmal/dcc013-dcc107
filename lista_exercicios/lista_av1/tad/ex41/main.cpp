// 22 minutos e 40 segundos
#include <iostream>
#include "Ponto2D.h"

using namespace std;

int main()
{
    Ponto2D p1(1, 1);
    Ponto2D p2(4, 4);

    cout << "Distancia entre (";
    p1.imprimeX();
    cout << ", ";
    p1.imprimeY();
    cout << ") e (";
    p2.imprimeX();
    cout << ", ";
    p2.imprimeY();
    cout << "): " << p1.distancia(p2) << endl;

    return 0;
}