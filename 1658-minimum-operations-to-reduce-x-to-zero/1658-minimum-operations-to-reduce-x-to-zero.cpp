class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size(),i=0,j=0;
        
        int s=0;
        for(auto d:nums) s+=d;
        
        x=s-x;
        if(x<0) return -1;
        if(x==0) return n;
        
        int ans = INT_MIN;
        map<int,int>mp;
        int sum=0;
        while(i<n && j<=n)
        {
            sum+=nums[j];
            
            if(sum>=x)
            {
                while(sum>=x && i<n)
                {
                    if(sum==x )
                        ans = max(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                
                
            }
            
            j++;
            
        }
        
        return ans==INT_MIN?-1: n-ans;
        
    }
};