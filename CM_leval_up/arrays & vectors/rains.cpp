#include <bits/stdc++.h>
using namespace std;

//max water weight
int maxwaterweight(vector<int>arr)
{
    int l = arr[0];
    int li = 0;
    int ri = 0;
    int r = 0;
    int maxw = 0; int w = 0;
    for(int i=1;i<arr.size();i++)
    {
        ri = i;
        if(arr[i]>arr[i-1] && ri-li>=1)
        {

            r = arr[i];
            w = (ri - li-1) * (r < l ? r : l);
            int sum = 0;
            for(int j =li+1;j<ri;j++)
            {
                sum = sum + arr[j];
            }
            w = w - sum;
        }
        //cout << "li = " << li << " ri = " << ri << " l = " << l << " r = " << r << " w = " << w << endl;

        if(r>l)
        {
            l = r;
            li = ri;
        }

            if (w > maxw)
                maxw = w;
    }
    return maxw;
}

int trappedwater(vector<int>heights)
{
    int n = heights.size();
    if(n<=2)
        return 0;
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    int water = 0;
    for(int i=0;i<n;i++)
    {
        water += min(left[i], right[i]) - heights[i];
    }
    return water;
}


int main()
        {

            // freopen("i.txt", "r", stdin);
            // freopen("o.txt", "w", stdout);

            vector<int> arr{1,0,2,1,0,1,3,2,1,2,1};
            cout << trappedwater(arr);
}
