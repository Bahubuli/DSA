class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto &x:tasks) mp[x]++;
        int ans =0;
        for(auto it:mp)
        {
            if(it.second<2) return -1;
            
            if(it.second%2==0)
            {
                int td = it.second/6;
                int re = (it.second%6)/2;
                
                ans+= 2*td+re;
            }
            else
            {
                if(it.second%3==0)
                {
                    ans+=it.second/3;
                }
                else if(it.second%3==2)
                {
                    ans+=it.second/3+1;
                }
                else
                {
                   int x = it.second/3 -1;
                    
                   ans+=x+2;
                }
                
            }
        }
        return ans;
        
    }
};