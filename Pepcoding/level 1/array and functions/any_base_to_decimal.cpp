#include <bits/stdc++.h>
using namespace std;

int reversenum(int n, int count)
{
    int m = 0;
    while (n)
    {
        m = m * 10 + n % 10;
        n = n / 10;
    }
    return (m * pow(10, count));
}

int anybasetodecimal(int n, int b)
{
    int m = 0, i = 0;
    while (n)
    {
        m = m + (n % 10) * pow(b, i);
        n = n / 10;
        i++;
    }
    return m;
}

int main()
{
    cout << anybasetodecimal(100111, 2);
}
