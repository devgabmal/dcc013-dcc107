#include <iostream>
#include "ArvBin.h"

using namespace std;

// ArvBin *criaArvoreVazia(){
//     ArvBin *nova = new ArvBin();
//     nova->cria
// }

int main()
{
    ArvBin *arv = new ArvBin;
    // 10 18 16 NULL NULL 19 NULL NULL 25 38 NULL NULL 14 NULL NULL
    arv->montaArvore();
    // ArvBin *esq = new ArvBin;
    // ArvBin *dir = new ArvBin;
    // ArvBin *esqP = new ArvBin;
    // ArvBin *dirP = new ArvBin;

    // esq->cria(16, new ArvBin, new ArvBin);
    // dir->cria(19, new ArvBin, new ArvBin);
    // esqP->cria(18, esq, dir);

    // esq = new ArvBin;
    // dir = new ArvBin;
    // esq->cria(38, new ArvBin, new ArvBin);
    // dir->cria(14, new ArvBin, new ArvBin);
    // dirP->cria(25, esq, dir);

    // arv->cria(10, esqP, dirP);

    arv->preOrdem();
    cout << endl;
    // cout << arv->busca(7) << endl;
    // cout << arv->altura() << endl;
    arv->percursoLargura();

    return 0;
}