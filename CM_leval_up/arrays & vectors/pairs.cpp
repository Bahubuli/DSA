#include <bits/stdc++.h>
using namespace std;

vector<int> pairsum(vector<int> arr, int S)
{
    unordered_set<int> s;
    vector<int> result;

    for(int i=0;i<arr.size();i++)
    {
        int x = S - arr[i];
        if(s.find(x)!=s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
}

int main()
    {

        freopen("i.txt", "r", stdin);
        freopen("o.txt", "w", stdout);

        vector<int> arr{10, 5, 2, 3, -6, 9, 11};
        int s = 4;
        auto p = pairsum(arr, s);

        if(p.size()==0)
            cout << "No such pair" << endl;
        else
        {
            cout << p[0] << " " << p[1] << endl;
        }

}
