class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
                st.pop();
            
            else if(ops[i]=="D")
                st.push(st.top()*2);
                
            else if(ops[i]=="+")
            {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                
                int newR = t1+t2;
                st.push(t1);
                
                st.push(newR);
            }
                
            else 
                st.push(stoi(ops[i]));
        }
        
        int sum =0;
        while(st.size())
        {
            sum = sum+st.top();
            st.pop();
        }
        return sum;
    }
};