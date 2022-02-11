#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       stack<int> st;
       vector<int> ans;
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           ans.push_back(-1);
           else if(arr[st.top()]>arr[i])
           ans.push_back(st.top());
           else
           {
               while(!st.empty() && arr[st.top()]<=arr[i])
               st.pop();
               if(st.empty())
               ans.push_back(-1);
               else
               ans.push_back(st.top());

           }
           st.push(i);
       }

         for(int i=0;i<n;i++)
         ans[i]=i-ans[i];


       return ans;
    }
};


// 1 0 1 1 3 1 0

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);

		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
