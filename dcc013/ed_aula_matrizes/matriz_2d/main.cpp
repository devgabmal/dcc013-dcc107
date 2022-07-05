#include <iostream>
#include "Matriz2D.h"

using namespace std;

int main()
{
    Matriz2D mat(5, 5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            float val;
            cin >> val;
            mat.set(i, j, val);
        }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << mat.get(i, 3) << endl;
    }
    // etc ...
    return 0;
}