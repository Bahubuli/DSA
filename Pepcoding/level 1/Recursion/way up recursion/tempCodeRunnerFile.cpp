#include <bits/stdc++.h>

using namespace std;

void printEncoding(string str, string asf)
{
    if(str.length()==0)
    {
        cout<<asf<<endl;
        return;

    }

    int sd = str[0]-'0';

    char sdc = 'a'+sd-1;
    printEncoding(str.substr(1),asf+sdc);

    if(str.length()>=2)
    {
        int ch12 = stoi(str.substr(0,2));
        char ch12v= 'a'+ch12-1;
        printEncoding(str.substr(2),asf+ch12v);


    }





}





int main()
{
    string str;
    cin>>str;
    printEncoding(str,"");

}
