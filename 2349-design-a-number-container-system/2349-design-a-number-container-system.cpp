class NumberContainers {
public:
    
    NumberContainers() 
    {
        
        
    }
 
    
    
    unordered_map<int,int> imap;
    unordered_map<int,set<int>> nmp;
    
    void change(int idx, int x) 
    {
        if(imap.find(idx)!=imap.end())
        {
            int prev = imap[idx];
            if(prev==x) return;
            imap[idx] = x;
        
            nmp[x].insert(idx);
            nmp[prev].erase(idx);   
        }
        else
        {
            imap[idx] = x;
            nmp[x].insert(idx);
        }    
    }
    
    
    int find(int x) 
    {
        if(nmp[x].size()==0) return -1;
        
        return *(nmp[x].begin());
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */