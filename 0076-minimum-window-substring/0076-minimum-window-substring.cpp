class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> remaining(128,0);
        for(auto &x:t) remaining[x]++;
        
        int required = t.size(),ansstart=0,start=0,i=0,mn = INT_MAX;
        
        while(i<=s.size() && start<s.size())
        {
            if(required)
            {
                remaining[s[i]]--;
                if(remaining[s[i]]>=0) required--;
                i++;
            }
            else
            {
                if(i-start<mn)
                {
                    mn=i-start;
                    ansstart=start;
                }
                
                remaining[s[start]]++;
                if(remaining[s[start]]>0) required++;
                
                start++;
                
            }
        }
        return mn==INT_MAX?"":s.substr(ansstart,mn);
    }
};