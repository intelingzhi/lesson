#include <iostream>

using namespace std;

int fun(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (fun(n - 1) * n);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    int b = fun(a);
    cout << b << endl;
    return 0;
}