#include<bits/stdc++.h>
using namespace std;


//my sol
string palidrome(string k)
{
    if(k.length()==1)
    return "True";
    if(k[0]==k[k.length()-1])
    {
        return palidrome(k.substr(1,k.length()-2));
    }
    else
    return "False";



}

int main()
{
    string s;
    cin>>s;
    cout<<palidrome(s)<<endl;
}
