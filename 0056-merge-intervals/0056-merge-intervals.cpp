class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) 
    {
        sort(it.begin(),it.end());
        
        vector<vector<int>>ans;
        ans.push_back(it[0]);
        
        for(int i=1;i<it.size();i++)
        {
            if(it[i][0]<=ans.back()[1]) 
                ans.back()[1] = max(it[i][1],ans.back()[1]);
            
            else ans.push_back(it[i]);
        }
        
        return ans;
    }
};