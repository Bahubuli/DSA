class Solution {
public:
    
    int helper(int n,int &ans,vector<int>&dp)
    {
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        int res = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            res = min(res,1+helper(n-i*i,ans,dp));
        }
        return dp[n] = res;
    }
    
    int numSquares(int n) 
    {
        int ans = INT_MAX;
        vector<int>dp(n+1,-1);
        return helper(n,ans,dp);
        
    }
};