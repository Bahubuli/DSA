#include<bits/stdc++.h>
using namespace std;

void printsss(vector<int> arr,int idx,string set,int sos,int d)
{

    if(idx==arr.size())
        return;
    sos=sos+arr[idx];
    set=set+to_string(arr[idx])+", ";

    //cout<<"idx = "<<idx<<endl;
    if(sos==d)
    {
        //cout<<"idx is = "<<idx<<endl;
        cout<<set+"."<<endl;
        return;

    }
    //cout<<"idx = "<<idx<<endl;

    for(int i=idx+1;i<arr.size();i++)
    {

        if(sos<d)
    printsss(arr,i,set,sos,d);

    }

    if(arr[idx+1]<d)
    printsss(arr,idx+1,"",0,d);
    //cout<<"why not this"<<endl;




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
