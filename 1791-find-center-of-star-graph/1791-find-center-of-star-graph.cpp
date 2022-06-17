class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<int> ind(n+2,0);
        
        for(auto e:edges)
        {
            ind[e[0]]++;
            ind[e[1]]++;
        }
        
        for(int i=1;i<=n+1;i++)
        {
            cout<<ind[i]<<endl;
            if(ind[i]==n) return i;
        }
        return 0;
    }
};