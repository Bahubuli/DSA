#include<bits/stdc++.h>

using namespace std;

string replacepi(string s)
{
    if(s.length()<=1)
    return s;

    if(s.length()>=2)
    {
        if(s.substr(0,2)=="pi")
        {
            return "3.14"+replacepi(s.substr(2));
        }
        else
        {
            return s.substr(0,1)+replacepi(s.substr(1));
        }

    }

}


int main()
{
    string s;
    cin>>s;

    cout<<replacepi(s)<<endl;
}
