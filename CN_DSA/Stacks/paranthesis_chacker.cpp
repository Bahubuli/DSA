// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[0] == ')' || x[0] == '}' || x[0] == ']')
                return false;

            if (x[i] == '(' || x[i] == '{' || x[i] == '[')
                s.push(x[i]);

            else if (!s.empty() and x[i] == ')')
            {
                if (s.top() == '(')
                    s.pop();
                else
                    return false;
            }

            else if (!s.empty() and x[i] == '}')
            {
                if (s.top() == '{')
                    s.pop();
                else
                    return false;
            }

            else if (!s.empty() and x[i] == ']')
            {
                if (s.top() == '[')
                    s.pop();
                else
                    return false;
            }
        }

        if (s.empty())
            return true;
        else
            return false;

        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends
