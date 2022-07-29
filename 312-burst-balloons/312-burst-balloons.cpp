class Solution {
public:
    
    int helper(vector<int>&nums,int i,int j, vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = -1e6;
        for(int k=i;k<=j;k++)
        {
            res = max(res,nums[i-1]*nums[k]*nums[j+1]+helper(nums,i,k-1,dp)+helper(nums,k+1,j,dp));
        }
        return dp[i][j] =  res;
    }
    
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n+3,vector<int>(n+3,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<i) continue;
                int res = -1e6;
                for(int k=i;k<=j;k++)
                {
                    res = max(res,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] =  res;
                
            }
        }
        
        
        return dp[1][n];
        
    }
};