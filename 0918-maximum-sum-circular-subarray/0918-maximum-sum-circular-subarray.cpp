class Solution {
public:
    
    
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        long long mx=INT_MIN,total=0,mn=INT_MAX,currmax=INT_MIN,currmin=INT_MAX;
        
        for(long long x:nums)
        {
            total+=x;
            currmax = max(currmax+x,x);
            currmin = min(currmin+x,x);
            
            mx = max(mx,currmax);
            mn = min(mn,currmin);
        }
        
        return mx>0 ? max(mx,total-mn) : mx;
        
    }
};