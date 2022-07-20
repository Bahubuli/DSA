// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string s;
        int l = INT_MAX;
        
        for(int i=0;i<N;i++)
        {
            if(arr[i].size()<l)
            {
                l = arr[i].size();
                s = arr[i];
            }
        }
        
        int m = s.size();
        
        for(int i=0;i<N;i++)
        {
            int c=0;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==s[j])
                {
                    c++;
                    
                }
                else break;
            }
            m = c;
        }
        string ans =  s.substr(0,m);
        return ans.size() ? ans : "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends