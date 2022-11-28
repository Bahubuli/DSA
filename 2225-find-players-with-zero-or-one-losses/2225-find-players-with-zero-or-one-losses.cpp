class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        vector<vector<int>> ans;
        map<int,int>win;
        map<int,int>los;
        
        for(auto res: matches)
        {
            win[res[0]]++;
            los[res[1]]++;
        }
        vector<int>wlist;
        vector<int>llist;
        for(auto it: win)
        {
            if(los.find(it.first)==los.end()) wlist.push_back(it.first);
        }
        
        for(auto it:los)
        {
            if(it.second==1) llist.push_back(it.first);
        }
        ans.push_back(wlist);
        ans.push_back(llist);
        return ans;
        
    }
};