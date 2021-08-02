#include <bits/stdc++.h>
using namespace std;

int longestband(vector<int>arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for(int x:arr)
        s.insert(x);
    int largestband = 1;
    for(int element:s)
    {
        int parent = element - 1;
        if(s.find(parent)==s.end())
        {
            int nextel = element + 1;
            int count = 1;
            while(s.find(nextel)!=s.end())
            {
                count++;
                nextel++;
            }
            if(count>largestband)
                largestband = count;
        }
    }
    return largestband;
}

        int main()
        {

            // freopen("i.txt", "r", stdin);
            // freopen("o.txt", "w", stdout);

            vector<int> arr{1, 2, 3, 4, 5, 6, 7, 10, 9, 12, 0, 18};
            cout << longestband(arr);
}
