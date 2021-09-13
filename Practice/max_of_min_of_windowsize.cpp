// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        stack<int> st;
        int left[n], right[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);

        }

        stack<int> s;
        st = s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);

        }


        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
            cout << " left " << left[i] << " right " << right[i] << " len " << len << " anslen " << ans[len] << endl;
        }
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);

        return vector<int>(ans.begin() + 1, ans.end());
    }
};

// { Driver Code Starts.
int main()
{



        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        vector<int> res = ob.maxOfMin(a, n);
        for (int i : res)
            cout << i << " ";
        cout << endl;

    return 0;
}
// } Driver Code Ends
