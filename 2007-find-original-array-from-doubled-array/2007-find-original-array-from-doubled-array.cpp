class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) 
    {
        if(nums.size()%2) return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        
        for(auto x:nums) mp[x]++;
        
        vector<int>ans;
        
        for(auto x:nums)
            if(mp.size() && mp[2*x] && mp[x])
            {
                mp[x]--;
                if(mp[x*2]==0) return{};
                mp[x*2]--;
                
                ans.push_back(x);
            }
            
        if(ans.size()<nums.size()/2) return {};
        return ans;
    }
};