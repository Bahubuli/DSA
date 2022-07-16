class Solution {
public:
    int mod = 1e9+7;
    int subc(string &s, string &t) 
{
    int n = s.size(),m = t.size();
  vector<unsigned int>prev(m+1,0),curr(m+1,0);
     
        prev[0] = 1;
        curr[0]  = 1;
    
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=m;j++)
        {
            int match = s[i-1]==t[j-1];
            
            if(match) match= prev[j-1];
            
            int notmatch = prev[j];
            
           curr[j] = (match+notmatch)%mod;
        }
        prev = curr;
    }
    
    return curr[m];
   
}
    
    int numDistinct(string s, string t) 
    {
        return subc(s,t);
    }
};