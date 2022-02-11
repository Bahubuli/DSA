#include<bits/stdc++.h>
using namespace std;
//naive recursive solution
int mjumpsr(int n,vector<int> jumps,vector<int> &dp)
{
    cout<<"********************************* "<<n<<endl;
    if(n==jumps.size())
    return 0;

//cout<<"hello "<<n<<endl;

    int min=9999;
    for(int i=jumps[n];i>0;i--)
    {
        if(n+i<=jumps.size())
        {
       int x= mjumpsr(n+i,jumps,dp);
       if(x<min)
       min=x;
        }
    }
    return min+1;

}


int mjumpsdp(int n,vector<int> jumps,vector<int> &dp)
{
    cout<<"********************************* "<<n<<endl;

    if(n==jumps.size())
    {
    return 0;
    dp[n]=0;
    }

    int min=9999;

    if(dp[n]>-1)
    return dp[n];
    else
    {
        for(int i=jumps[n];i>0;i--)
        {

            if(n+i<=jumps.size())
            {

                if(dp[n+i]<9999)
                {
                int x= mjumpsdp(n+i,jumps,dp);
                if(x<min)
                min=x;
                }

            }
        }
    }

    dp[n]=min+1;
    return dp[n];

}
//implement this during revision
int mjumpsmemo(int n,vector<int> jumps,vector<int> &dp)
{
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

   //cout<<mjumpsr(0,arr,dp);
   cout<<mjumpsdp(0,arr,dp);

}
