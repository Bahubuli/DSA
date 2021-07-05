#include <bits/stdc++.h>
using namespace std;

string compress1(string s)
{
    string s2 = "";

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] != s[i])
            s2 = s2 + s[i - 1];
    }
    if (s2[s2.length() - 1] != s[s.length() - 1])
    {
        s2 = s2 + s[s.length() - 1];
    }

    return s2;
}

string compress2(string s)
{
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
        if (count > 1)
            s2 = s2 + to_string(count);
        count = 1;
        i++;
    }
    if (s2[s2.length() - 1] != s[s.length() - 1])
        s2 = s2 + s[s.length() - 1];

    if (count > 1)
        s2 = s2 + to_string(count);
    return s2;
}

int main()
{
    string s = "aabbbcaaddddeee";

    //getline(cin, s);
    cout << compress1(s) << endl;
    cout << compress2(s) << endl;
}
