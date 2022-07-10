#include <iostream>
#include "Vertice.h"

using namespace std;

Vertice::Vertice()
{
    x = 0;
    y = 0;
    ant = NULL;
    prox = NULL;
}

Vertice::~Vertice()
{
    x = 0;
    y = 0;
    ant = NULL;
    prox = NULL;
}

int Vertice::getX()
{
    return x;
}

int Vertice::getY()
{
    return y;
}

Vertice *Vertice::getAnt()
{
    return ant;
}

Vertice *Vertice::getProx()
{
    return prox;
}

void Vertice::setX(int val)
{
    x = val;
}

void Vertice::setY(int val)
{
    y = val;
}

void Vertice::setAnt(Vertice *p)
{
    ant = p;
}

void Vertice::setProx(Vertice *p)
{
    prox = p;
}