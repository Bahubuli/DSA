#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    int numtoberotated = nums[0];
    int idx = 0;
    int count = 0;
    int n = nums.size();
    while (count <=n)
    {
        int nextnum = nums[(idx + k) % n];
        nums[(idx + k) % n] = numtoberotated;
        numtoberotated = nextnum;
        idx = (idx + k) % n;
        count++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int k;
    cin >>k;

    rotate(nums, k);

    for(auto x:nums)
        cout << x << " ";
    cout << endl;
}
