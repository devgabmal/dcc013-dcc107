#include <iostream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

NoArv *ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "ERRO: Arvora vazia!" << endl;
        exit(1);
    }
}

bool ArvBin::vazia() { return raiz == NULL; }

void ArvBin::cria(int val, ArvBin *sae, ArvBin *sad)
{
    NoArv *novo = new NoArv();
    novo->setInfo(val);
    novo->setEsq(sae->raiz);
    novo->setDir(sad->raiz);
    raiz = novo;
}

void ArvBin::auxImprime(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}
void ArvBin::imprime() { auxImprime(raiz); }

bool ArvBin::auxBusca(NoArv *p, int ch)
{
    if (p == NULL)
        return false;
    if (p->getInfo() == ch)
        return true;
    if (auxBusca(p->getEsq(), ch))
        return true;
    else
        return (auxBusca(p->getDir(), ch));
}
bool ArvBin::busca(int val) { return auxBusca(raiz, val); }

int ArvBin::auxAltura(NoArv *p)
{
    int hEsq, hDir;
    if (p == NULL)
        return -1;

    hEsq = auxAltura(p->getEsq());
    hDir = auxAltura(p->getDir());

    return 1 + max(hEsq, hDir);
}
int ArvBin::altura() { return auxAltura(raiz); };