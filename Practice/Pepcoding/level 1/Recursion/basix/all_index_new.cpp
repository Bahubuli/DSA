#include <bits/stdc++.h>

using namespace std;
vector<int> allIndices(vector<int> arr, int idx, int x, int fsf)

{

    // write your code here
    if (idx == arr.size())
    {
        vector<int> array(fsf);
        return array;
    }

    vector<int>iarr;
    if (arr[idx] == x)
    {
        iarr= allIndices(arr,idx+1,x,fsf+1);
        iarr[fsf]=idx;

    }
    else
    {
         iarr = allIndices(arr,idx+1,x,fsf);
    }


        return iarr;
}
int main()
{
    int n, x;
    cin >> n;
    vector<int> arr={};
     for(int i = 0; i < n; i++)
        {
            cin>>x;
            arr.push_back(x);
        }
        cin>>x;


    vector<int> p = allIndices(arr, 0, x, 0);

    if(p.size()>0)
    for(int a:p)
    cout<<a<<endl;

}
