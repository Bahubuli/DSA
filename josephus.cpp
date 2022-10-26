

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int josephus(int n, int k){
    // code here
    list<int> l;
    for(int i=1;i<=n;i++)
    l.push_back(i);

    auto it = l.begin();
    while(l.size()>1)
    {
        int r=k;
        for(int i=0;i<r-1;i++)
        {
            it++;
            if(it==l.end())
            {
                it=l.begin();
            }

        }

        it=l.erase(it);
        if(it==l.end())
            it = l.begin();


    }
    return *it;


}

// { Driver Code Starts.

int main(){


        int n,k;
        cin>>n>>k;

        cout<<josephus(n,k)<<"\n";

    return 0;
}  // } Driver Code Ends
