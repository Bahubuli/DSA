class Solution {
public:
    
    int expand(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        i++;
        j--;
        return j-i+1;
    }
    string longestPalindrome(string s) 
    {
        int l=0,r=0,len;
        
        for(int i=0;i<s.size();i++)
        {
            int res1 = expand(s,i,i);
            int res2 = expand(s,i,i+1);
            
            len = max(res1,res2);
            if(r-l<len)
            {
                l = i - (len-1)/2;
                r = i+ (len)/2;
            }
        }
        return s.substr(l,r-l+1);
        
    }
};