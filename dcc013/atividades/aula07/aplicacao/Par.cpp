#include <iostream>
#include "Par.h"

using namespace std;

Par::Par()
{
    coef = 0;
    ord = 0;
    prox = NULL;
}

Par::~Par()
{
    coef = 0;
    ord = 0;
    prox = NULL;
}

int Par::getCoef()
{
    return coef;
}

int Par::getOrd()
{
    return ord;
}

Par *Par::getProx()
{
    return prox;
}

void Par::setCoef(int val)
{
    coef = val;
}

void Par::setOrd(int val)
{
    ord = val;
}

void Par::setProx(Par *p)
{
    prox = p;
}