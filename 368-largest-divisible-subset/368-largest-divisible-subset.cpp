class Solution {
public:
    
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        
       int n = nums.size(),mxidx=0;
       vector<int>dp(n+1,1), hash(n+1,0);
     
        sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++) hash[i] = i;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
                if(dp[i]>dp[mxidx]) mxidx = i;
            }
        }
        
        //for(int i=0;i<n;i++) cout<<hash[i]<<" . ";
        vector<int>ans(dp[mxidx]);
        int k = mxidx;
        mxidx = dp[mxidx]-1;
        while(mxidx>=0)
        {
            //cout<<mxidx<<endl;
            ans[mxidx] = nums[k];
            k = hash[k];
            mxidx--;
        }
        return ans;
    }
};