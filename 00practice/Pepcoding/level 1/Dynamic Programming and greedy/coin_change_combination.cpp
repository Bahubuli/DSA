#include<bits/stdc++.h>
using namespace std;

//naive recursive solution
void coinchanger(vector<int> arr,int m,int i,int &d)
{
    if(m<0 || i>= arr.size())
    return;
    if(m==0)
    {
        d++;
        return;
    }

    coinchanger(arr,m-arr[i],i,d);
    coinchanger(arr,m,i+1,d);

}

//my unoptimized dp solution
void coinchangedp(vector<int> arr,int n,int m)
{
    vector < vector < int >> dp(n+1, vector < int > (m+1));

       for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            if(j==0)
            {
            dp[i][j]=1;
            continue;
            }
            if(i==0)
            dp[i][j]=0;
        }
    }
    //cout<<"+++++++++++"<<endl;
      for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(i==1)
            {
                if(j%arr[i-1]==0)
                dp[i][j]++;
                continue;
            }
            dp[i][j]=dp[i-1][j];

            int x=arr[i-1];
            int k=1;
            while(x*k<=m && j-x*k>=0)
            {
                if(dp[i-1][j-x*k]!=0)

                    dp[i][j]=dp[i-1][j-x*k]+ dp[i][j];

                k++;
            }




        }
    }
    // cout<<"--------------"<<endl;
    //    for(int i=0;i<dp.size();i++)
    // {
    //     for(int j=0;j<dp[0].size();j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][m]<<endl;






}
//sumeet sir's solution
void dpcoinchange(vector<int> arr,int n,int m)
{
    vector<int>dp(m+1);
    dp[0]=1;

    for(int i=0;i<arr.size();i++)
    for(int j=arr[i];j<dp.size();j++)
    {
        dp[j]=dp[j]+dp[j-arr[i]];
    }
cout<<dp[m]<<endl;

}




int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif



       int n,m,d=0;
   cin>>n;

   vector<int> arr(n);
      for(int i=0;i<n;i++)
   {

       cin>>arr[i];

   }
   cin>>m;


    //coinchanger(arr,m,0,d);

    //cout<<d<<endl;

    dpcoinchange(arr,n,m);




}
