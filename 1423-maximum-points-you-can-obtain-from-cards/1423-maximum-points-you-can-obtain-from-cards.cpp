class Solution {
public:
    int maxScore(vector<int>& nums, int k)
    {
        int ans =0,sum=0,n = nums.size();
        for(int i =0;i<k;i++) sum+=nums[i];
        ans = max(ans,sum);
        
        int i =k-1;
        int j= n-1;
        
        while(i>=0)
        {
            sum-=nums[i];
            sum+=nums[j];
            ans = max(ans,sum);
            i--;
            j--;
        }
        return ans;
        
    }
};