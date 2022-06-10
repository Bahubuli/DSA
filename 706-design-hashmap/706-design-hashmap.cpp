class MyHashMap {
public:
    int hash  = 47;
    vector<list<pair<int,int>>> mp;
    MyHashMap() 
    {
        mp.resize(47);
    }
    
    void put(int key, int value) 
    {
        int idx = key%hash;
        auto &ll = mp[idx];
        
        for(auto &node :ll)
        {
            if(node.first==key)
            {
                node.second = value;
                return;
            }
        }
        ll.push_back({key,value});
    }
    
    int get(int key) 
    {
        int idx = key%hash;
        auto &ll = mp[idx];
        
        for(auto &node:ll)
        {
            if(node.first==key)
                return node.second;
        }
        return -1;
        
    }
    
    void remove(int key) 
    {
        int idx = key%hash;
        auto &ll = mp[idx];
        
        for(auto &node : ll)
        {
            if(node.first==key)
            {
                ll.remove(node);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */