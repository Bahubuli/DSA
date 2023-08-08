class Solution {
public:
    
    int helper(int m,int n,vector<vector<int>>&dp)
    {
         if(n==1 && m==1) return 1;
        if(n<=0 || m<=0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int up = helper(m-1,n,dp);
        int left = helper(m,n-1,dp);
        
        return dp[m][n] = up+left;
    }
    
    int uniquePaths(int m, int n) 
    {
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m,n,dp);
    }
};