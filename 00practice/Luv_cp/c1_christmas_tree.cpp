#include<bits/stdc++.h>
using namespace std;

int fact(int n){
for (int i = n-1; i > 0; i--){
n = n * i;
}
return n;
}
void Pascal(int n)
{
    for (int line = 1; line <= n; line++)
    {
        long long int C = 1;
        for (int i = 1; i <= line; i++)
        {
            cout<< C<<" ";
            C = C * (line - i) / i;
        }
        cout<<"\n";
    }
}

void edito()
{
  	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			long int c = 1;
			for(int j = 0; j <= i; ++j){
				cout << c << " ";
				c = c * (i-j) / (j+1);
			}
			cout << endl;
		}
	}

}
//why one test case is failing
long long int pnum(long long int i,long long int j)
{
    long long int u=1;long long int d=1;
    long long int x=i;long long int y=j;
    //cout<<"i "<<i<<" j"<<j<<endl;
    for(long long  int k=0;k<j;k++)
    {
        u=u*x;
        x--;
        d=d*y;
        y--;
    }
    // cout<<"i j "<<i<<" "<<j<<endl;
    // cout<<"u and d"<<u<<" - "<<d<<endl;
    return u/d;
}



int main()
 {

     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout<<fact(10)<<endl;

// long long int t;
// cin>>t;
// while(t)
// {

//     long long int n;
//     cin>>n;
// cout<<"1"<<endl;
//  for(long long int i=1;i<n;i++)
//  {
//      for(long long int j=0;j<=i;j++)
//      {
//          if(i==1)
//          {
//              cout<<"1"<<" ";

//          }
//          else if(j==0 || j==i)
//          cout<<"1"<<" ";
//          else
//          {
//              cout<<pnum(i,j)<<" ";
//          }

//      }
//      cout<<"\n";
//  }
//  t--;
//}


//edito();


}
