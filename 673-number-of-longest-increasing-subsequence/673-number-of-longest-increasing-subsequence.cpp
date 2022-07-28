class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int mx = 1;
        vector<int>dp(n,1),count(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i])
                {
                    count[i]+=count[j];  
                }
            }
            mx = max(mx,dp[i]);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==mx) ans+=count[i];
        }
        return ans;
    }
};