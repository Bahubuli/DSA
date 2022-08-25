class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if(ransomNote.size()>magazine.size()) return false;
        
        map<char,int>mp;
        for(auto m:magazine) mp[m]++;
        
        for(auto r:ransomNote) 
            if(mp[r]==0) return false;
            else 
            {
                mp[r]--;
            }
        return true;
    }
};