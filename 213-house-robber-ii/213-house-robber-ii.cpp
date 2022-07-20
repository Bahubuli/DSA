class Solution {
public:
    
    int robb(vector<int>&nums)
    {
       
        
        int one = nums[0],two = max(nums[0],nums[1]), tree = two;
        
        for(int i=2;i<nums.size();i++)
        {
            tree = max(nums[i]+one,two);
            one = two;
            two = tree;
        }
        
        return tree;
    }
    
    int rob(vector<int>& nums) 
    {
         if(nums.size()==1) return nums[0];
        int n = nums.size();
        int f = nums[0];
        nums[0] = 0;
        int res1 = robb(nums);
        nums[0] = f;
        f= nums[n-1];
        nums[n-1] = 0;
        int res2 = robb(nums);
        
        return max(res2,res1);
        
    }
};