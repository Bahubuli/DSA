#include<bits/stdc++.h>
using namespace std;

int minrevbal(string s)
{
    int n = s.length();
    if(n%2!=0)
        return -1;

    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='}' && !st.empty())
        {
            if(st.top()=='{')
                st.pop();
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    int count = 0;
    while (!st.empty())
    {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();

        if (c1 == c2)
            count++;
        else
            count += 2;
    }
    return count;

    // int nlen = st.size();

    // int m = 0;
    // while(!st.empty() && st.top() =='{')
    // {
    //     st.pop();
    //     m++;
    // }

    // return (nlen / 2 + m % 2);
}

    int main()
    {

}
