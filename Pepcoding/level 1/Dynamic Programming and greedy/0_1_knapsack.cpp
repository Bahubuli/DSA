#include<bits/stdc++.h>
using namespace std;


//basic recursive code
int knapsack01(vector<int> w,vector<int> v,int i,int cap,int pf)
{
     if(i==w.size() || cap<0)
    return 0;

        if(cap==0)
        {
        return pf;
        }



    int p1 = knapsack01(w,v,i+1,cap-w[i],pf+v[i]);
    int p2 = knapsack01(w,v,i+1,cap,pf);


    if(pf+v[i]>p1 && pf+v[i]>p2 && cap-w[i]>=0)
    return pf+v[i];

    if(p1>p2)
    return p1;
    else
    return p2;
}

//dp code
















int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif



       int n,m,d=0;
   cin>>n;

   vector<int> w(n);
   vector<int> v(n);

int min=9999;
for(int i=0;i<w.size();i++)
if(w[i]<min)
min=w[i];



      for(int i=0;i<n;i++)
      cin>>v[i];

    for(int i=0;i<n;i++)
      cin>>w[i];



      int cap;
      cin>>cap;


    cout<<knapsack01(w,v,0,cap,0);






}
