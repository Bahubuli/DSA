class Solution {
public:
    
    int helper(vector<int>&prices,int i,int buy,vector<vector<int>>&dp)
    {
        int n = prices.size(),pick=0,npick=0;
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            pick = -prices[i]+helper(prices,i+1,0,dp);
            npick = helper(prices,i+1,1,dp);
        }
        else
        {
            pick = prices[i]+helper(prices,i+2,1,dp);
            npick = helper(prices,i+1,0,dp);
        }
        return dp[i][buy] =  max(pick,npick);
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(prices,0,1,dp);
        
    }
};