class Solution {
public:
    int calculate(string s) 
    {
        int ans=0,num=0;
        stack<int>st;
        st.push(1);
        int ispositive = 1;
        
        for(auto c:s)
        {
            if(isdigit(c))
            {
                num = num*10 + (c-'0');
            }
            else
            {
            ans+=num*st.top()*ispositive;
            num=0;
            
            if(c=='+') ispositive = 1;
            if(c=='-') ispositive = -1;
            if(c==')') st.pop();
            if(c=='(')
            {
                st.push(st.top()*ispositive);
                ispositive = 1;
            }
            }
        }
        
        ans+=num*st.top()*ispositive;
        return ans;
    }
};