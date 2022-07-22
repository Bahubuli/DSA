class Solution {
public:
    
    
    int maxProfit(int t, vector<int>& prices) 
    {
        
        int n = prices.size();
        vector<vector<int>>prev(3,vector<int>(t+1,0)),curr(3,vector<int>(t+1,0));


        for(int day=n-1;day>=0;day--)
        {
            for(int buy=0;buy<2;buy++)
            {

                for(int cap=0;cap<=t;cap++)
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

        return curr[1][t];
    }
};