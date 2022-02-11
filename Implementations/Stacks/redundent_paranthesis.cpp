#include<bits/stdc++.h>
using namespace std;

bool isredudent(string s)
{

    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ')')
        {
            st.push(s[i]);
        }
        else
        {
            int count = 0;
            while (!st.empty() && st.top() != '(')
                {
                    st.pop();
                    count++;
                }
                    st.pop();
                if(count<2)
                    return 1;
        }
    }
    return false;
}

int main()
{

    string s = "(a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j())) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( (f * j))) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) * (d * ( f * j)) + (a + (b*c)) + (d * ( f * j)) + () ";
    cout << isredudent(s) << endl;
}
