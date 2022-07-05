#include <iostream>
#include "MatrizDiag.h"

#define NUM 7

using namespace std;

int main()
{
    MatrizDiag mat(NUM);
    for (int i = 0; i < NUM; i++)
    {
        mat.set(i, i, i);
    }

    // mat.get(-5, 0);
    // mat.get(0, NUM);
    // mat.set(1, 2, 9);
    // mat.set(2, 4, 0);

    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            cout << mat.get(i, j) << "\t";
        }
        cout << endl;
    }

    return 0;
}