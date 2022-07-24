#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = NULL;
    fim = NULL;
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

NoArv *FilaEncad::getInicio()
{
    if (inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::enfileira(NoArv *val)
{
    No *novo = new No;
    novo->setInfo(val);
    if (fim == NULL)
        inicio = novo;
    else
        fim->setProx(novo);
    fim = novo;
}

NoArv *FilaEncad::desenfileira()
{
    NoArv *info;
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
    }
    return info;
}