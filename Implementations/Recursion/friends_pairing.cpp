#include<bits/stdc++.h>
using namespace std;

int fpairs(int n)
{
    if(n<=1)
    return 1;



    int d= fpairs(n-2);

    return n+d;
}

int main()
{
    int n;
    cin>>n;
    cout<<fpairs(n)<<endl;
}
