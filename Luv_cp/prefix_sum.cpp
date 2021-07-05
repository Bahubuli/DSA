#include<bits/stdc++.h>
using namespace std;


const int N=1e3+10;

int ar[N][N];
long long pf[N][N];
int main()
 {

     #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
        freopen("o.txt", "w", stdout);
    #endif

int n;
cin>>n;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>ar[i][j];
        pf[i][j]=ar[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
    }
}

int t;
cin>>t;
while(t--)
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    long long sum=0;
    for(int i=a;i<=c;++i)
    {
        for(int j=b;j<=d;++j)
        {
            sum=sum+ar[i][j];
        }
    }
    cout<<sum<<endl;
    cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<endl;

}







//edito();


}
