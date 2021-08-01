#include <bits/stdc++.h>
using namespace std;


    int abcsubseq(string s, string res, int i)
    {
        if (i > s.length())
            return 0;
        cout << res << " " << s.substr(i) << endl;
        
        if (isfor(res))
            return 1;

        int s1 = abcsubseq(s, res + s[i], i + 1);
        int s2 = abcsubseq(s, res, i + 1);
        return s1 + s2;
}

int main()
{
        freopen("i.txt", "r", stdin);
        freopen("o.txt", "w", stdout);
        string s;
        cin >> s;
        cout << abcsubseq(s, "", 0);
}
