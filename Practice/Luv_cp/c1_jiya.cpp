#include<bits/stdc++.h>
using namespace std;


void edito()
{
    // don't use pow function
    // multiply by 2 in each iteration

}
//will not work in case of very large binary number
int anybasetodecimal(int n, int b)
{
    int m = 0, i = 0;
    while (n)
    {
        m = m + (n % 10) * pow(b, i);
        n = n / 10;
        i++;
    }
    return m;
}


int main()
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int t;
    cin>>t;
    while(t)
        {
            int n;
            cin>>n;
          string s;
          cin>>s;
            int d=0;
            long long int p2=1;

            for(int i=n-1;i>=0;i--)
            {
                int x= s[i]-'0';

                d=d+(x%10)*p2;
                p2=p2*2;


            }
            cout<<d<<endl;


            t--;

        }





//edito();


}
