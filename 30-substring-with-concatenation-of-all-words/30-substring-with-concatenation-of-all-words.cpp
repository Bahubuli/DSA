class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int> mp;
        for(auto &w:words) mp[w]++;
        vector<int> ans;
        int n = words.size();
        int k = words[0].size();
        
        for(int i=0;i+k*n<=s.size();i++)
        {
            unordered_map<string,int> freq;
            
            for(int j=0;j<n;j++)
            {
                string res = s.substr(i+j*k,k);
                freq[res]++;
                if(freq[res]>mp[res]) break;
                
                if(j==n-1) ans.push_back(i);
            }
        }
        return ans;
    }
};