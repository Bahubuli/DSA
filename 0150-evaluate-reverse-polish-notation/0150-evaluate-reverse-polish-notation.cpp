class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int>st;
        
        for(auto s:tokens)
        {
          if(s=="+")
          {
               long long  int x= st.top();
                st.pop();
                long long int y = st.top();
                st.pop();
                st.push(y+x);
          }
          else if(s=="-")
          {
               long long  int x= st.top();
                st.pop();
               long long  int y = st.top();
                st.pop();
                st.push(y-x); 
              
          }
                
            else if(s=="*")
            {
               long long  int x= st.top();
                st.pop();
               long long int y = st.top();
                st.pop();
                st.push(x*y);
            }
            else if(s=="/")
            {
              long long  int x= st.top();
                st.pop();
               long long int y = st.top();
                st.pop();
                st.push(y/x);
            }
            else
            {
                st.push(stoi(s));
            }
                
        }
        // int ans=0;
        // while(st.size())
        // {
        //     ans+=st.top();
        //     st.pop();
        // }
        // return ans;
        return st.top();
        
    }
};