#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0)
    {
        vector<string> base_st;
        base_st.push_back("");
        return base_st;
    }

    char ch = s[0];//b

    string ros = s.substr(1);

    vector<string> rres = gss(ros);// "".,c
    vector<string> mres;

    for (string si : rres)
    {
        mres.push_back(si);
    }

    for (string si : rres)
    {
        mres.push_back(ch + si);
    }
    return mres;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
