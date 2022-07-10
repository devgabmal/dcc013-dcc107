#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = NULL;
    fim = NULL;
    numNos = 0;
}

FilaEncad::~FilaEncad()
{
    No *p = inicio;
    while (inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
}

bool FilaEncad::vazia()
{
    return (inicio == NULL);
}

int FilaEncad::getInicio()
{
    if (inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::enfileira(int val)
{
    No *novo = new No;
    novo->setInfo(val);
    if (fim == NULL)
        inicio = novo;
    else
        fim->setProx(novo);
    fim = novo;
    numNos++;
}

int FilaEncad::desenfileira()
{
    int info = 0;
    if (inicio == NULL)
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
    else
    {
        No *p = inicio;
        info = p->getInfo();
        inicio = p->getProx();
        if (inicio == NULL)
            fim = NULL;
        delete p;
        numNos--;
    }
    return info;
}

int FilaEncad::getNumNos()
{
    return numNos;
}