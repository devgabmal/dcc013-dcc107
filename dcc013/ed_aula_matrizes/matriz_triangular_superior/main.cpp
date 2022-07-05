#include <iostream>
#include "MatrizTriSup.h"

#define NUM 7

using namespace std;

int main()
{
    MatrizTriSup mat(NUM);
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            if (j >= i)
            {
                mat.set(i, j, i * j + 1);
            }
        }
    }

    // mat.get(-5, 0);
    // mat.get(0, NUM);
    // mat.set(4, 2, 9);
    // mat.set(1, 3, 0);

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