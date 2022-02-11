#include<bits/stdc++.h>
using namespace std;

//naive recursive solution
void targetsumr(vector<int> arr,int m,int i,int &d)
{
    if(m==0)
    {
        d=1;
        return;
    }
    if(m<0 || i==arr.size())
    return;

    targetsumr(arr,m-arr[i],i+1,d);

    targetsumr(arr,m,i+1,d);
}


//dp solution

void targetsumdp(vector<int> arr,int n,int m)
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


    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(i==1 && j==arr[i-1])
            {
                dp[i][j]=1;
            }

            if(arr[i-1]!=j)
            {
                if(dp[i-1][j]==1)
                dp[i][j]=1;

                if(j-arr[i-1]>=0)
                    if(dp[i-1][j-arr[i-1]]==1)
                    dp[i][j]=1;
            }
            else
            {
                dp[i][j]=1;
            }

        }

    }


    if(dp[n][m]==1)
    cout<<"true";
    else
    {
        cout<<"flase";
    }

    //  for(int i=0;i<dp.size();i++)
    // {
    //     for(int j=0;j<dp[0].size();j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }






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
   targetsumdp(arr,n,m);


//    targetsumr(arr,m,0,d);
//    if(d==1)
//    cout<<"true"<<endl;
//    else
//    {
//        cout<<"false"<<endl;
//    }


}
