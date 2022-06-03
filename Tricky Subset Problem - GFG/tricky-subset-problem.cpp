// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
         vector<long long>pre;
        pre.push_back(S);
        long long sum = S;
        for(int i = 1 ; i <= N && sum <= X; i++){
            pre.push_back(sum + A[i - 1]);
            sum += pre[i];
        }
        int len = pre.size();
        for(int i = len - 1 ; i >= 0 ;i--){
            if(pre[i] <= X)
            X -= pre[i];
        }
        return X == 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends