#include<bits/stdc++.h>
using namespace std;

char upper(char c)
{
    return 'A'+(c-'a');
}

void edito()
{
    while(true)
    {
        string s;
        cin>>s;
        if(s.size()==0)
        break;
        for(int i=0;i<s.size();i++)
        s[i]=upper(s[i]);
        cout<<s<<endl;
    }
}


int main()
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
char fullname[70000];
    cin.getline(fullname, 70000);

    for(int i=0;fullname[i]!='\0';i++)
    {
        if(fullname[i]!=' ')
        cout<<(char)(fullname[i]-32);
        else
        {
            cout<<"\n";
        }
    }


//edito();


}
