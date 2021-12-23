#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int a = 0;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            a = a ^ arr[i];
        }
        if(a==0)
        {
            cout << a << endl;
            return 0;
        }

            long long int xr = 0;
            while (a--)
            {
                xr = 0;

                for (int i = 0; i < n; i++)
                {
                    xr = xr ^ (arr[i] + a);
                }
                if (xr == 0)
                {
                    break;
                }
        }
        if(xr==0)
            cout << a << endl;
        else
        {
            cout << -1 << endl;
        }

    }
}
