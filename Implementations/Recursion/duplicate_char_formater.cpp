
#include <bits/stdc++.h>
using namespace std;

//“hello” return “hel*lo”.
//my solution
string dupformater(string s)
{
    if(s.length()==1)
    {
        return s ;
    }
    string s2=s.substr(0,1);

    if(s[0]==s[1])
    {
       s2 = s2+"*";
    }

    return (s2+dupformater(s.substr(1)));


}

string duplicateChar(string s)
{
    if (s.size() <= 1)
    {
        return s;
    }

    string ros = duplicateChar(s.substr(1));

    if (s[0] == ros[0])
    {
        return s[0] + string("*") + ros;
    }

    return s[0] + ros;
}



int main()
{

    string s="kkk";
    cout<<dupformater(s);

}
