#include <bits/stdc++.h>
using namespace std;

int main()
{
    //write your code

    long long int n, min = INT32_MAX, max = INT32_MIN, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
    }
    cout << max - min;
}