class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        set<string> st,vis;
        
        char op[] = {'A','C','G','T'};
        
        for(auto s:bank) st.insert(s);
        
        if(st.find(end)==st.end()) return -1;
        
        queue<string>q;
        vis.insert(start);
        int ans = 0;
        q.push(start);
        while(q.size())
        {     
            int n = q.size();
            
            while(n--)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr==end) return ans;
                
                for(int i=0;i<8;i++)
                {
                    char oc = curr[i];
                    
                    for(int j=0;j<4;j++)
                    {
                        curr[i] = op[j];
                        
                        if(vis.find(curr)==vis.end() && st.find(curr)!=st.end())
                        {
                            q.push(curr);
                            vis.insert(curr);
                        }
                            
                    }
                    curr[i] = oc;
                }
                
                
            }     
            
            ans++;
            
        }
        
        return -1;
        
    }
};