class Solution {
public:
    
    int helper(string s,int i,int op,int cl)
    {
        if(i==s.size()) return op+cl;
        if(s[i]==')' && op>0) return helper(s,i+1,op-1,cl);
        else if(s[i]=='(') return helper(s,i+1,op+1,cl);
        else return helper(s,i+1,op,cl+1);
    }
    
    int minAddToMakeValid(string s) 
    {
        return helper(s,0,0,0);
        
    }
};