class Solution {
public:
    
    int helper(vector<int>&nums,int i,int pi,vector<vector<int>>&dp)
    {
        int n = nums.size(),pick=0,npick=0;
        if(i==n) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        
        if(pi==-1 || nums[pi]<nums[i]) pick = 1+helper(nums,i+1,i,dp);
        npick = helper(nums,i+1,pi,dp);
        
        return dp[i][pi+1] =  max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        
       
        
        for(int i=n-1;i>=0;i--)
        {
            
            for(int pi=i-1;pi>=-1;pi--)
            {
                int pick=0,npick=0;
                npick = dp[i+1][pi+1];
                
                if(pi==-1 || nums[pi]<nums[i])
                    pick = 1+dp[i+1][i+1];
                    
                dp[i][pi+1] = max(pick,npick);
            }
        }
        
        
        
        return dp[0][0];
        
    }
};