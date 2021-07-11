#include<bits/stdc++.h>
using namespace std;



int knapsackub(vector<int> w,vector<int> v,int i,int cap,int pf)
{
    if(cap<0 || i==w.size())
    {
        return 0;
    }
    if(cap==0)
        return pf;

        int x = knapsackub(w, v, i, cap - w[i], pf + v[i]);
        int y = knapsackub(w, v, i + 1, cap - w[i], pf + v[i]);
        int z = knapsackub(w, v, i + 1, cap, pf);

        int largest = x > y ? (x > z ? x : z) : (y > z ? y : z);
        if(largest<pf)
            largest = pf;

        return largest;
}

// dp solution
int knapsackubdp(vector<int> w,vector<int> v,int cap)
{
    vector<int> dp(cap + 1);

    for (int i = 0; i <= cap; i++)
    {
        for (int j = 0; j < w.size(); j++)
        {
            if (w[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
            }
        }
    }
    return dp[cap];
}
















int main()
{

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);




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


      //cout << knapsackub(w, v, 0, cap, 0);

       cout << knapsackubdp(w, v, cap);
}
