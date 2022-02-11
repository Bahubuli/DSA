#include <iostream>
using namespace std;

int main()
{
    //write your code here
    long long int n, idx = -1, max = INT32_MIN;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= i)
            {
                cout << "*\t";
            }
            else
                cout << "\t";
        }
        cout << "\n";
    }
}