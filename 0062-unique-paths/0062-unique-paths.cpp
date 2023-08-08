class Solution {
public:
    
    int helper(int m,int n,vector<vector<int>>&dp)
    {
        if(m<=0 || n<=0) return 0;
        
        if(n==1 && m==1) return 1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int top = helper(m-1,n,dp);
        int left = helper(m,n-1,dp);
        
        return dp[n][m] = top+left;
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return helper(m,n,dp);
        
    }
};