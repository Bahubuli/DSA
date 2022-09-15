class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) 
    {
        if(nums.size()%2) return {};
        sort(nums.begin(),nums.end());
        multiset<int> st;
        
        for(auto x:nums) st.insert(x);
        
        vector<int>ans;
        
        for(auto x:nums)
            if(st.size() && (st.find(x*2)!=st.end()) &&  (st.find(x)!=st.end()))
            {
                auto it = st.find(x); 
                st.erase(it);
                
                auto it2 = st.find(x*2); 
                if(it2==st.end()) return {};
                st.erase(it2);
                
                ans.push_back(x);
            }
            
        if(ans.size()<nums.size()/2) return {};
        return ans;
    }
};