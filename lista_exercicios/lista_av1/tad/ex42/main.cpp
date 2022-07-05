// 23 minutos e 10 segundos
#include <iostream>
#include "Ponto2D.h"

using namespace std;

Ponto2D *centroGeometrico(Ponto2D *v, int n)
{
    float xC, yC, somaX, somaY;
    Ponto2D *pC;

    somaX = somaY = 0;

    for (int i = 0; i < n; i++)
    {
        somaX += v[i].getX();
        somaY += v[i].getY();
    }

    xC = somaX / n;
    yC = somaY / n;

    pC = new Ponto2D(xC, yC);

    return pC;
}

int main()
{
    int n;
    Ponto2D *vetPontos;

    n = 3;

    Ponto2D p1(1, 1);
    Ponto2D p2(4, 4);
    Ponto2D p3(9.5, -2);

    vetPontos = new Ponto2D[n];

    vetPontos[0] = p1;
    vetPontos[1] = p2;
    vetPontos[2] = p3;

    Ponto2D *pC = centroGeometrico(vetPontos, 3);

    cout << "Distancia entre (" << p1.getX() << ", " << p1.getY() << ") e ("
         << p2.getX() << ", " << p2.getY() << "): " << p1.distancia(p2) << endl;

    cout << "Centro Geometrico: (" << pC->getX() << ", " << pC->getY() << ")" << endl;

    delete[] vetPontos;
    delete pC;

    return 0;
}