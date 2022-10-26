#include<bits/stdc++.h>
using namespace std;

int stoint(string s)
{
    if(s.length()==1)
    {

    int chr = s[0]-'0';
    return chr;
    }

    string res=s.substr(1);

    int chr=s[0]-'0';

    return (chr*pow(10,res.length()))+stoint(res);


}
//better solution
int Convert(char arr[],int n){
    if(n==1){
      int x= (int)(arr[n-1]-48);
      return x;
    }
    int x= (int)(arr[n-1]-48);
    return Convert(arr,n-1)*10+x;
}


int main()
{
    string x;
    cin>>x;

    cout<<stoint(x)<<endl;
}
