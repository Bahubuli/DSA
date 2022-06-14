class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(size(nums)==1) return nums[0];
        int prev= max(nums[0],nums[1]), pprev  =nums[0];
        int ans = prev;
        for(int i=2;i<size(nums);i++)
        {
            ans = max(nums[i]+pprev,prev);
            
            pprev = prev;
            prev = ans;
        }
        return ans;
    }
};