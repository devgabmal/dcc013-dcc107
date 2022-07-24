#include <iostream>
#include "ArvBin.h"

using namespace std;

ArvBin *criaArvCheia()
{
    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *esqP = new ArvBin;
    ArvBin *dirP = new ArvBin;

    esq->cria(16, new ArvBin, new ArvBin);
    dir->cria(19, new ArvBin, new ArvBin);
    esqP->cria(18, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(38, new ArvBin, new ArvBin);
    dir->cria(14, new ArvBin, new ArvBin);
    dirP->cria(25, esq, dir);

    arv->cria(10, esqP, dirP);

    return arv;
}

ArvBin *criaArvCompleta()
{

    ArvBin *arv = new ArvBin;
    ArvBin *esq = new ArvBin;
    ArvBin *dir = new ArvBin;
    ArvBin *arve2 = new ArvBin;
    ArvBin *arvd2 = new ArvBin;
    ArvBin *arve3 = new ArvBin;
    ArvBin *arvd3 = new ArvBin;

    arve3->cria(24, new ArvBin, new ArvBin);
    arvd3->cria(12, new ArvBin, new ArvBin);

    esq->cria(16, new ArvBin, new ArvBin);
    dir->cria(19, new ArvBin, new ArvBin);
    arve2->cria(18, esq, dir);

    esq = new ArvBin;
    dir = new ArvBin;
    esq->cria(38, arve3, arvd3);
    dir->cria(14, new ArvBin, new ArvBin);
    arvd2->cria(25, esq, dir);

    arv->cria(10, arve2, arvd2);

    return arv;
}

int main()
{
    ArvBin *arvCheia = criaArvCheia();
    ArvBin *arvCompleta = criaArvCompleta();
    ArvBin *arvVazia = new ArvBin;
    ArvBin *arv1No = new ArvBin;
    ArvBin *arv1Folha = new ArvBin;
    ArvBin *arv1NoAux = new ArvBin;
    arv1No->cria(13, new ArvBin, new ArvBin);
    arv1NoAux->cria(17, new ArvBin, new ArvBin);
    arv1Folha->cria(9, arv1NoAux, new ArvBin);

    // 10 18 16 NULL NULL 19 NULL NULL 25 38 NULL NULL 14 NULL NULL
    // arvCheia->montaArvore();

    // arvCheia->preOrdem();
    // cout << endl;

    // Ex01
    // cout << "Vazia: " << arvVazia->nNos() << endl;
    // cout << "1 no: " << arv1No->nNos() << endl;
    // cout << "1 folha: " << arv1Folha->nNos() << endl;
    // cout << "Completa: " << arvCompleta->nNos() << endl;
    // cout << "Cheia: " << arvCheia->nNos() << endl;
    // cout << endl;

    // Ex02
    // cout << "Vazia: " << arvVazia->nFolhas() << endl;
    // cout << "1 no: " << arv1No->nFolhas() << endl;
    // cout << "1 folha: " << arv1Folha->nFolhas() << endl;
    // cout << "Completa: " << arvCompleta->nFolhas() << endl;
    // cout << "Cheia: " << arvCheia->nFolhas() << endl;
    // cout << endl;

    // Ex03
    // cout << "Vazia: " << boolalpha << arvVazia->ehCheia() << endl;
    // cout << "1 no: " << boolalpha << arv1No->ehCheia() << endl;
    // cout << "1 folha: " << boolalpha << arv1Folha->ehCheia() << endl;
    // cout << "Completa: " << boolalpha << arvCompleta->ehCheia() << endl;
    // cout << "Cheia: " << boolalpha << arvCheia->ehCheia() << endl;
    // cout << endl;

    // Ex04
    // arvVazia->preOrdem();
    // cout << endl;
    // arv1No->preOrdem();
    // cout << endl;
    // arv1Folha->preOrdem();
    // cout << endl;
    // arvCompleta->preOrdem();
    // cout << endl;
    // arvCheia->preOrdem();
    // cout << endl;
    // arvVazia->removeFolhas();
    // arv1No->removeFolhas();
    // arv1Folha->removeFolhas();
    // arvCompleta->removeFolhas();
    // arvCheia->removeFolhas();
    // cout << endl;
    // arvVazia->preOrdem();
    // cout << endl;
    // arv1No->preOrdem();
    // cout << endl;
    // arv1Folha->preOrdem();
    // cout << endl;
    // arvCompleta->preOrdem();
    // cout << endl;
    // arvCheia->preOrdem();
    // cout << endl;

    return 0;
}