class Solution {
public:
    
    void helper(vector<int>&nums,vector<vector<int>>&ans,int i)
    {
        if(i==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j = i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            helper(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        
        helper(nums,ans,0);
        
        return ans;
        
    }
};