#include <iostream>
#include "ListaCont2.h"

using namespace std;

int main()
{
    ListaCont2 l(2, 10);

    l.insereFinal(30);
    l.insereFinal(23);
    l.insereFinal(98);
    l.insereFinal(47);
    l.insereFinal(-25);
    /*
    l.insereFinal(1);
    l.insereFinal(2);
    l.insereFinal(3);
    */

    // l.removeInicio();
    // l.removeFinal();
    l.insereInicio(-1);
    l.insereInicio(-2);
    // l.insereInicio(-3);
    //  l.insereInicio(4);
    //  l.insereK(6, 87);
    //  l.insereInicio(-1);
    //  l.insereInicio(4);
    l.removeK(2);

    l.imprime();
    return 0;
}