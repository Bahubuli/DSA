class TextEditor {
public:
    stack<char>left,right;
    TextEditor() {
    }
    
    void addText(string text) 
    {
        for(auto &c:text) left.push(c);
    }
    
    int deleteText(int k) 
    {
        int ans = 0;
        while(left.size() && k)
        {
            left.pop();
            ans++;
            k--;
        }
        return ans;
    }
    
    string cursorLeft(int k) 
    {
        while(left.size() && k)
        {
            right.push(left.top());
            left.pop();
            k--;
        }
        return buildstring();
    }
    
    string cursorRight(int k) 
    {
        while(right.size() && k)
        {
            left.push(right.top());
            right.pop();
            k--;
        }
        return buildstring();
    }
    string buildstring()
    {
        int c = 10;
        string ans="";
        while(left.size() && c)
        {
            ans+=left.top();
            left.pop();
            c--;
        }
        reverse(ans.begin(),ans.end());
        for(auto &c:ans) left.push(c);
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