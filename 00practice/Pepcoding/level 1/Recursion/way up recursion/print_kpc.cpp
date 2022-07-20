#include <iostream>
#include <vector>
using namespace std;

void kpc(string s,string ans)
{
    if(s=="")
    {
    cout<<ans<<endl;
    return;
    }

    vector<string> kps = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    string rest="";

    int ch = s[0]-'0';

    string keys = kps[ch];
   
    if(s.length()>1)
    rest = s.substr(1);

    for(int i=0;i<keys.length();i++)
    {
        kpc(rest ,ans+keys[i]);
    }

    

    

    



   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    string s;
    cin >> s;

    kpc(s,"");


}
