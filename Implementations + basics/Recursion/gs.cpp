#include<bits/stdc++.h>
using namespace std;

double gs(int k) {
if(k == 0) {
return 1;
}
return gs(k-1) + 1/pow(2,k);
}
//my sol
double gs2(int k)
{
    if(k==0)
    return 1;
    double d=1;
    d= d+gs2(k-1)/2;
    return d;

}

int main()
{
    int s;
    cin>>s;
    cout<<gs2(s)<<endl;
}
