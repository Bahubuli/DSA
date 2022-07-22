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
        vector<vector<int>>prev(3,vector<int>(3,0)),curr(3,vector<int>(3,0));
        
        
        for(int day=n-1;day>=0;day--)
        {
            for(int buy=0;buy<2;buy++)
            {
                
                for(int cap=0;cap<=2;cap++)
                {
                    if(buy && cap)
                    {
                        int pick = -prices[day]+ prev[0][cap];
                        int npick = prev[1][cap]; 
                        curr[buy][cap]= max(pick,npick);
                    }
                    else if(cap)
                    {
                        int pick = prices[day]+ prev[1][cap-1];
                        int npick = prev[0][cap];
                        curr[buy][cap] = max(pick,npick);
                    }
                    
                }
                
            }
            
            prev = curr;
        }
        
        return curr[1][2];
        
    }
};