#include <iostream>
using namespace std;

void brokeneco(long long int *arr, int n, int d)
{
    long long int l = 0, h = n - 1, mid;
    while (l <= h)
    {

        mid = (l + h) / 2;
        if (arr[mid] > d)
        {
            h = mid - 1;
        }

        else if (arr[mid] < d)
        {
            l = mid + 1;
        }

        else
        {
            l = mid, h = mid;
            while (arr[l] == d || arr[h] == d)
            {
                if (arr[l] == d && l >= 0)
                    l--;
                if (arr[h] == d && h < n)
                    h++;
            }
            cout << l + 1 << "\n"
                 << h - 1;
            return;
        }
    }
    cout << -1 << "\n"
         << -1;
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