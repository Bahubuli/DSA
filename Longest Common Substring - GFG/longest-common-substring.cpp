// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
   
    int helper(string &s1,string &s2,int i,int j,int &ans,vector<vector<int>>&dp)
    {
    if(i>=s1.size() || j>=s2.size()) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int match = (s1[i]==s2[j]);
    
    if(i+1<s1.size() && j+1<s2.size() && s1[i+1]==s2[j+1])
        match+=helper(s1,s2,i+1,j+1,ans,dp);
    
    int nmatch = max(helper(s1,s2,i+1,j,ans,dp),helper(s1,s2,i,j+1,ans,dp));
    ans = max(ans,nmatch);
    if(s1[i]==s2[j])
    {
        ans = max(ans,match);
         return dp[i][j] =  match;
    }
       
    return dp[i][j] = nmatch;
    }
   
   
   
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
    int ans = 0;
    
    vector<vector<int>>dp(n,vector<int>(m,-1));
	helper(s1,s2,0,0,ans,dp);
    return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends