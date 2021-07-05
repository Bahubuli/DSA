#include <bits/stdc++.h>
using namespace std;

string togglecase(string s)
{

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 95)
        {
            s[i] = s[i] + 32;
        }
        else
        {
            s[i] = s[i] - 32;
        }
    }
    return s;
}

int main()
{
    string s;

    getline(cin, s);
    cout << togglecase(s) << endl;
}
