class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        
        int i=0,j=0,n=s.size(),lastidx=0;
        
        while(j<n)
        {
            while(j<n && s[j]==' ') j++;
            
            int startidx = i;
            
            while(j<n && s[j]!=' ')
            {
                s[i++] = s[j++];
                lastidx = i;
            }
            
            reverse(s.begin()+startidx,s.begin()+i);
            s[i++] = ' ';
        }
        
        s.resize(lastidx);
        return s;
    }
};