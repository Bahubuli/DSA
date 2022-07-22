class Solution {
public:
    
    int helper(vector<int>&prices,int i,int buy,int count,int dp[100001][3][3])
    {
        int n = prices.size();
        if(i==n || count==0) return 0;
        
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        
        if(buy && count)
        {
            int pick = -prices[i]+helper(prices,i+1,0,count,dp);
            int npick = helper(prices,i+1,1,count,dp);
            return dp[i][buy][count]= max(pick,npick);
        }
        else if(count)
        {
            int pick = prices[i]+helper(prices,i+1,1,count-1,dp);
            int npick = helper(prices,i+1,0,count,dp);
            return dp[i][buy][count] = max(pick,npick);
        }
        return dp[i][buy][count] =0;
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int dp[n][3][3];
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,1,2,dp);
        
    }
};