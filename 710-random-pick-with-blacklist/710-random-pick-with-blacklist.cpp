class Solution {
public:
    unordered_map<int,int> mp;
    int valid_nums=0;
    Solution(int n, vector<int>& blacklist) {
        
        set<int> st;
        
        for(auto &x : blacklist) st.insert(x);
        
         valid_nums = n-st.size();
        int idx = valid_nums;
        
        
        for(auto &x:st)
        {
            if(x<valid_nums)
            {
                while(st.count(idx)) idx++;  
                mp[x] = idx++;
            }
            
             
        }
        
        
    }
    
    int pick() {
        int ans = rand()%valid_nums;
        
        if(mp.count(ans))
            return mp[ans];
        
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */