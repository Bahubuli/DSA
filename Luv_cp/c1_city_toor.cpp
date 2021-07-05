#include<bits/stdc++.h>
using namespace std;


void edito()
{
    // don't use pow function
    // multiply by 2 in each iteration.

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

//      #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif


    int t;
    cin>>t;
    while(t)
        {
            long long int n;
            cin>>n;
            cout<<n*4<<endl;



            t--;

        }





//edito();


}
