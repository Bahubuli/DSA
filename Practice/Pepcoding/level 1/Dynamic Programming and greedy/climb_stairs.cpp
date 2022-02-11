#include<bits/stdc++.h>
using namespace std;

int sp(int n,vector<int> &spt)
{
    if(n==0)
    {
         spt[n]=1;
         return 1;
    }

    if(n<0)
    {
        return 0;
    }
    if(spt[n]!=0)
    {
        return spt[n];
    }


    int p1 = sp(n-1,spt);
    int p2 = sp(n-2,spt);
    int p3 = sp(n-3,spt);
spt[n]=p1+p2+p3;

return spt[n];





}

int sptab(int n)
{
    vector<int> dpt(n+1);
    dpt[0]=1;

    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            dpt[i]=dpt[i-1];
        }
       else if(i==2)
        {
            dpt[i]=dpt[i-2]+dpt[i-1];
        }
        else
        {
            dpt[i]=dpt[i-3]+dpt[i-2]+dpt[i-1];
        }
    }

     return dpt[n];


}

int main()
{
   int n;
   cin>>n;
   vector<int> spt(n+1,0);

   cout<<sp(n,spt)<<endl;
   cout<<sptab(n);
}
