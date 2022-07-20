#include<bits/stdc++.h>
using namespace std;

int fibo(int n,vector<int> &fib)
{
    if(n==0||n==1)
    {
         fib[n]=n;
         return n;
    }
        for(int i:fib)
    cout<<i<<endl;
     cout<<"============="<<endl;

    if(fib[n]!=0)
    {
        cout<<"is this really doing something "<<n<<endl;
        return fib[n];
    }

//cout<<"this is "<<n<<endl;
    int fib1=fibo(n-1,fib);
    int fib2=fibo(n-2,fib);

    int res=fib1+fib2;
    fib[n]=res;
    for(int i:fib)
    cout<<i<<endl;
    cout<<"bullshit"<<endl;
    return res;

}

int main()
{
   int n;
   cin>>n;
   vector<int> fib(n+1,0);

   cout<<fibo(n,fib);
}
