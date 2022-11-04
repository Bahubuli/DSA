class Solution {
public:
    bool isvowel(char c)
        {
            if(c>=97)
                c-=32;
            if(c=='A' || c=='E' || c=='I' || c=='O' ||c=='U')
                return true;
            return false;
        }

    
     string reverseVowels(string s)
        {
            int i=0,j=s.size()-1;
            while(i<j)
            {
                while(i<j && !isvowel(s[i]))
                    ++i;
                while(i<j && !isvowel(s[j]))
                    --j;
                if(i<j)
                    swap(s[i],s[j]);
                ++i;
                --j;
            }
                return s;
        }
};