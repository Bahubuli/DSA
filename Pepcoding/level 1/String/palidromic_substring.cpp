#include <bits/stdc++.h>
using namespace std;

bool ispalidromic(string s)
{
    //cout << s << endl;
    int i = 0;
    int j = s.length();
    int flag = 1;

    if (s.length() == 1)
        return true;
    j = j - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            flag = 0;
            break;
        }

        i++;
        j--;
        continue;
    }
    if (flag == 1)
        return true;
    else
        return false;
}

int main()
{
    string s;

    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= s.length() - i; j++)
        {
            //cout << "i= " << i << "j = " << j << endl;
            if (ispalidromic(s.substr(i, j)))
                cout << s.substr(i, j) << endl;
        }
    }
}
