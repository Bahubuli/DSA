#include<bits/stdc++.h>
using namespace std;

void printsss(vector<int> arr,int idx,string set,int sos,int d)
{
    if(sos>d)
    return;

    if(idx==arr.size())
        {
            if(sos==d)
            {
                cout<<set+"."<<endl;

            }
             return;
        }
//add everything
printsss(arr,idx+1,set+to_string(arr[idx])+",",sos+arr[idx],d);

//add nothing
printsss(arr,idx+1,set,sos,d);

}

int main()
{

    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int d;
    cin>>d;

    printsss(arr,0,"",0,d);

}
