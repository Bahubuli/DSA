#include <bits/stdc++.h>
using namespace std;


int main()
{

    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);


    // cout << arr.size() << endl;

    // cout << arr.capacity() << endl;

    vector<vector<int>> arr = {
        {1, 3, 5},
        {2, 5, 7},
        {3, 2, 1}};

        for(int i=0;i<arr.size();i++)
        {
            for(int numb:arr[i])
            {
                cout << numb<<" ";
            }
            cout << endl;
        }
}
