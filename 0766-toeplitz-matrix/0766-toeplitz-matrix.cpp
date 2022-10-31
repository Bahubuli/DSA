class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0;i<n;i++)
        {
             int x=i,y=0;
            
            set<int> st;
            while(x<n && y<m)   st.insert(mat[x++][y++]);
            
            if(st.size()>1) return false;
            
        }
    
        for(int j=0;j<m;j++)
        {
            int x=0,y=j;
            
            set<int> st;
            
            while(x<n && y<m)  st.insert(mat[x++][y++]);
            
            
            if(st.size()>1) return false;  
        }
        
        return true;
    }
};