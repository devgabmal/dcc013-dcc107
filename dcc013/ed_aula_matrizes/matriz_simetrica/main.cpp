#include <iostream>
#include "MatrizSim.h"

#define NUM 7

using namespace std;

int main()
{
    MatrizSim mat(NUM);
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            // Gera números aleatórios entre 0 e 99
            float r2 = static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 99));
            if (j >= i)
                mat.set(i, j, r2);
        }
    }

    // mat.get(-5, 0);
    // mat.get(0, NUM);
    mat.set(2, 2, 100);
    mat.set(4, 1, 200);
    mat.set(3, 4, 300);

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