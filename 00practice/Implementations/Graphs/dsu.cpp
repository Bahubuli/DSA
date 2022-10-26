class dsu
{
    public:

    vector<int> parent,size;

    dsu(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void union(int u,int v){

        int pu = findpar(u);
        int pv = findpar(v);

        if(pu=pv) return;

        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv] +=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        } 

    }

    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findpar(parent[node]);
    }

}
