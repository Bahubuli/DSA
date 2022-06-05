class TextEditor {
public:
    list<char>ll;
    list<char>::iterator curr;
    TextEditor() 
    {
        ll.clear();
        ll.push_back('|');
        curr = ll.end();
        
    }
    
    void addText(string text) 
    {
        ll.insert(curr,text.begin(),text.end());    
    }
    
    int deleteText(int k) 
    {
        int c = 0;
        curr--;
        while(k-- && curr!=ll.begin())
        {
            c++;
            ll.erase(curr--);
        }
        curr++;
        return c;
        
    }
    
    string solve()
    {
        auto it = curr;
        it--;
        string ans = "";
        int k = 10;
        while(k-- && it!=ll.begin())
        {
            ans+= *(it--);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string cursorLeft(int k) 
    {
        while(k-- )
        {
            auto prev = curr;
            prev--;
            if(prev==ll.begin()) break;
            curr = prev;
        }
            
        return solve();
        
    }
    
    string cursorRight(int k) 
    {
        while(k-- && curr!=ll.end()) curr++;
        return solve();
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */