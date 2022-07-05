#include <iostream>
#include <cmath>
#include "Ponto2D.h"

using namespace std;

Ponto2D::Ponto2D(float xp, float yp)
{
    x = xp;
    y = yp;
}

Ponto2D::~Ponto2D() {}

float Ponto2D::getX()
{
    return x;
}

float Ponto2D::getY()
{
    return y;
}

void Ponto2D::imprimeX()
{
    cout << "X = " << x;
}

void Ponto2D::imprimeY()
{
    cout << "Y = " << y;
}

float Ponto2D::distancia(Ponto2D pontoFim)
{
    float xF, yF;
    xF = pontoFim.getX();
    yF = pontoFim.getY();

    return sqrt(powf(xF - x, 2) + powf(yF - y, 2));
}