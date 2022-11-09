class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int i;
        
        for(i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1]) break;
        
        if(i<0) reverse(nums.begin(),nums.end());
        else
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    swap(nums[j],nums[i]);
                    break;
                }
            }
            
            reverse(nums.begin()+1+i,nums.end());
        }
    }
};