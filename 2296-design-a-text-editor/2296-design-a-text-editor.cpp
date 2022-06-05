class TextEditor {
public:
    stack<char> left;
    stack<char> right;
    TextEditor() {
        
    }
    
    void addText(string text) 
    {
        for(auto &c:text) left.push(c);
        
    }
    
    int deleteText(int k) 
    {
        int c=0;
        while(left.size() && k)
        {
            left.pop();
            c++;
            k--;
        }
        return c;
        
    }
    
    string cursorLeft(int k) 
    {
        while(left.size() && k)
        {
            char c = left.top(); 
            left.pop();
            right.push(c);
            k--;
        }
        return cursorstring();  
    }
    
    string cursorRight(int k) 
    {
        while(right.size() && k)
        {
            char c = right.top();
            right.pop();
            left.push(c);
            k--;
        }
        return cursorstring();  
    }
    
    string cursorstring()
    {
        string ans = "";
        int c = 10;
        while(left.size() && c)
        {
            ans+=left.top();
            left.pop();
            c--;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            left.push(ans[i]);
        
        return ans;
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