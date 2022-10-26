// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:

     long long trappingWater(int arr[], int n){
            // code here
            if (n <= 1) return 0;
    int lmarr[n];
    lmarr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmarr[i] = max(lmarr[i - 1], arr[i]);
    }

    int rmarr[n];
    rmarr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmarr[i] = max(rmarr[i + 1], arr[i]);
    }

    long long totalw = 0;
    for (int i = 0; i < n; i++)
    {
        totalw = totalw + max(0, (min(lmarr[i], rmarr[i]) - arr[i]));
    }
    return totalw;
}
}
;


// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends
