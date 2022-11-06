class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            
            int j = i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j+1<=k && nums[j]==nums[j+1]) j++;
                    while(k-1>=j && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                
                else if(sum<0) j++;
                else k--;
            }
            
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
        
    }
};