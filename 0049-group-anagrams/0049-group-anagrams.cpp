class Solution {
public:
    string sortLowercase(string &s) {
    int charExist[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        charExist[s[i] - 'a']++;
    }
    string res;
    int j = 0;
    while (j < 26) {
        if (charExist[j] == 0) {
            j++;
        }
        else {
            res.push_back(j + 'a');
            charExist[j]--;
        }
    }
    return res;
}
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>> mp;
        vector<vector<string>>ans;
        for(auto &s : strs)
        {
            string ss =s;
            ss = sortLowercase(ss);
            mp[ss].push_back(s);   
        }
        
        for(auto it :mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};