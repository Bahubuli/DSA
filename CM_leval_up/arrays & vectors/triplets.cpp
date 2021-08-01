#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetsum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int n = arr.size();
    //pick every a[i], and pair sum for remaining part
    for(int i=0;i<=n-3;i++)
    {
        int j = i + 1;
        int k = n - 1;

        while(j<k)
        {
            int currsum = arr[i];
            currsum  += arr[j];
            currsum += arr[k];
            if(currsum==targetsum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if(currsum>targetsum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}



int main()
    {

        // freopen("i.txt", "r", stdin);
        // freopen("o.txt", "w", stdout);

        vector<int> arr{1,2,3,4,5,6,7,8,9,15};
        int s = 18;
        auto result = triplets(arr, s);

        for(auto v:result)
        {
            for(auto no :v)
            {
                cout << no << ",";
            }
            cout << endl;
        }

}
