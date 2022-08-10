class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        map<int,long long int> mp;
        
        sort(arr.begin(),arr.end());
        for(auto x:arr) mp[x]++;
        
        for(int i=1;i<size(arr);i++)
        {
            long long int res = 0;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && mp.find(arr[i]/arr[j])!=mp.end())
                {
                    res+= mp[arr[j]] * (mp[arr[i]/arr[j]]);
                }
            }
            mp[arr[i]] += res;
        }
        
        long long int ans = 0;
        for(auto it:mp) ans+= it.second;
        int mod = 1e9+7;
        return ans%mod;
        
    }
};