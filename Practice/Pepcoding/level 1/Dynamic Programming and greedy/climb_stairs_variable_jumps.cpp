#include<bits/stdc++.h>
using namespace std;
//to be continued....
int spr(int n,vector<int> jumps,vector<int> &dp)
{
    //cout<<"whats going on"<<endl;
    int x=0;
    if(n==jumps.size())
    {
        dp[n]=1;
        return 1;
    }
    if(n>jumps.size())
    {return 0;
    }
    if(dp[n]>-1)
    return dp[n];
    else
    {

        for(int i=1;i<=jumps[n];i++)
    {
        x=x+spr(n+i,jumps,dp);

    }



    }

    dp[n]=x;
    return x;

}




int sp(int n,vector<int> &jumps)
{

    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        //cout<<"jumps "<<i<<" "<<jumps[i]<<endl;
        for(int j=jumps[i];j!=0;j--)
        {
            if(i+j<dp.size())
            dp[i]=dp[i]+dp[i+j];
            //cout<<"i j dp[i+j] = "<<i<<" "<<j<<" "<<dp[i+j]<<endl;
        }
    }
    //cout<<" k is "<<endl;
    // for(int k:dp)
    // cout<<k<<endl;


return dp[0];

}

int main()
{
   int n;
   cin>>n;

   vector<int> arr(n);
   for(int i=0;i<n;i++)
   {

       cin>>arr[i];

   }

    vector<int> dp(n+1,-1);


   //cout<<sp(n,arr)<<endl;

   cout<<spr(0,arr,dp);

}
