// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> nsl(int arr[],int n)
    {
        vector<int> ans;
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(st.empty())
            ans.push_back(-1);
            else if(arr[st.top()]<arr[i])
            ans.push_back(st.top());
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
                if(st.empty())
                ans.push_back(-1);
                else
                ans.push_back(st.top());
            }
            st.push(i)
        }
        return ans;

    }
    vector<int> nsr(int arr[],int n)
    {
         vector<int> ans;
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            ans.push_back(n);
            else if(arr[st.top()]<arr[i])
            ans.push_back(st.top());
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
                if(st.empty())
                ans.push_back(n);
                else
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    int maxareahisto(int arr[],int n)
    {
        vector<int> l=nsl(arr,n);
        vector<int> r=nsr(arr,n);
        vector<int> wid;
        for(int i=0;i<l.size();i++)
        {
            wid.push_back(r[i]-l[i]-1);
        }
         for(int i=0;i<l.size();i++)
        {
            wid[i]=wid[i]*arr[i];
        }
        return *max_element(wid.begin(),wid.end());

    }

};



int main()
{

		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;

        int s3 = obj.maxareahisto(a, n);
        cout<<s3<<endl;


	return 0;
}
  // } Driver Code Ends
