class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
    {
        int n = reward1.size(),ans=0;
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
            nums.push_back({reward1[i]-reward2[i],i});
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i<k) ans+=reward1[nums[i].second];
            else ans+=reward2[nums[i].second];
        }
        
        return ans;
    }
};