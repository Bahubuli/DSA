class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> hash(1000,0);
        int mx =INT_MIN,i=0,j=0,n=s.size();
        while(j<n && i<n)
        {
            hash[s[j]]++;
            
            if(hash[s[j]]==1)
            {
                mx = max(mx,j-i+1);
                j++;
            }
            else
            {
                while(i<j)
                {
                    hash[s[i]]--;
                    if(hash[s[i]]==1)
                    {
                        i++;
                        break;
                    }
                    i++;
                }
                j++;
            }
        }
        return mx==INT_MIN?0:mx;
    }
};