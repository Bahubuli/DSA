// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        // code here
        int start = 0;
        int end = n - 1;
        int mid;
        if (arr[start] <= arr[end])
            return 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= arr[mid + 1] && arr[mid] < arr[mid - 1])
            {
                cout << "mid = " << arr[mid] << " mid-1 = " << arr[mid - 1] << " mid+1 = " << arr[mid + 1]<<endl;
                return mid;
            }
            else if (arr[mid] >= arr[start])
            {
                cout << "mid = " << arr[mid] << " mid-1 = " << arr[mid - 1] << " mid+1 = " << arr[mid + 1] << endl;
                start = mid ;
            }
            else if (arr[mid] < arr[start])
            {
                cout << "mid = " << arr[mid] << " mid-1 = " << arr[mid - 1] << " mid+1 = " << arr[mid + 1]<<endl;
                end = mid;
            }
            }
    }
};

// { Driver Code Starts.

int main()
{


        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";

    return 0;
}
// } Driver Code Ends
