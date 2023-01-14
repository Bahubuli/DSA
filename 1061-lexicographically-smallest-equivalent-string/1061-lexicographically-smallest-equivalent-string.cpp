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
        int pa = find(a),pb = find(b);
        if(pa!=pb) par[max(pa,pb)] = min(pa,pb);
    }
    string smallestEquivalentString(string s1, string s2, string s) 
    {
        memset(par,-1,sizeof(par));
        for(int i=0;i<size(s1);i++) Union(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<size(s);i++) s[i] = find(s[i]-'a')+'a';
        return s;
        
    }
};