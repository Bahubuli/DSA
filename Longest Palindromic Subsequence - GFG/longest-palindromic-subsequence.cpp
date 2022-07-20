// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    int lcs(string s,string t)
    {
        int n = s.size(), m = t.size();
        vector<int>curr(m,0),prev(m,0);
        
        for(int k=0;k<m;k++)
        if(s[0]==t[k]) prev[k] = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int match = s[i]==t[j];
                if(match && i>0 && j>0) match+=prev[j-1];
                
                int nmatch = 0;
                if(i>0) nmatch = max(nmatch,prev[j]);
                if(j>0) nmatch = max(nmatch,curr[j-1]);
                
                curr[j] = max(match,nmatch);
            }
            prev = curr;
        }
        return curr[m-1];
    }
    
    int longestPalinSubseq(string s) 
    {
        string rs = s;
        reverse(rs.begin(),rs.end());
        return lcs(s,rs);
        
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends