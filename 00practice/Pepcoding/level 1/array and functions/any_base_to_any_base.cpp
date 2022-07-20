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

int decimaltoanybase(int n, int b)
{
    int bn = 0, count = 0;
    while (n > 0)
    {
        bn = bn * 10 + n % b;
        if (bn == 0 && n % b == 0)
            count++;

        n = n / b;
    }
    return reversenum(bn, count);
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
    int n, b1, b2;
    cout << decimaltoanybase(anybasetodecimal(101110, 2), 8);
}
