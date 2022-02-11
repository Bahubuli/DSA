#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> ourmap;
    pair<string,int> p("abc",1);

//---------------------------------------------
    ourmap.insert(p);

    ourmap["xyz"] = 2;

//---------------------------------------------
    cout << ourmap["xyz"] << endl;
    cout << ourmap.at("abc") << endl;



    //cout << ourmap.at("ghi") << endl;

    cout << ourmap["jkl"] << endl;

    // .at will give error in case of no value
    // [] will insert the value assigned by default

//------------------------------------------------
    cout << ourmap.count("tyi") << endl;

//-------------------------------------------------

    ourmap.erase("abc");
    cout << ourmap.at("abc");

//-----------------------------------------------
}
