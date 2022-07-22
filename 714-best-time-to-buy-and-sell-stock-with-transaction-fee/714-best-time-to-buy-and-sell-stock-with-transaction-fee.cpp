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
        vector<vector<int>>dp(n+1,vector<int>(2,0));
       
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int pick,npick;
                if(buy)
                {
                    pick = -fee-prices[i]+dp[i+1][0];
                    npick = dp[i+1][1];
                }
                else
                {
                    pick = prices[i]+dp[i+1][1];
                    npick =dp[i+1][0]; 
                }
                dp[i][buy] = max(pick,npick);
            }
        }
        
        return dp[0][1];
        
    }
};