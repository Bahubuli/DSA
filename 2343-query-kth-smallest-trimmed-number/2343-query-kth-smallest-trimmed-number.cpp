class Solution {
public:
    
    
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<pair<string,int>> res(n);
        vector<int> ans;
        for(auto q: queries)
        {
            int d = q[1], idx = q[0]-1;
            
            for(int i=0;i<n;i++)
            {
                d = nums[i].size()-q[1];
                string st = nums[i].substr(d);
                res[i] = {st,i};
            }
            
           sort(res.begin(),res.end());
            ans.push_back(res[idx].second);
            
        }
        return ans;
    }
};