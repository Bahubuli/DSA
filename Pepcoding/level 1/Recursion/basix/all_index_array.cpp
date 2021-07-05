#include <iostream>
using namespace std;


void allindex(int *arr, int idx, int n, int *output, int i, int fsf, int x)
{
    if (idx == n)
        return;
    if (arr[idx] == x)
    {
        output[i] = idx;
        i++;
    }
    allindex(arr, idx + 1, n, output, i, fsf, x);
}



int main()
{
    int n, fsf = 0;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == d)
            fsf++;
    }
    int *output = new int[fsf];

    allindex(arr, 0, n, output, 0, fsf, d);

    for (int i = 0; i < fsf; i++)
        cout << output[i];
}
