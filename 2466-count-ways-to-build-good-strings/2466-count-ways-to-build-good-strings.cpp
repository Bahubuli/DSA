class Solution {
public:
    
    int mod = 1e9+7;
    
    int helper(int high,int zero,int one,vector<int>&dp)
    {
        if(high<0) return 0;
        if(high==0) return 1;
        
        if(dp[high]!=-1) return dp[high];
        
        return dp[high] = (helper(high-zero,zero,one,dp)%mod + helper(high-one,zero,one,dp)%mod)%mod;
        
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int>dp(high+1,-1);
        
        helper(high,zero,one,dp);
        
        long long int ans = 0;
        
        for(int i=low;i<=high;i++)
        {   
            ans = ans+helper(i,zero,one,dp);   
        }
        
        return ans%mod;
        
    }
};