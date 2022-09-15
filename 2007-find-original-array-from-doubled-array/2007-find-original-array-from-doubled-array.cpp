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
            if(mp.size() && (mp.find(x*2)!=mp.end()) &&  (mp.find(x)!=mp.end()))
            {
                mp[x]--;
                if(mp[x*2]==0) return{};
                mp[x*2]--;
                
                if(mp[x]==0) mp.erase(x);
                if(mp[x*2]==0) mp.erase(x*2);
                ans.push_back(x);
            }
            
        if(ans.size()<nums.size()/2) return {};
        return ans;
    }
};