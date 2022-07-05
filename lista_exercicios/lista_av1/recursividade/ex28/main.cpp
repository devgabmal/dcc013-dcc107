// 1 hora, 6 minutos e 20 segundos
#include <iostream>

using namespace std;

bool ehPalindromoIter(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = tolower(a[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool ehPalindromoRec(char a[], int tam, int ind)
{
    // Natan 5/2 = 2
    // Kaak 4/2 = 2

    if (tam - ind <= tam / 2)
        return true;

    if (tolower(a[ind]) != tolower(a[tam - ind - 1]))
        return false;
    else
        return ehPalindromoRec(a, tam, ind + 1);
}

bool ehPalindromo(char a[], int n)
{
    if (n == 1)
        return true;
    else if (n < 1)
        return false;
    else
        return ehPalindromoRec(a, n, 0);
}

int main()
{
    int n;
    string str;
    char *car;
    bool ehPal;

    cout << "Texto: ";
    cin >> str;

    n = str.length();

    car = new char[n];

    for (int i = 0; i < n; i++)
    {
        car[i] = str[i];
    }

    ehPal = ehPalindromo(car, n);

    if (ehPal)
        cout << str << ": eh palindromo";
    else
        cout << str << ": nao eh palindromo";

    return 0;
}