#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int i = 10;
    //initialize it because you can not change it after
    int j = 12;
    cout << j << endl;
    const int &k = j;
    //k++;//cause error
    j++;
    //reference path is constant

    cout << k << endl;
    cout << j << endl;
}