

#include <bits/stdc++.h>
using namespace std;

void printsubset(int *arr, int n)
{
    int l = pow(2, n), temp, m;

    for (int i = 0; i < l; i++)
    {
        m = i;
        string s = "";

        for (int j = 0; j < n; j++)
        {
            temp = m % 2;
            m = m / 2;
            if (temp == 0)
                s = "-" + s;

            else
                s = to_string(1) + s;
        }
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '-')
                cout << "-\t";
            else
                cout << arr[j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printsubset(arr, n);

    // write your code here
}