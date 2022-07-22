class Solution {
public:
    
    int helper(vector<int>&prices,int i,int buy,int fee,vector<vector<int>>&dp)
    {
        int n = prices.size(),pick,npick;
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        if(buy)
        {
            pick = -fee-prices[i]+helper(prices,i+1,0,fee,dp);
            npick = helper(prices,i+1,1,fee,dp);
        }
        else
        {
            pick = prices[i]+helper(prices,i+1,1,fee,dp);
            npick = helper(prices,i+1,buy,fee,dp);
        }
        
        return dp[i][buy] = max(pick,npick);
    }
    
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = size(prices);
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(prices,0,1,fee,dp);
        
    }
};