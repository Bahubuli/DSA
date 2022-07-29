class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) 
    {
        map<char,int> mp;
        vector<string> ans;
        
        
        
        for(auto &w: words)
        {
            if(w.size()==p.size())
            {
                bool flag = true;
                map<char,char> mp1;
                map<char,char> mp2;
                for(int i=0;i<p.size();i++)
                {
                    if(mp1.find(p[i])==mp1.end() && mp2.find(w[i])==mp2.end())
                    {
                        mp1[p[i]] = w[i];
                        mp2[w[i]] = p[i];
                    }
                    
                    else if(mp1[p[i]]!=w[i] || mp2[w[i]]!=p[i])
                    {
                        flag = false;
                    }
                }
                if(flag) ans.push_back(w);
            }
        }
        return ans;
    }
};