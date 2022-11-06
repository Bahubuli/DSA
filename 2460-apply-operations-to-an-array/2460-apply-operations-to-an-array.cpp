class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n  = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i+1<n && nums[i]==nums[i+1])
            {
                nums[i]  = nums[i]*2;
                nums[i+1]=0;
            }
        }
        
        int j=0,i=0;
        
        while(i<n && j<n)
        {
            if(nums[j]!=0)
            {
                swap(nums[j],nums[i]);
                j++;
                i++;
            }
            else
                j++;
        }
        
        
        return nums;
        
    }
};