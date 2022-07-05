#include <iostream>

using namespace std;

int fatorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main()
{
    int num, fat;
    cout << "Digite um número natural: ";
    cin >> num;
    fat = fatorial(num);
    cout << num << "! = " << fat << endl;
    return 0;
}
