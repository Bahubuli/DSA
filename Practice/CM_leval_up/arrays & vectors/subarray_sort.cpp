#include <bits/stdc++.h>
using namespace std;

//basix nlogn solution
vector<int> subarraysort(vector<int>arr)
{
    vector<int> b(arr);
    sort(arr.begin(), arr.end());
    int i = 0;
    int n = arr.size();
    while(i<n and arr[i]==b[i])
    {
        i++;
    }
    int j = arr.size() - 1;
    while(j>=0 and arr[j]==b[j])
    {
        j--;
    }
    if(i==arr.size())
        return {-1,-1};


        return{i,j};
}
bool outoforder(vector<int>arr,int i)
{
    int x = arr[i];
    if(i==0)
    {
        return x > arr[i];
    }
    if(i==arr.size()-1)
        return x < arr[i - 1];
    return x > arr[i+1] or x < arr[i-1];
}

pair<int, int> subarrsort(vector<int> arr)
    {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            if (outoforder(arr, i))
            {
                smallest = min(smallest, x);
                largest = max(largest, x);
            }
        }
        if (smallest == INT_MAX)
            return {-1, -1};
        int left = 0;
        while (arr[left] <= smallest)
        {
            left++;
        }
        int right = arr.size() - 1;
        while (arr[right] >= largest)
        {
            right--;
        }
        return {left, right};
}
        int main()
        {
            int g;
            // freopen("i.txt", "r", stdin);
            // freopen("o.txt", "w", stdout);
            cin >> g;
            vector<int> arr{1,2,3,4,5,8,6,7,9,10,11};
            auto res=subarrsort(arr);
            cout << res.first << " " << res.second << endl;
}
