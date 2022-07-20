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
int knapsack01dp(vector<int> w,vector<int> v,int cap)
{

    vector<vector<int>> dp(w.size() + 1, vector<int>(cap + 1));

    for(int i=1;i<=w.size();i++)
    {
        for(int j=1;j<=cap;j++)
        {

                int part = 0;
                int notpart = 0;
                if(j-w[i-1]>=0)
                {
                    part = v[i - 1] + dp[i - 1][j - w[i - 1]];
                }

                    notpart = dp[i - 1][j];

                if(part>notpart)
                    dp[i][j] = part;
                else
                {
                    dp[i][j] = notpart;
                }

        }
    }


    // for(int i=1;i<=w.size();i++)
    // {
    //     for(int j=1;j<=cap;j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

            return dp[v.size()][cap];
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

     cout << knapsack01dp(w, v, cap);
}
