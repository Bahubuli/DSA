#include <iostream>
using namespace std;

void printPermutations(string str, string asf)
{

    if(str.length()==0)
    cout<<asf<<endl;

    for(int i=0;i<str.length();i++)
    {
        string st=str;

        char ch= st[i];
        st.erase(i,1);

        printPermutations(st,asf+ch);


    }


}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");

}
