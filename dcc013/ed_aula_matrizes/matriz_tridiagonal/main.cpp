#include <iostream>
#include "MatrizTridiag.h"

#define NUM 7

using namespace std;

int main()
{
    MatrizTridiag mat(NUM);
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            if ((j + 1 >= i && i >= j - 1))
            {
                // Gera números aleatórios entre 0 e 99
                float r2 = static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 99));
                mat.set(i, j, r2);
            }
        }
    }

    // mat.get(-5, 0);
    // mat.get(0, NUM);
    // mat.set(1, 3, 100);
    // mat.set(5, 2, 100);
    mat.set(2, 2, 100);
    mat.set(5, 6, 200);
    mat.set(1, 0, 300);

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