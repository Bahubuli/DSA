#include<bits/stdc++.h>
using namespace std;


int main()
{

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        int n;
        cin >> n;

        vector<int> arr(n + 1);
        arr[0] = 1;
        arr[1] = 2;

        for(int i=2;i<=n;i++)
        {
          arr[i] = arr[i - 1] + arr[i - 2];
        }
        cout << arr[n];
}
