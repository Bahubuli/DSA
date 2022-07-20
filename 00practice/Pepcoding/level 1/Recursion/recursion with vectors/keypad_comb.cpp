#include <iostream>
#include <vector>
using namespace std;

vector<string> kpc(string s)
{
    vector<string> kps = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    if (s.size() == 1)
    {
        vector<string> base;
        int ch = s[0] - '0';
        string sb = kps[ch];
        for (int i = 0; i < sb.size(); i++)
        {
            base.push_back(sb.substr(i, 1));
            //cout << sb.substr(i, 1) << endl;
        }
        return base;
    }

    int ch = s[0] - '0';
    string ros = s.substr(1);

    vector<string> rres = kpc(ros);
    //cout << ch << endl;

    string s2 = kps[ch];
    //cout << s2 << endl;
    //cout << "function is running" << endl;

    vector<string> myres;

    for (int i = 0; i < s2.length(); i++)
    {
        for (string si : rres)
        {

            myres.push_back(s2[i] + si);
            //cout << s2[i] + si << endl;
        }
    }

    return myres;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;

    vector<string> ans = kpc(s);

    for (string si : ans)
        cout << si << endl;
}
