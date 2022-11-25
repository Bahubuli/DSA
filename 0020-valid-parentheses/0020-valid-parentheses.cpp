class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        
        map<char,char>match;
        match[')'] = '(';
        match[']'] = '[';
        match['}'] = '{';
        
        for(auto c:s)
        {
            if(c=='(' || c=='{' || c=='['  ) st.push(c);
            else if( st.size() && match[c]==st.top()) st.pop();
            else return false;
        }
        return st.empty();
    }
};