class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int ans =0;
        int prefx =0;
        vector<int> mp(k);
        mp[0]=1;
        for(auto x:nums)
        {
            prefx+=x%k;
            prefx = (prefx+k)%k;
            
            ans+=mp[prefx]++;
        }
        
        return ans;
        
    }
};