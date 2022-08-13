class Solution {
public:
     vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt; // Expected times of each word
        for(auto &w : words) cnt[w]++;
        int n = words.size();
        int k = words[0].size();
        vector<int> ans;
         
        for(int i=0;i+k*n<=s.size();i++)
        {
            unordered_map<string,int> seen;
            
            for(int j=0;j<n;j++)
            {
                string str = s.substr(i+j*k,k);
                seen[str]++;
                
                if(seen[str]> cnt[str]) break;
                if(j==n-1) ans.push_back(i);
            }
        }
         
         return ans;  
    }
};