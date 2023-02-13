class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int currmx = nums[0],leftmx = nums[0];
        int ans = 0,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            currmx = max(currmx,nums[i]);
            if(nums[i]<leftmx)
            {
                leftmx = currmx;
                ans = i;
            }
        }
        return ans+1;
    }
};