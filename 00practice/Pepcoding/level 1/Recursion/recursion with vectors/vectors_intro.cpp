#include <bits/stdc++.h>
using namespace std;

//to avoid creating new vector array each time pass with reference
//similar to normal arrays
void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main()
{
    vector<int> v1;

    //vector<string> s1 ;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    //printvec(v1);

    vector<int> v2(10, 1);

    v2.push_back(5);
    printvec(v2);

    vector<int> v3 = v2;
    // copied vector array similar to using for loop O(n) complexity
}