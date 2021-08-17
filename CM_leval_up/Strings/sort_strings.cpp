#include<bits/stdc++.h>
using namespace std;

string extractkey(string str,int key)
{
    //string tokeniser

    char *s = strtok((char *)str.c_str()," ");

    while(key>1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int converttoint(string s)
{
    int ans = 0;
    int p = 1;
    for(int i=s.length()-1;i>=0;i--)
    {
        ans += ((s[i] - '0') * p);
        p = p * 10;
    }
    return ans;
}



bool lexicocompare(pair<string,string> s1,pair<string,string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}


bool numericcompare(pair<string,string> s1,pair<string,string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return converttoint(key1) < converttoint(key2);
}




int main()
{
    int n;
    cin >> n;

    cin.get();

    string temp;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        getline(cin, temp);
        v.push_back(temp);
    }
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    vector<pair<string, string>> vp;
    //1. key extraction
    for(int i=0;i<n;i++)
    {
        vp.push_back({v[i], extractkey(v[i], key)});
    }

    //2. sorting

    if(ordering=="numeric")
    {
        sort(vp.begin(), vp.end(), numericcompare);
    }
    else
    {
        sort(vp.begin(), vp.end(), lexicocompare);
    }

    //3.reversal
    if(reversal=="true")
    {
        reverse(vp.begin(), vp.end());
    }

    //4. output

    for(int i=0;i<n;i++)
        cout << vp[i].first << endl;

}
