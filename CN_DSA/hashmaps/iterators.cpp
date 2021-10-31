#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mymp;

    mymp["key1"] = 1;
    mymp["key2"] = 2;
    mymp["key3"] = 3;
    mymp["key4"] = 4;
    mymp["key5"] = 5;
    mymp["key6"] = 6;
    mymp["key7"] = 7;

    unordered_map<string, int>::iterator it = mymp.begin();
    while(it!=mymp.end())
    {
        cout << "key : " << it->first << " value: " << it->second << endl;
        it++;
    }

    vector<int> v;
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(17);

    vector<int>::iterator it1 = v.begin();

    while(it1!=v.end())
    {
        cout << *it1 << endl;
        it1++;

    }

    // there are few function in various stl ds that only return iterators
    unordered_map<string, int>::iterator it2 = mymp.find("key1");

    vector<int>::iterator it3 = v.begin();
    v.erase(it3, it3 + 4);  // deletion using iterator

    it1 = v.begin();

    while (it1 != v.end())
    {
        cout << *it1 << endl;
        it1++;
    }
}
