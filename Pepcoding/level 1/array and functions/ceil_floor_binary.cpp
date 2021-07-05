#include <iostream>
using namespace std;

void brokeneco(long long int *arr, int n, int d)
{
    long long int l = 0, h = n - 1, mid;
    while (l < h - 1)
    {

        mid = (l + h) / 2;
        if (arr[mid] > d)
        {
            h = mid;
        }

        else if (arr[mid] < d)
        {
            l = mid;
        }

        else
        {
            cout << arr[mid] << "\n"
                 << arr[mid];
            return;
        }
    }

    cout << arr[h] << "\n"
         << arr[l];
}

int main()
{
    long long int n;
    cin >> n;
    long long int *arr = new long long int[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int data;
    cin >> data;
    brokeneco(arr, n, data);

    // write your code here
}