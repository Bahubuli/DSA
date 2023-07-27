class Solution {
public:
    
   
    int calPoints(vector<string>& ops) 
    {
        stack<int>st;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                
                int newRecord = t1+t2;
                st.push(t1);
                st.push(newRecord);
            }
            else if(ops[i]=="D")
            {
                st.push(st.top()*2);
            }
            else if(ops[i]=="C")
            {
                st.pop();
            }
            else 
            {
                st.push(stoi(ops[i]));
            }
        }
        
        int ans = 0;
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};