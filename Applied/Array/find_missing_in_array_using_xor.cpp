#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[], int n)
{
    int x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++)
        x1 = x1 ^ arr[i];

    for (int i = 1; i <= n + 1; i++)
        x2 = x2 ^ i;

    return x1 ^ x2;
}
int main()
{
    int arr[] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << " the missing number is: " << findMissing(arr, n);
}
