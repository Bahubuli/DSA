#include <iostream>
#include <vector>
using namespace std;


void printstairpaths(int n,string s)
{
    if(n<0)
    return;
    if(n==0)
    {
        cout<<s<<endl;
        return;
    }

    printstairpaths(n-1,s + "1");

    printstairpaths(n-2,s+"2");

    printstairpaths(n-3,s+"3");

}

int main()
{
   int s;
    cin>>s;
    printstairpaths(s,"");


}
