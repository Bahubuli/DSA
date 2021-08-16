// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Complete this function
string reSize(string s)
{
    //Your code here
    string s2 = "";
    int i = 1, j = 0, count = 1;

    while (i < s.length())
    {
        if (s[i - 1] == s[i])
        {
            count++;
            i++;
            continue;
        }
        s2 = s2 + s[i - 1];
        if (count >= 1)
            s2 = s2 + to_string(count);
        count = 1;
        i++;
    }
    if (s2[s2.length() - 1] != s[s.length() - 1])
        s2 = s2 + s[s.length() - 1];

    if (count >= 1)
        s2 = s2 + to_string(count);
    return s2;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << reSize(s) << endl;
    }
    return 0;
}
