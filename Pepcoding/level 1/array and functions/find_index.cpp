#include <iostream>
using namespace std;

int main()
{
    //write your code here
    long long int n, idx = -1, x;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
            idx = i;
    }
    cout << idx;
}