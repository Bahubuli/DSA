class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) 
    {
        vector<vector<int>>ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int x=0;x<n;x++)
        {
            
             for(int i=x+1;i<n;i++)
            {
                int j = i+1,k=n-1;

                while(j<k)
                {
                    long long  sum = nums[x]+nums[i];
                    sum+= nums[j]+nums[k];

                    if(sum==t)
                    {
                    
                        ans.push_back({nums[x],nums[i],nums[j],nums[k]});
                        while(j+1<=k && nums[j]==nums[j+1]) j++;
                        while(k-1>=j && nums[k]==nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    else if(sum<t) j++;
                    else k--;
                }

                while(i+1<n && nums[i]==nums[i+1]) i++;
                
            }
            
            while(x+1<n && nums[x]==nums[x+1]) x++;
            
        }
    
        return ans;
        
    }
};