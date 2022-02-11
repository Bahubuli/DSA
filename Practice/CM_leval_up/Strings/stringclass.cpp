#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pra = "we are learning about hte stl strings. stl string class is very powerfull";
    string word;


    cout << pra.find("stl") << endl;

    int index = pra.find("cat");

    if(index==-1)
        cout << "word not found";
    else
    {
        cout << index << endl;
    }
    int idx1 = pra.find("stl");
    if(idx1!=-1)
        cout << "first occurance " << idx1 << endl;
    int idx2 = pra.find("stl", idx1 + 1);
    if(idx2!=-1)
        cout << "second occurance " << idx2 << endl;

}
