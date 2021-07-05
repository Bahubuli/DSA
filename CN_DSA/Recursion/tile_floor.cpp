#include<bits/stdc++.h>

using namespace std;

int tfw(int n,int m)
{
    //cout<<"fn is running"<<endl;
    if(n<m)
    return 1;

    if(n==m)
    return 2;

    int w1 = tfw(n-1,m);

    int w2 = tfw(n-2,m);
    return w1+w2;

}


int main()
{
    int n,m;

    cin>>n>>m;

    cout<<tfw(n,m)<<endl;;

}
