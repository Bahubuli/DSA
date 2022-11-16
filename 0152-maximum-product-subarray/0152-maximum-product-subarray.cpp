class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int mx = 1,mn=1,ans=INT_MIN;
        
        for(auto x:nums)
        {
            if(x<0) swap(mx,mn);
            
            mx = max(mx*x, x);
            mn = min(mn*x,x);
            
            ans = max(ans,mx);
        }
        
        return ans;
        
    }
};