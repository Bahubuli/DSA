class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) 
    {
        sort(nums.begin(),nums.end());
        
        int mn=INT_MAX,ans,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            
            
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                
                if(abs(sum-t)<mn)
                {
                    mn = abs(sum-t);
                    ans = sum;
                }
                
                if(sum<t) j++;
                else k--;
            }
        }
        return ans;
        
    }
};