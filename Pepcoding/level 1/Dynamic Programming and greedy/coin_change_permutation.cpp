#include<bits/stdc++.h>
using namespace std;

//naive recursive solution
int coinchangepr(vector<int> arr,int m,int i,int d)
{
    if(m<0)
    return 0;
    if(m==0)
    return 1;

int paths=0;
for(int i=0;i<arr.size();i++)
{


        paths=paths+coinchangepr(arr,m-arr[i],i,d);

}
return paths;

}




void coinchangeprdp(vector<int> arr,int m)
{
    vector<int> dp(m+1);
dp[0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]<=i)
            {
                dp[i]=dp[i-arr[j]]+dp[i];
            }
        }
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


   // cout<<coinchangepr(arr,m,0,d);

    coinchangeprdp(arr,m);




}
