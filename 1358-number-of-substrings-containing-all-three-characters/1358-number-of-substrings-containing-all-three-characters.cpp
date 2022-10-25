class Solution {
public:
    int numberOfSubstrings(string s) 
    {    
        int ans = 0,n=s.size(),i=0,j=0;
        map<char,int>mp;
        
        while(i<n && j<n)
        {
            while(j<n && (mp['a']==0 || mp['b']==0 || mp['c']==0))
            {
                mp[s[j]]++;
                j++;
            }
            
            while(mp['a'] && mp['b'] && mp['c'])
            {
                ans+= (n-j+1);
                mp[s[i]]--;
                i++;
            }
           
        }
        return ans;
    }
};