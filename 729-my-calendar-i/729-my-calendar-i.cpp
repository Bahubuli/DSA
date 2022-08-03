class MyCalendar {
public:
    
    set<pair<int,int>> st; 
    
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        auto idx = st.lower_bound({start,end});
        
        if(idx!=st.end() && (idx->first<end)) return false;
        
        if(idx!=st.begin() && !(prev(idx)->second<=start)) return false;
        
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */