class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
//         vector<pair<int,int>> numsp(n);
        
//         for(int i=0;i<n;i++)
//         {
//             int x = nums[i];
          
            
//             int ds =0;
//             while(x>9)
//             {
//                 while(x)
//                 {
//                     ds = x%10;
//                     x = x/10;
//                 }
//                 x = ds;
//             }
            
//             numsp[ds] = {x,nums[i]};      
//         }
        
//         sort(numsp.begin(),numsp.end(),cmp);
        
        unordered_map<int,multiset<int>>mp;
        
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            int ds =0;
            
                while(x)
                {
                    ds += x%10;
                    x = x/10;
                }
                x = ds;
               
            
           // cout<<x<<endl;
            mp[x].insert(nums[i]);
            if(mp[x].size()>2) mp[x].erase((mp[x].begin()));
            
        }
        
        int ans = -1;
        
        for(auto it:mp)
        {
            if(it.second.size()>1)
            {
                ans = max(ans,*it.second.begin()+*it.second.rbegin());
            }
        }
        
        return ans;
        
        
        
    }
};