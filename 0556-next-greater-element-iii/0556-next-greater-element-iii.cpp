class Solution {
public:
    int nextGreaterElement(int m) 
    {
        string s = to_string(m);
        
        int n = s.size();
        int idx = -1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
            {
                idx = i;
                break;
            }
        }
        
        if(idx==-1) return -1;
       
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]>s[idx])
            {
                //cout<<s<<endl;
                swap(s[i],s[idx]);
                //cout<<s<<endl;
                sort(s.begin()+idx+1,s.end());
                
                //cout<<s<<endl;
                break;
            }
        }
     
        long long ans = stoll(s);
        
        if(ans>INT_MAX || ans<m) return -1;
        
        return ans;
    }
};