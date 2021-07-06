#include<bits/stdc++.h>
using namespace std;


//write basic recursive code
int knapsackub(vector<int> w,vector<int> v,int i,int cap,int pf)
{

}

//implement dp code on your own
int knapsackubdp(vector<int> w,vector<int> v,int cap)
{
    vector<int> dp(cap + 1);

    for(int c=1;c<=cap;c++)
    {
        for(int i=0;i<w.size();i++)
        {
            int max = 0;
            if(w[i]<=c)
            {


            return dp[cap];
}
















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


      for(int i=0;i<n;i++)
      cin>>v[i];

    for(int i=0;i<n;i++)
      cin>>w[i];

      int cap;
      cin>>cap;

     //cout<<knapsack01(w,v,0,cap,0);

     cout << knapsackubdp(w, v, cap);
}
