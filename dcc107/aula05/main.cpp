#include <iostream>
#include "MatrizLin.h"

#define NUM 4

using namespace std;

bool ehSimetrica(float matriz[NUM][NUM], int nl, int nc)
{
    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (l != c)
            {
                if (matriz[l][c] != matriz[c][l])
                    return false;
            }
        }
    }
    return true;
}

float maior(float matriz[NUM][NUM], int nl, int nc)
{
    float mai = matriz[0][0];
    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (matriz[l][c] > mai)
                mai = matriz[l][c];
        }
    }
    return mai;
}

float *prodMatVetor(MatrizLin *m, float *v)
{
    float resLin;

    int numLin = m->getNl();
    int numCol = m->getNc();

    float *vetor = new float[numLin];

    for (int l = 0; l < numLin; l++)
    {
        resLin = 0;
        for (int c = 0; c < numCol; c++)
        {
            resLin = resLin + m->get(l, c) * v[c];
        }
        vetor[l] = resLin;
    }

    return vetor;
}

int main()
{
    int m = NUM + 1, n = NUM;
    MatrizLin mat(m, n);
    MatrizLin *matT;
    float vet[NUM + 1] = {2, 3, 4, 5};
    float *vetM;

    // float matQuad[NUM][NUM] = {{2, -3, 5}, {-3, 0, 7}, {5, 7, 1}};
    // float matQuad[NUM][NUM] = {{2, 9, 5}, {-3, 0, 4}, {2, 7, 1}};

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            float val = j + n * i; /// sequencia numerica no intervalo 0..(m*n-1)
            mat.set(i, j, val);
        }

    /*
        for (int i = 0; i < NUM; i++)
            for (int j = 0; j < NUM; j++)
            {
                matQuad[i][j] = 1 + i + j;
            }
    */

    /*
        for (int i = 0; i < NUM; i++)
        {
            for (int j = 0; j < NUM; j++)
            {
                cout << matQuad[i][j] << "\t";
            }
            cout << endl;
        }
    */
    mat.imprime();

    /*
        cout << boolalpha << ehSimetrica(matQuad, NUM, NUM) << endl;
        cout << "Maior: " << maior(matQuad, NUM, NUM) << endl;
        */

    // matT = mat.transposta();

    // matT->imprime();

    vetM = prodMatVetor(&mat, vet);

    for (int i = 0; i < NUM + 1; i++)
    {
        cout << vetM[i] << endl;
    }

    return 0;
}
