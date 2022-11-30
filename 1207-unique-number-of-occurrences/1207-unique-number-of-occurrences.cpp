class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int>mp;
        for(auto x:arr) mp[x]++;
        set<int> st;
        
        for(auto it:mp)
        {
            if(st.find(it.second)!=st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};