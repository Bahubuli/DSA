class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        map<string,int> mp;
        int mx=0;
        int c=0;
        for(auto w :words)
        {
            mp[w]++;   
        }
        bool flag = false;
        for(auto w : words)
        {
            string o = w;
            reverse(w.begin(),w.end());
            
            if(mp[w]>0)
            {
                if(o==w)
                {
                    if(mp[w]==1)
                    {
                        if(flag == false)
                        {
                            c=c+2;
                            flag = true;
                        }
                    }
                    else 
                    {
                        mp[w]--;
                        mp[w]--;
                        c=c+4;
                    }
                    
                }
                else if(mp[w]>0 && mp[o]>0)
                {
                  c=c+4;
                    mp[w]--;
                    mp[o]--;
                }
            }
        }
        return c;
        
    }
};