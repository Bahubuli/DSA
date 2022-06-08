class Solution {
public:
    int dp[46]= {0};
   
    int climbStairs(int n) 
    {
        if(n<0) return 0;
        if(n==0|| n==1)
        {
             dp[0] = 1;
                dp[1] = 1;
             return 1;
        }
       
        
        if(dp[n]!=0) return dp[n];
        dp[n] =  climbStairs(n-1)+climbStairs(n-2);
        
        return dp[n];
        
    }
};