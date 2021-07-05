#include <iostream>
#include <vector>
using namespace std;



void subseq(string s1,string s2)
{

    if(s1.length()==0)
    {
    cout<<s2<<endl;
    return;
    }

    char ch = s1[0];

    string s3= s1.substr(1);

    subseq(s3,s2+ch);
    subseq(s3,s2+"");


    


}
  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string s;
    cin>>s;

   
  

   subseq(s,"");
    
}
