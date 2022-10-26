class Solution {
public:
    bool checkIfPangram(string s) 
    {
        vector<int>hsh(26,0);
        for(int i=0;i<s.length();i++)
            hsh[s[i]-'a']++;
        
        for(int i=0;i<26;i++)
            if(hsh[i]==0) return false;
        
        return true;
    }
};