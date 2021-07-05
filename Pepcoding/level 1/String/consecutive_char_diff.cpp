#include <bits/stdc++.h>
using namespace std;

string conchardef(string s)
{
    string s2 = "";
    int i;

    for (i = 0; i < s.length() - 1; i++)
    {
        s2 = s2 + s[i] + to_string(s[i + 1] - s[i]);
    }
    s2 = s2 + s[i];
    return s2;
}

int main()
{
    string s;

    getline(cin, s);
    cout << conchardef(s) << endl;
}
