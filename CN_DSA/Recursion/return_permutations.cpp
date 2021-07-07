#include<bits/stdc++.h>
using namespace std;

vector<string> permutations(string s,vector<string> sinp,string pf)
{

    if(s.length()==0)
    {
        sinp.push_back(pf);
        return sinp;
    }
    
    for(int i=0;i<s.length();i++)
    {
        string s2 = s;
        s2.erase(i, 1);
        sinp = permutations(s2, sinp, pf + s[i]);
    }
    return sinp;
}



int main()
{

    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    string s = "abc";
    vector<string> sinp;
    vector<string> res= permutations(s, sinp, "");

    for(string s:res)
        cout << s << endl;
}
