class Solution {
public:
    
    int helper(vector<int>&values,int n,int i,bool buy,vector<vector<int>>&dp)
    {
    if(i==n) return 0;
    int pick,npick;
    if(dp[i][(int)buy]!=-1) return dp[i][(int)buy];
    if(buy)
    {
        pick = -values[i]+helper(values,n,i+1,!buy,dp);
        npick = helper(values,n,i+1,buy,dp);  
    }
    else
    {
        pick = values[i]+helper(values,n,i+1,!buy,dp);
        npick = helper(values,n,i+1,buy,dp);  
    }
    return dp[i][(int)buy] = max(pick,npick);
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size(),pick, npick;
        vector<int>prev(2,-1),curr(2,-1);
        
        prev[0] = 0;
        prev[1] = 0;
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                if(buy)
                {
                    pick = -prices[i]+prev[buy-1];
                    npick =prev[buy];
                }
                else
                {
                    pick = prices[i]+prev[buy+1];
                    npick = prev[buy];
                }
                
                curr[buy] = max(pick,npick);
            }
            prev = curr;
        }
        
        
        return curr[1];
        
    }
};