class Solution {
public:
    
    int par[26];
    int find(int x)
    {
        if(par[x]==-1) return x;
        return par[x] = find(par[x]);
    }
    
    void Union(int a,int b)
    {
        int pa = find(a);
        int pb = find(b);
        
        if(pa!=pb)    par[max(pa,pb)] = min(pa,pb);
    }
    
    
    string smallestEquivalentString(string s1, string s2, string s) 
    {
        memset(par,-1,sizeof(par));
        int n = s1.size();
        for(int i=0;i<n;i++) Union(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<s.size();i++) s[i] = find(s[i]-'a')+'a';
        return s;
        
    }
};