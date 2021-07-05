#include<bits/stdc++.h>
using namespace std;


void edito()
{

}

int isprime(long long int n)
{
    if(n<0)
    n=n*(-1);
    for(long long int i=2;i<=n/2;i++)
    {
    if(n%i==0)
    return 0;
    }

    return 1;
}


int main()
 {

     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

string s;
cin>>s;
long long int n=0;
for(int i=0;i<s.length();i++)
{
    if(s[i]>='a' && s[i]<='z')
    {

        s[i]=s[i]-32;
        n=n+int(s[i]);

    //cout<<int(s[i])<<endl;
    }
    else if(s[i]>='A' && s[i]<='Z')
    {

        s[i]=s[i]+32;
        n=n-int(s[i]);
        //cout<<int(s[i])<<endl;


    }

}
cout<<n<<endl;
cout<<isprime(n)<<endl;



//edito();


}
