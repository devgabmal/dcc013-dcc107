#include <iostream>
#include "No.h"

using namespace std;

No::No()
{
    info = 0;
    prox = NULL;
}

No::~No()
{
    info = 0;
    prox = NULL;
}

int No::getInfo()
{
    return info;
}

No *No::getProx()
{
    return prox;
}

void No::setInfo(int val)
{
    info = val;
}

void No::setProx(No *p)
{
    prox = p;
}