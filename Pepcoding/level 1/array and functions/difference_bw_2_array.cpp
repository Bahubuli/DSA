#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, max, c = 0, m1, m2;
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
        m1 = a1[n1];
        m2 = a2[n2];
        if (m1 > m2)
        {
            m2 = m2 + 10;
            a2[n2 - 1] = a2[n2 - 1] - 1;
        }
        a3[i] = m2 - m1;

        n1--;

        n2--;
    }
    int flag = 0;

    for (int i = 0; i < max; i++)
    {
        if (flag == 0 && a3[i] == 0)
        {
            continue;
        }
        else
            flag = 1;
        cout << a3[i] << endl;
    }
}