// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    if(k==1)
    {
        for(int i=0;i<n;i++)
            ans.push_back(arr[i]);
        return ans;
    }


    // your code here
    deque<int> dq;

    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.front()]<arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);

    for(int i=k;i<n;i++)
    {
        if(dq.size()==k)
        {
            cout <<i<<"   "<< arr[dq.front()] << endl;
            dq.pop_front();

        }

        while(!dq.empty() && arr[i]>arr[dq.front()])
        {
            //cout << dq.front() << endl;
            dq.pop_front();
        }
        dq.push_back(i);
        //cout << arr[dq.front()] << endl;
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}

// { Driver Code Starts.

int main()
{



        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res = max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;


    return 0;
} // } Driver Code Ends
