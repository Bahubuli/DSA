class Solution {
public:
    string largestPalindromic(string num) 
    {
        vector<int>mp(10,0);
        
        for(auto &c:num) mp[c-'0']++;
        
        string left = "",right = "";
        
        int d = 9;
        
        while(d>=0)
        {
            
            if(mp[d]>1)
            {
                if(d==0 && left.size()==0)
                {
                    break;
                }
                left += to_string(d);
                right += to_string(d);
                mp[d]-=2;
            }
            if(mp[d]<=1) d--;    
        }
        
        //cout<<left<<" "<<right<<endl;
        d = 9;
        
        reverse(right.begin(),right.end());
        while(d>=0)
        {
            if(mp[d]) 
            {
                left+=to_string(d);
                left+=right;
               return left;
            }
            d--;
        }
        
        return left+right;
    }
};