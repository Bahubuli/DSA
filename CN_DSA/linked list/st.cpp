#include <bits/stdc++.h>
using namespace std;

int main() {

        long long int t;
        cin>>t;
        while(t--)
        {
            long long int n;
            cin>>n;


            vector<long long int> arr(n);
            if (n == 1)
            {
                cout << 0 << endl;
            }
            else
            {
                for (long long int i = 0; i < n; i++)
                    cin >> arr[i];

                sort(arr.begin(), arr.end());
                bool flag = 0;
                for (long long int i = 1; i < n; i++)
                {
                    if (arr[i] == arr[i - 1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << n - 1 << endl;
                }
            }
        }

	return 0;
}
