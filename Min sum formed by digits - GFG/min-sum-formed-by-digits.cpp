// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long int a=0,b=0;
        
        int i=0,j=1;
        
        while(i<n && j<n)
        {
            a = a*10+arr[i];
            i+=2;
            b= b*10+arr[j];
            j+=2;
        }
        if(i<n) a = a*10+arr[i];
        if(j<n) b = b*10+arr[j];
        
        return a+b;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends