#include <iostream>
#include "MatrizFlex.h"

using namespace std;

int main()
{
    int lil = -2, lfl = 7;
    int lic = 0, lfc = 5;
    MatrizFlex mat(lil, lfl, lic, lfc);
    // atribui valores a matriz mat
    for (int i = lil; i <= lfl; i++)
        for (int j = lic; j <= lfc; j++)
        {
            float val = (lfc - lic + 1) * (i - lil) + j - lic; // 0...(n*m-1)
            mat.set(i, j, val);
        }
    // imprime a matriz mat
    for (int i = lil; i <= lfl; i++)
    {
        for (int j = lic; j <= lfc; j++)
        {
            float val = mat.get(i, j);
            cout << val << "\t";
        }
        cout << endl;
    }
    return 0;
}