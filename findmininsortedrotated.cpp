#include<bits/stdc++.h>
using namespace std;

int findminidx(vector<int> arr)
{
    int n = arr.size();

    int l = 0, h = n - 1;
    int idx = 0;
    while (l < h)
    {

        int mid = (l + h) / 2;
        if (l < 0 || h >= n || mid < 0 || mid >= n)
            break;
        cout << "- l - h - mid --" << l << " " << h << " " << mid << " " << endl;
        if (arr[mid] < arr[mid - 1] && arr[mid] <= arr[mid + 1])
        {
            idx = mid;
            break;
        }
        else if (arr[mid] > arr[h])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return arr[idx];
}

int main()
{
    vector<int> arr = {11,13,15,17};
    cout << findminidx(arr) << endl;
}
