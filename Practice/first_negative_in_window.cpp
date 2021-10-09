#include<bits/stdc++.h>
using namespace std;

//first negative number in every window size
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};

    int n = 8;
    int k = 3;
    int i = 0;
    queue<int> q;
    for(i=0;i<k-1;i++)
    {
        if(arr[i]<0)
            q.push(arr[i]);
    }

    vector<int> ans;
    while(i<n)
    {
        if(arr[i]<0)
            q.push(arr[i]);
        if(!q.empty())
        {
            ans.push_back(q.front());

            if(q.front()==arr[i-k-1])
                q.pop();
        }
        else
        {
            q.push(0);
        }

        }


}
