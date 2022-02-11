#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, max, c = 0;
    cin >> n1;
    long long int s = 0;
    int *a1 = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }

    cin >> n2;
    int *a2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }
    if (n1 > n2)
        max = n1;
    else
        max = n2;

    int *a3 = new int(max);
    n1--;
    n2--;
    for (int i = max - 1; i >= 0; i--)
    {
        if (n1 < 0)
        {
            n1 = 0;
            a1[n1] = 0;
        }
        if (n2 < 0)
        {
            n2 = 0;
            a2[n2] = 0;
        }
        //no need of this if else
        if (a1[n1] + a2[n2] + c < 10)
        {
            a3[i] = a1[n1] + a2[n2] + c;
            c = 0;
        }
        else
        {
            a3[i] = (a1[n1] + a2[n2] + c) % 10;
            c = 1;
        }
        n1--;
        n2--;
    }
    if (c > 0)
        cout << c << endl;
    for (int i = 0; i < max; i++)
        cout << a3[i] << endl;
}