class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& sb,vector<int> &nums,int i)
    {
        ans.push_back(sb);
        
        for(int j=i;j<nums.size();j++)
        {
            if(j!=i && nums[j-1]==nums[j]) continue;
            
            sb.push_back(nums[j]);
            helper(ans,sb,nums,j+1);
            sb.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>sb;
        vector<vector<int>> ans;
        helper(ans,sb,nums,0);
        return ans;
        
    }
};