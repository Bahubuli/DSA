class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int max=0,ones=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) ones++;
            else ones = 0;
            
            if(ones>max) max = ones;
        } 
        return max;
    }
};