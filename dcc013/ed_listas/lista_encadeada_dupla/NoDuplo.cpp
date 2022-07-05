#include <iostream>
#include "NoDuplo.h"

using namespace std;

NoDuplo::NoDuplo()
{
    info = 0;
    ant = NULL;
    prox = NULL;
}

NoDuplo::~NoDuplo()
{
    info = 0;
    ant = NULL;
    prox = NULL;
}

int NoDuplo::getInfo()
{
    return info;
}

NoDuplo *NoDuplo::getAnt()
{
    return ant;
}

NoDuplo *NoDuplo::getProx()
{
    return prox;
}

void NoDuplo::setInfo(int val)
{
    info = val;
}

void NoDuplo::setAnt(NoDuplo *p)
{
    ant = p;
}

void NoDuplo::setProx(NoDuplo *p)
{
    prox = p;
}