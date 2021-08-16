
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Complete this function
void eqPoint(int arr[], int n)
{
    //Your code here
    int lm = 1;
    int rm = 1;

    double idx;

    for (int i = 0; i < n - 1; i++)
    {
        lm = lm * arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rm = rm * arr[j];
        }
        if (lm == rm)
        {
            idx = i;
            break;
        }
        else
        {
            rm = 1;
        }
    }
    double par = (idx + 1) + (idx + 2) / 10;
    cout << par << endl;
}

// { Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i]; //0 is not allowed in the array
        }

        eqPoint(arr, n);
    //}
}
// } Driver Code Ends
