#include<bits/stdc++.h>
using namespace std;


const int N=2e5+10;

//e5 indicates 5 zeros at the end of the given number

int main()
 {

     #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
        freopen("o.txt", "w", stdout);
    #endif


    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        int l,r;
        cin>>n>>q;
        int arr[n+9];
        int forward[n+9];
        int backward[n+9];
        forward[0]=backward[n+1]=0;

        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        for(int i=1;i<=n;i++)
        {
            forward[i]=__gcd(forward[i-1],arr[i]);
        }

//__gcd is a built in function that calculates the gcd of given two numbers in
//O(nlogn) time the acutal implementation will be done in furture videos
        for(int i=n;i>=1;--i)
        {
            backward[i]=__gcd(backward[i+1],arr[i]);
        }

        while(q--)
        {
            cin>>l>>r;

            cout<<__gcd(forward[l-1],backward[r+1])<<endl;;
        }
    }
 }
