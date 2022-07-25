class Solution {
public:
    
    int helper(vector<int>&nums,int i,int pi,  vector<int>&dp)
    {
        int n = nums.size(),pick=0,npick=0;
        if(i==n) return 0;
        
        if(dp[pi+1]!=-1) return dp[pi+1];
        
        if(pi==-1 || nums[pi]<nums[i]) pick = 1+helper(nums,i+1,i,dp);
        npick = helper(nums,i+1,pi,dp);
        
        return dp[pi+1] =  max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(),ans=1;
        vector<int>dp(n+1,1);
        
        for(int i=0;i<n;i++)
        {
            for(int pi=0;pi<i;pi++)
            {
                if(nums[i]>nums[pi])
                {
                    dp[i] = max(dp[i],dp[pi]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        
        return ans;
        
    }
};