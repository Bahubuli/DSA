class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) 
    {
      
        int mx = 0,ans=INT_MAX;
        map<int,int> mp;
        
        for(auto x:nums)
        {
            int k = x%space;
            mp[k]++;
            if(mp[k]>mx)  mx = mp[k]; 
        }
        
        for(auto x:nums)
            if(mp[x%space]==mx) ans = min(ans,x);
        
       
        return ans;
    }
};