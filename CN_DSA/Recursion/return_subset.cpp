#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> arr,int i)
{
    if(i==0)
    {
        vector<vector<int>> vec;
        vector<int> a1 = {};
        vector<int> a2 = {1};
        vec.push_back(a1);
        vec.push_back(a2);

        return vec;
    }


    vector<vector<int>> res = subsets(arr, i - 1);

    vector<vector<int>> ans;
    vector<vector<int>> tempr = res;

    for (int j = 0; j < res.size(); j++)
    {
        ans.push_back(res[j]);
    }

    for (int j=0; j < tempr.size(); j++)
    {


        tempr[j].push_back(arr[i]);


        ans.push_back(tempr[j]);

    }

   

    return ans;
}



int main()
{

    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);


    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];


    vector<vector<int>> ans = subsets(arr, n - 1);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
